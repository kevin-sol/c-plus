#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;

const int maxn=505;
const int maxs=10005;
const int maxm=2505;

int Q;
int M,N;

struct Node{
    int func;
    vector<int> in;
    vector<int> out;
};
Node eq[maxn];
int inq[maxn];
vector<int> G[maxn];
int ans[maxn];

int S;
int Input[maxs][maxm];



int Operate(vector<int>& input,int opt)
{
    if(opt==0){
        return !input[0];
    }
    int r=input[0];
    int size=input.size();
    if(opt==1){
		for(int i=1;i<size;i++){
			r&=input[i];
		}
		return r;
	}else if(opt==2){
		for(int i=1;i<size;i++){
			r|=input[i];
		}
		return r;
	}else if(opt==3){
		for(int i=1;i<size;i++){
			r^=input[i];
		}
		return r;
	}else if(opt==4){
		for(int i=1;i<size;i++){
			r&=input[i];
		}
		return !r;
	}else if(opt==5){
		for(int i=1;i<size;i++){
			r|=input[i];
		}
		return !r;
	}
}

int dfs(int s,itn v)
{
    if(ans[v]!=-1){
        return ans[v];
    }
    vector<int> allinput;
    int size=eq[v].in.size();
    for (int i = 0; i < size; i++)
    {
        allinput.push_back(Input[s][eq[v].in[i]]);
    }
    size=eq[v].out.size();
    for (int i = 0; i < size; i++)
    {
        allinput.push_back(dfs(s,eq[v].out[i]));
    }
    return ans[v]=Operate(allinput,eq[v].func);
}

bool topol()
{
    queue<int> q;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        ++count;
        for (int i = 0; i < G[u].size(); i++)
        {
            int v=G[u][i];
            intq[v]--;
            if(!inq[v]){
                q.push(v);
            }
        }
        
    }
    return cout==N;
}

void clear()
{
    for (int i = 1; i <= N; ++i)
    {
        G[i].clear();
        inq[i]=0;
        eq[i].in.clear();
        eq[i].out.clear();
    }
}

int main(int argc, char const *argv[])
{
    map<string,int> m;
	m["NOT"]=0;m["AND"]=1;m["OR"]=2;m["XOR"]=3;m["NAND"]=4;m["NOR"]=5;
	cin>>Q;
    string func;
    int k;
    string des;
    for (int z = 0; z < Q; z++)
    {
        cin>>M>>N;
        clear();
        for (int i = 1; i <= N; i++)
        {
            cin>>func;
            eq[i].func=m[func];
            cin>>k;
            for (int j = 0; j < k; j++)
            {
                cin>>des;
                if(des[0]=='I'){
                    int a=stoi(des.substr(1));
                    eq[i].in.push_back(b);
                }else{
                    int b=stoi(des.substr(1));
                    eq[i].out.push_back(b);
                    inq[i]++;
                    G[b].push_back(i);
                }
            }
            
        }
        cin>>S;
        for(int i=0;i<S;i++){
			for(int j=1;j<=M;j++){
				cin>>Input[i][j];
			}
		}
        bool flag=topol();
        if(flag==false){
            printf("LOOP\n");
        }
        for (int i = 0; i < S; i++)
        {
            fill(ans,ans+maxn,-1)
            int si,id;
            cin>>si;
            for (int j = 0; j < si; j++)
            {
                cin>>id;
                if(flag==true){
                    itn res=dfs(i,id);
                    if(j==si-1){
                        printf("%d\n",res);
                    }else
                    {
                        printf("%d",res);
                    }
                    
                }
            }
            
        }
    }
    return 0;
}
