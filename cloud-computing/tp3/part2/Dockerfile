FROM python:3.10-slim
EXPOSE 5126
RUN mkdir /app
WORKDIR /app
COPY . /app

RUN pip3 install -r requirements.txt

CMD [ "python3", "dashboard.py" ]
