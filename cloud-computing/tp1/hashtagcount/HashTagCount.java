package hashtagcount;
import java.io.IOException;
import java.io.DataInput;
import java.io.DataOutput;
import java.util.Collection;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.HashSet;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Writable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.json.JSONObject;

public class HashTagCount {
    static public class HashTagWritable implements Writable {
        private IntWritable counter;
        private String tag;
        private HashSet<String> correlated;
        
        public HashTagWritable(){
            reset();
        }

        public void reset(){
            counter = new IntWritable(0);
            tag = "";
            correlated = new HashSet<String>();
        }

        @Override
        public void write(DataOutput dataOutput) throws IOException {
            (new Text(tag)).write(dataOutput);
            // Text aux = new Text(tag);
            // aux.write(dataOutput);
            counter.write(dataOutput);
            dataOutput.writeInt(correlated.size());  //write size of list
            for(String ele: correlated){
                (new Text(ele)).write(dataOutput);
                // aux.set(ele);
                // aux.write(dataOutput);
                // dataOutput.writeChars(ele);
            }
        }

        @Override
        public void readFields(DataInput dataInput) throws IOException {
            Text aux = new Text();
            aux.readFields(dataInput);
            tag = aux.toString();
            counter.readFields(dataInput);
            int size = dataInput.readInt();
            correlated.clear();
            for(int i=0; i<size; i++) {
                Text aux2 = new Text();
                aux2.readFields(dataInput);
                correlated.add(aux2.toString());
            }
        }

        public void setTag(String tag) {
            this.tag = tag;
        }

        public String getTag () {
            return tag;
        }
        public void setCounter(int newCounter){
            counter.set(newCounter);
        }

        public int getCounter(){
            return counter.get();
        }

        public void addCorrelated(HashSet<String> elements){
            for(String element: elements){
                if(element != tag){
                    correlated.add(element);
                }
            }
        }

        public void setCorrelated(HashSet<String> elements){
            correlated = elements;
            if(correlated.contains(tag)){
                correlated.remove(tag);
            }
        }

        public HashSet<String> getCorrelated(){
            return correlated;
        }

        @Override
        public String toString() {
            
            return ""+counter.get()+","+correlated.toString()
                    .replace("[","\"")
                    .replace("]","\"")
                    .replace(" ", "");
        }
    }

    public static class HashTagMapper
            extends Mapper<Object, Text, Text, HashTagWritable> {
        private static final Pattern HASHTAG_REGEX = Pattern.compile("#\\w+");
        
        @Override
        public void map(Object key, Text value, Context context)
                throws IOException, InterruptedException {

            JSONObject jo = new JSONObject(value.toString());
            String text = jo.getString("text");
            Matcher matcher = HASHTAG_REGEX.matcher(text);
            HashSet<String> tags = new HashSet<String>();
            while (matcher.find()) {
                int start = matcher.start()+1;
                String tag = text.substring(start, matcher.end()).toLowerCase();
                tags.add(tag);
            }
            for(String tag: tags){
                HashTagWritable hashTagWr = new HashTagWritable();
                hashTagWr.setTag(tag);
                hashTagWr.setCorrelated(new HashSet<String>(tags));
                hashTagWr.setCounter(1);
                context.write(new Text(tag), hashTagWr);
            }
        }
    }

    public static class HashTagReducer
            extends Reducer<Text, HashTagWritable, Text, HashTagWritable> {

        @Override
        public void reduce(Text key, Iterable<HashTagWritable> values, Context ctx)
                throws IOException, InterruptedException {
            HashTagWritable result = new HashTagWritable();
            int sum = 0;
            for (HashTagWritable val : values) {
                sum += val.getCounter();
                result.addCorrelated(val.getCorrelated());
            }
            if(sum < 1000) return;
            result.setCounter(sum);
            ctx.write(key, result);
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        conf.set("mapred.textoutputformat.separator", ",");

        Job job = Job.getInstance(conf, "My Job");
        job.setJarByClass(HashTagCount.class);
        job.setMapperClass(HashTagMapper.class);
        job.setReducerClass(HashTagReducer.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(HashTagWritable.class);
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
