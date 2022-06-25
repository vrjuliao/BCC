import requests
import sys

text = ' '.join(sys.argv[3:])
host = sys.argv[1]
port = sys.argv[2]

url = host+':'+port+'/api/american'
 
headers = {'Content-Type': 'application/json; charset=utf-8'}
 
data = {'text': text}
response = requests.post(url, headers=headers, json=data) 
# print("Status Code", response.status_code)
print("Response ", response.json())
