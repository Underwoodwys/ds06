#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct{
	char vexs[MAX];
	int arcs[MAX][MAX]={0};
	int vexnum,arcnum;
}MGraph;
typedef struct QNODE{
	int x;
	struct QNODE *next;
}QNODE,*QPTR;
typedef struct SNODE{
	int x;
	struct SNODE *next;
}SNODE,*LINKSTACK;
void PUSH(LINKSTACK &S,int x){
	LINKSTACK a;
	a=(LINKSTACK)malloc(sizeof(SNODE));
	a->x=x;
	a->next=S;
	S=a;
}
void POP(LINKSTACK &S){
	if(!S);
	else{
		S=S->next;
	}
}
void INPUT(QPTR &Q,int x){
	QPTR a;
	a=(QPTR)malloc(sizeof(QNODE));
	if(!Q){a->x=x;Q=a;Q->next=Q;}
	else{a->x=x;a->next=Q->next;Q->next=a;Q=a;}
}
void DELETE(QPTR &Q,int v){
	if(!Q);
	else{v=Q->x;if(Q->next=Q)Q=NULL;
		else{Q->next=Q->next->next;}}
}
void INIT(MGraph &G){
	int a,b;
	printf("请输入顶点个数及边的个数\n");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	printf("请输入顶点信息\n");
	for(int i=0;i<=G.vexnum+1;++i)//从下标为1开始存放字符，两端皆为缓冲换行
		G.vexs[i]=getchar();
	printf("请输入边的信息\n");//从0开始存放边的信息
	for(int j=0;j<G.arcnum;++j){
		scanf("%d%d",&a,&b);
		G.arcs[a][b]=1;
		G.arcs[b][a]=1;
	}
}
int vi[MAX]={0};
int vis[MAX]={0};
int vist[MAX]={0};
void shendu(MGraph G,int v){
	if(v<G.vexnum){
		printf("%3c",G.vexs[v+1]);
		vi[v+1]=1;
		for(int i=0;i<G.vexnum;++i){
			if(vi[i+1]==0&&G.arcs[v][i]){shendu(G,i);}
		}
	}
}
void guangdu(MGraph G,int v){
	QPTR Q;
	Q=NULL;
	printf("%3c",G.vexs[v+1]);
	vis[v+1]=1;
	INPUT(Q,v);
	while(Q){
		DELETE(Q,v);
		for(int w=0;w<G.vexnum;w++){
			if(G.arcs[v][w]==1&&!vis[w+1]){
				printf("%3c",G.vexs[w+1]);
				vis[w+1]=1;
				INPUT(Q,w);
			}
		}
	}
}
void shendu2(MGraph G,int v){
	LINKSTACK S;
	S=NULL;
	int t=0;
	printf("%3c",G.vexs[v+1]);
	vist[v+1]=1;
	PUSH(S,v);
	while(S){
		v=S->x;
		for(int w=0;w<G.vexnum;++w){
			if(G.arcs[v][w]&&vist[w+1]==0){
				printf("%3c",G.vexs[w+1]);
				vist[w+1]=1;
				PUSH(S,w);
				t++;
				break;
			}
			
		if(t==0)POP(S);
	}
}
}
int main(void){
	MGraph G;
	INIT(G);
	for(int i=1;i<=G.vexnum;++i)
		printf("%3c",G.vexs[i]);
	printf("\n");
	for(int i=0;i<G.arcnum;++i){
		for(int j=0;j<G.arcnum;++j)
			printf("%3d",G.arcs[i][j]);
		printf("\n");
	}
	shendu(G,2);
	shendu2(G,2);
	return 0;
}


