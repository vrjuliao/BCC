import redis
import json

import numpy as np

import dash_bootstrap_components as dbc

from dash import Dash, html, dcc

import plotly.express as px
import plotly.io as pio
import plotly.graph_objects as graph

from plotly.subplots import make_subplots

from dash.dependencies import Input, Output

app = Dash(external_stylesheets=[dbc.themes.DARKLY])
pio.templates.default = 'plotly_dark'
redis_client = redis.Redis(host='192.168.121.189', port=6379)

app.minute = []
app.hour = [] 
app.vmem = []

def get_redis_data():
    app.cpu_data = json.loads(redis_client.get('viniciusramos-proj3-output'))

get_redis_data()

app.layout = html.Div([
    html.Div([
        html.H5(children='Moving Average of CPUs Utilization (60 minutes)', style={'fontSize':'40px'}),
        dcc.Graph(id='cpu-hour'),
        dcc.Interval(id='interval0', interval=3*1000, n_intervals=0)
    ]),
    html.Div([
        html.H4(children='Moving Average of CPUs Utilization (60 seconds)', style={'fontSize':'40px'}),
        dcc.Graph(id='cpu-minute'),
        dcc.Interval(id='interval1', interval=3*1000, n_intervals=0)
    ]),
    html.Div([
        html.H4(children='Moving Average of Memory Utilization (60 seconds)', style={'fontSize':'40px'}),
        dcc.Graph(id='virtual-memory'),
        dcc.Interval(id='interval2', interval=3*1000, n_intervals=0)
    ])
])



@app.callback(Output('cpu-hour', 'figure'), Input('interval0', 'n_intervals'))
def build_cpu_hour_dashboard(n):
    get_redis_data()
    
    hours = []
    cpus = 0

    initial_text = 'avg-util-cpu'
    end_text = '60min'
    for (key, value) in app.cpu_data.items():
        if key.startswith(initial_text) and key.endswith(end_text):
            hours.append(value)
    app.hour.append(hours)

    if len(app.minute) > 300:
        app.hour = app.hour[-300:]
    
    figs = make_subplots(
        rows = 1,
        cols = 1,
        subplot_titles = (
            "CPU Utilization(60 minutes)"
        )
    )
    
    cpus = len(hours)
    for i in range(cpus):
        figs.add_trace(graph.Scatter(x=np.arange(len(app.hour)*cpus), y=np.array(app.hour)[:,i], name="cpu%d"%i, mode="lines"), row=1, col=1)
    
    
    figs.update_xaxes(title_text = 'Time')
    figs.update_yaxes(title_text = 'Utilization (%)')
    
    figs.update_layout(
        height = 600,
        yaxis_range=[-5, 105]
    )
    
    return figs

@app.callback(Output('cpu-minute', 'figure'), Input('interval1', 'n_intervals'))
def build_cpu_hour_dashboard(n):
    get_redis_data()
    
    minutes = []
    cpus = 0

    initial_text = 'avg-util-cpu'
    end_text = '60sec'
    for (key, value) in app.cpu_data.items():
        if key.startswith(initial_text) and key.endswith(end_text):
            minutes.append(value)
    app.minute.append(minutes)

    if len(app.minute) > 300:
        app.minute = app.minute[-300:]
    
    figs = make_subplots(
        rows = 1,
        cols = 1,
        subplot_titles = (
            "CPU Utilization(60 seconds)",
        )
    )
    
    cpus = len(minutes)
    for i in range(cpus):
        figs.add_trace(graph.Scatter(x=np.arange(len(app.minute)*cpus), y=np.array(app.hour)[:,i], name="cpu%d"%i, mode="lines"), row=1, col=1)
    
    
    figs.update_xaxes(title_text = 'Time')
    figs.update_yaxes(title_text = 'Utilization (%)')
    
    figs.update_layout(
        height = 600,
        yaxis_range=[-5, 105]
    )
    
    return figs


@app.callback(Output('virtual-memory', 'figure'), Input('interval2', 'n_intervals'))
def build_vmem_dashboard(n):
    get_redis_data()
    app.vmem.append(app.cpu_data['avg-virtual-memory-usage-60sec'])

    if len(app.vmem) > 300:
        app.vmem = app.vmem[-300:]
    
    figs = make_subplots(
        rows = 1,
        cols = 1
    )
    figs.add_trace(graph.Scatter(x=np.arange(len(app.vmem)), y=np.array(app.vmem), name="virtual memory", mode="lines"), row=1, col=1)

    figs.update_xaxes(title_text = 'Time (s)')
    figs.update_yaxes(title_text = 'Utilization (Megabytes)')

    figs.update_layout(
        height = 600,
        yaxis_range=[-5, 105]
    )

    return figs


if __name__ == '__main__':
    app.run_server(debug=True, port=5126, host='0.0.0.0')
