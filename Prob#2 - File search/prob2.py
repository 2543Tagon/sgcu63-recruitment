import json

def fileSearch(fileToSearch, filesObj):
   jsonfile = open(filesObj, 'r', encoding ="utf-8")
   data = json.load(jsonfile)
   Ans="[\n"+dfs(data,"","",fileToSearch)+"]"
   return Ans


def dfs(now,lastS,string,search):
    Ans=""
    for to in now:
        if(to[0]=="_"):
            for j in now[to]:
                if j==search:
                    Ans+="   \""+string+"/"+j+"\",\n"
        else:
            Ans+=dfs(now[to],to,string+"/"+to,search)
    return Ans

print(fileSearch('file1','test.json'))
