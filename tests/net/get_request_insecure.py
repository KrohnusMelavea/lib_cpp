import urllib.request
import json

response = urllib.request.urlopen(urllib.request.Request("http://localhost:81/thisismyrequest ", data=json.dumps({"data1": 15}).encode(), headers={"Content-Type": "application/json"}, method="GET"))
print(response.read())
