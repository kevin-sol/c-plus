#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

typedef struct Node
{
    int father;
    map<string, int> child;
    int type;//目录//文件
    long long lr, ld;
    long long lr_r, ld_r;
    long long size;//文件大小
} Node;

vector<pair<int, string>> reback;
Node node[4000010];
int num = 0;
void Reback()
{
    for (int i = 0; i < reback.size();i++){
        int id = reback[i].first;
        string name = reback[i].second;
        node[id].child.erase(node[id].child.find(name));
    }
}


string commandC()
{
    string path;
    long long filesize;
    cin >> path >> filesize;
    int last = -1;
    for (int i = path.length() - 1; i >= 0;i--){
        if(path[i]=='/'){
            last = i;
            break;
        }
    }
    int current = 1;
    int id = 0;
    reback.clear();
    int oldnum = num;
    while(current<last)
    {
        string t = "";
        while(current<last&&path[current]!='/')
        {
            t+=path[current];
            current++;
        }
        current++;
        if(node[id].child.find(t)==node[id].child.end()){
            num++;
            node[id].child[t] = num;
            node[num].father = id;
            node[num].type = 2;
            node[num].ld = LLONG_MAX / 3;
            node[num].lr = LLONG_MAX / 3;
            reback.push_back(make_pair(id, t));
            id = num;
        }
        else{
            int childid = node[id].child[t];
            if(node[childid].type==1)
            {
                num = oldnum;
                Reback();
                return "N";
            }
            id = childid;
        }
    }
    string t = "";
    for(int i=last+1;i<path.length();i++)
    {
        t+=path[i];
    }
    if(node[id].child.find(t)!=node[id].child.end())
    {
        int childid = node[id].child[t];
        if(node[childid].type==2)
        {
            num = oldnum;
            Reback();
            return "N";
        }
    }
    //是否满足配额
    long long changesize = 0;
    if(node[id].child.find(t)==node[id].child.end())
        changesize = filesize;
    else{
        int fileid = node[id].child[t];
        changesize = node[fileid].size + filesize;
    }
    if(node[id].ld_r+changesize>node[id].ld){
        num = oldnum;
        Reback();
        return "N";
    }
    int now = id;
    while(now!=-1){
        if(node[now].lr_r+changesize>node[now].lr){
            num = oldnum;
            Reback();
            return "N";
        }
        now = node[now].father;
    }
    if(node[id].child.find(t)==node[id].child.end())
    {
        num++;
        node[num].type = 1;
        node[num].father = id;
        node[num].size = filesize;
        node[id].child[t] = num;
    }
    else{
        node[node[id].child[t]].size=filesize;
    }
    node[id].ld_r = node[id].ld_r + changesize;
    now = id;
    while(now!=1){
        node[now].lr_r = node[now].lr_r + changesize;
        now = node[now].father;
    }
    return "Y";
}

string commandQ(){
    string filepath;
    long long LD, LR;
    cin >> filepath >> LD >> LR;
    int last = -1;
    int id = 0;
    for(int i=filepath.length()-1;i>=0;i--)
    {
        if(filepath[i]=='/')
        {
            last=i;
            break;
        }
    }
    int current = 1;
    if(LD==0)
        LD = LLONG_MAX / 3;
    if(LR==0)
        LR = LLONG_MAX / 3;
    while(current<last){
        string t="";
        while(current<last&&filepath[current]!='/')
        {
            t+=filepath[current];
            current++;
        }
        current++;
        if(node[id].child.find(t)==node[id].child.end())//目录不存在
        {
            return "N";
        }
        else{
            id = node[id].child[t];
            if(node[id].type == 1) return "N";
        }
    }
    string t="";
    for(int i=last+1;i<filepath.length();i++)
    {
        t+=filepath[i];
    }
    if(t=="")
        id = 0;
    else{
        if(node[id].child.find(t)==node[id].child.end()) return "N";
        else{
            id = node[id].child[t];
        }
    }
    if(node[id].type==1) return "N";
    if(node[id].ld_r>LD||node[id].lr_r>LR) return "N";
    else{
        node[id].ld = LD;
        node[id].lr = LR;
        return "Y";
    }
}

string commandR()
{
    string filepath;
    cin>>filepath;
    int last=-1;
    int current=1;
    int id=0;
    for(int i=filepath.length()-1;i>=0;i--)
    {
        if(filepath[i]=='/')
        {
            last=i;
            break;
        }
    }
    while(current<last){
        string t="";
        while(current<last&&filepath[current]!='/')
        {
            t+=filepath[current];
            current++;
        }
        current++;
        if(node[id].child.find(t)==node[id].child.end())
            return "Y";
        else{
            id = node[id].child[t];
        }
        if(node[id].type==1)
            return "Y";
    }
    string t="";
    for(int i=last+1;i<filepath.length();i++)
        t+=filepath[i];
    if(node[id].child.find(t)==node[id].child.end()) return "Y";
    int delnode = node[id].child[t];
    long long delsize;
    if(node[delnode].type==1){
        delsize = node[delnode].size;
        node[id].ld_r -= delsize;
        node[id].child.erase(node[id].child.find(t));
    }
    else if(node[delnode].type==2)
    {
        delsize=node[delnode].lr_r;
        node[id].child.erase(node[id].child.find(t));
    }
    int now = id;
    while(now!=-1){
        node[now].lr_r -= delsize;
        now = node[now].father;
    }
    return "Y";
}

int main()
{
    int n;
    cin >> n;
    char ch;
    for(int i=0;i<n;i++)
    {
        cin >> ch;
        switch(ch){
            case 'C':
                cout << commandC() << endl;
                break;
            case 'Q':
                cout << commandQ() << endl;
                break;
            case 'R':
                cout << commandR() << endl;
                break;
        }
    }
}
