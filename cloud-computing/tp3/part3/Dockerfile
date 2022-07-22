FROM python:3.10-alpine
WORKDIR /opt
COPY . /opt

RUN pip3 install -r requirements.txt

CMD [ "python3", "serverless.py" ]
