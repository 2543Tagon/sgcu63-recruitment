from bs4 import BeautifulSoup
import requests
import dominate
from dominate.tags import *

#this code will take a minute please wait

ans=[]

url = requests.get("https://rubnongkaomai.com/baan")
soup = BeautifulSoup(url.content, "html.parser")
containers = soup.find_all("div",{"class","ant-col ant-col-8"})
container = containers[0]

print("please wait")

for container in containers:
    url2 = requests.get("https://rubnongkaomai.com"+container.a["href"])
    nSoup = BeautifulSoup(url2.content, "html.parser")
    data = nSoup.find("div",{"class","baan-info-module--text-wrapper--uuYTz"})
    ans.append([data.div.h1.text,data.div.h3.text])

for i in ans:
    print(i[0]+"\t\t"+i[1])


table_headers = ['ชื่อบ้าน','สะโลเเกน']
def create_page():
    doc = dominate.document(title="บ้าน")

    with doc.head:
        link(rel='stylesheet',href='style.css')

    with doc:
        with div(cls='container'):
            with table(id ='main', cls='table table-striped'):
                with thead():
                    with tr():
                        for table_head in table_headers:
                            th(table_head)
                with tbody():
                    for i in ans:
                        with tr():
                            td(i[0])
                            td(i[1])
    with open('table.html','wb') as file:
        print(doc.render().encode('utf-8'))
        file.write(doc.render().encode('utf-8'))
                
create_page()
