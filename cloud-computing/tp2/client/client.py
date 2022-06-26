import requests
import sys

# usage: 
# python3 client.py <host> <port> <message>
# python3 client.py http://127.0.0.1 5026 the book is on the table

text = ' '.join(sys.argv[3:])
host = sys.argv[1]
port = sys.argv[2]

url = host+':'+port+'/api/american'
headers = {'Content-Type': 'application/json; charset=utf-8'}
 
data = {'text': text}
response = requests.post(url, headers=headers, json=data) 
# print("Status Code", response.status_code)
print("Response ", response.json())
