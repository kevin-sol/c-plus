#include<bits/stdc++.h>
using namespace std;
struct pro{
	int type,id; //操作类型及目标进程号 
};

int main(){
	int T,n,next,countfail,countempty; //countfail:当前无法满足的进程数量 countempty：当前空进程数量 
	scanf("%d%d",&T,&n);
	getchar();//消除回车 
	string str;//每一行的输入 
	bool jud2 = true; 
	while(T--){
		queue<pro> mypro[n];//队列没有clear操作，所以每次重新声明一个，双向队列dequeue可以clear 
		jud2 = true;
		for(int i=0; i<n; i++){
			getline(cin,str);//读取行输入 
			for(int j=0; j<str.length(); j++){
				pro tool;//声明一个进程 
				tool.type = str[j]=='S'?1:0;//判断进程类型，send为1，receive为0 
				int t = 0;//目标进程号 
				j++;
				while(str[j]!=' '&&j<str.length()){//计算目标进程号 
					t = t*10+(str[j++]-'0'); 
				} 
				tool.id = t;
				mypro[i].push(tool);//进程入队 
			}
		}
		while(jud2){
			countfail = 0; //countfail:当前无法满足的进程数量 countempty：当前空进程数量 
			countempty = 0; //每次循环重置 
			for(int i=0; i<n; i++){
				if(!mypro[i].empty()){
					next = mypro[i].front().id;//目标进程号 
					if(mypro[next].empty()){//目标进程为空，死锁退出 
						printf("1\n");
						jud2 = false;
						break;
					}
					//目标进程可以满足，两进程都出队 
					else if(mypro[next].front().id==i&&mypro[next].front().type!=mypro[i].front().type){
						mypro[i].pop();
						mypro[next].pop();
					}
					else{
						countfail++;//无法满足数量加一 
					}
				}
				else countempty++;//空队数量加一 
			}
			if(countempty==n){ //全空，不死锁，退出 
				printf("0\n");
				break;
			}
			else if(countfail+countempty==n){ //除了空全无法满足，死锁，退出 
				printf("1\n");
				break;
			}
		}
	}
	return 0;
} 
