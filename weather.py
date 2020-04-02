#-*- coding:utf-8 -*-
import sys
import requests
import time
import xml.etree.ElementTree as ETree

reload(sys)
sys.setdefaultencoding('utf-8')

rssURL = 'http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4136025000'
graphURL = 'http://ec2-3-19-61-182.us-east-2.compute.amazonaws.com:8001/insert/?temp='

while True:
    res = requests.get(rssURL)
    root = ETree.fromstring(res.text)
    first_data = root.find('channel').find('item').find('description').find('body').find('data')
    temp = first_data.find('temp').text

    req = requests.get(graphURL + str(temp))
    time.sleep(600)
