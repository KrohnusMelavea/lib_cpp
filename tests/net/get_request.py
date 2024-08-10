##import requests
##
##session = requests.Session()
##request = requests.Request("GET", "http://localhost:81/unique_uri?var0=fdsa&var1=asdf")
##ready_request = request.prepare()
###del ready_request.headers["Accept-Encoding"]
##ready_request.headers["Connection-Type"] = "Close"
##print(ready_request.headers)
##response = session.send(ready_request)
##print("fdsa")


import urllib3

response = urllib3.request("GET", "http://localhost:81/unique_uri?var0=fdsa&var1=asdf")
print(response.data)
