# Part 3

Vinicius Julião Ramos - 2018054630

The compatibility of the runtime developed by this work was done by observing the scope of the `deployment.yaml` file provided with the assignment description.
So, all the environment variables and directories used by `lucasmsp/serverless:redis` are exactly the same in my implementation.
In summary the my runtime runs the the application from the `/opt` directory, since the python module containing the handler is given by the volume that maps the python file to the module `/opt/usermodule.py`. Also, the same environment variables were used with the same goal:

* `REDIS_HOST`
* `REDIS_PORT`
* `REDIS_INPUT_KEY`
* `REDIS_OUTPUT_KEY`


Regarding to the functionality of my runtime, it runs in a infinity loop that runs the following steps:
1. Read the metrics stored on Redis
2. Mount the `context` object as it is expected.
3. Call the serverless function passing the mounted `context` and the metrics read from Redis.
4. Stores the output of the serverless function on Redis.
5. Stores in the `context` the last execution timestamp.
  