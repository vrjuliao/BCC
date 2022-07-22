from datetime import datetime, timedelta

def aggregate(aggregation, data, key_template):
    for (key, value) in data.items():
        cpu_id = key.split('-')[1]
        new_key = key_template.format(id=cpu_id)
        if new_key in aggregation:
            aggregation[new_key] += value
        else:
            aggregation[new_key] = value
    
def compute_answer(agggrgator, data, count):
    for (key, agg) in data.items():
        agggrgator[key] = agg/count


def handler(input: dict, context: object):
    metric_str = 'cpu_percent'
    cpu_percent = dict(filter(lambda item: item[0].startswith(metric_str),
                                           input.items()))
    current_datetime_str = input['timestamp']
    current_datetime = datetime.fromisoformat(current_datetime_str)
    
    mem_usage_timestamps = {}
    if 'mem_usage' in context.env:
        mem_usage_timestamps = context.env['mem_usage']
    else:
        context.env['mem_usage'] = {}

    minute_delta = timedelta(seconds=60)
    hour_delta = timedelta(seconds=3600)

    mem_usage_agg = input['virtual_memory-percent']
    mem_usage_count = 1
    to_erase = []
    for (tmstp, mem_usage) in mem_usage_timestamps.items():
        prev_datetime = datetime.fromisoformat(tmstp)
        if prev_datetime + minute_delta >= current_datetime:
            mem_usage_agg += mem_usage
            mem_usage_count += 1
        else: to_erase.append(tmstp)

    for tmstp in to_erase: del context.env['mem_usage'][tmstp]
    context.env['mem_usage'][current_datetime_str] = input['virtual_memory-percent']
    
    
    minute_agg = {}
    aggregate(minute_agg, cpu_percent, 'avg-util-cpu{id}-60sec')
    minute_count = 1
    hour_agg = {}
    aggregate(hour_agg, cpu_percent, 'avg-util-cpu{id}-60min')
    hour_count = 1

    cpu_usage_timestamps = {}
    if 'cpu_usage' in context.env:
        cpu_usage_timestamps = context.env['cpu_usage']
    else:
        context.env['cpu_usage'] = {}

    to_erase = []
    for (tmstp, cpu_usage) in cpu_usage_timestamps.items():
        prev_datetime = datetime.fromisoformat(tmstp)
        if prev_datetime + minute_delta >= current_datetime:
            minute_count +=  1
            hour_count +=  1
            aggregate(minute_agg, cpu_usage, 'avg-util-cpu{id}-60sec')
            aggregate(hour_agg, cpu_usage, 'avg-util-cpu{id}-60min')
        elif prev_datetime + hour_delta >= current_datetime:
            hour_count +=  1
            aggregate(hour_agg, cpu_usage, 'avg-util-cpu{id}-60min')
        else:
            to_erase.append(tmstp)
    
    for time_greater in to_erase:
        del context.env['cpu_usage'][time_greater]

    context.env['cpu_usage'][current_datetime_str] = cpu_percent

    answer = {}
    compute_answer(answer, minute_agg, minute_count)
    compute_answer(answer, hour_agg, hour_count)
    compute_answer(answer, {'avg-virtual-memory-usage-60sec': mem_usage_agg}, mem_usage_count)
    answer['timestamp'] = current_datetime_str
    return answer
