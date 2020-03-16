import requests
import random
import time

url = 'https://api.thingspeak.com/update?api_key=FAH0KOYNUF0MH6LM&field1='

for i in range(10):
    value = random.random()
    r = requests.get(url+str(value))
    r.encoding = 'utf8'
    print(r.text)
    time.sleep(16)

