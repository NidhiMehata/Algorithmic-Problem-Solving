#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int n,e;
int top[50],ind=0;
int counter=1;
void dfsrec(int graph[][n+1],int s,int visited[],int pre[],int post[]){
    int i;
    visited[s]=1;
    pre[s]=counter++;
    for(i=1;i<=n;i++){
        if(graph[s][i]==1 && !visited[i]){
            dfsrec(graph,i,visited,pre,post);
        }
    }
    top [ind++] = s;
    post[s]=counter++;
}

void dfs(int graph[][n+1],int s){
    int i;
    int visited[n+1];
    int pre[n+1],post[n+1],j;
    for(i=0;i<=n;i++){
        pre[i] = post[i] = visited[i] = 0; 
    }
    visited[s]=1;

    dfsrec(graph,s,visited,pre,post);
    for(i=1;i<=n;i++){
        if(!visited[i]){    
            dfsrec(graph,i,visited,pre,post);
        }
    }
    for(i = 1; i <=n ; i++ )
        printf("%d (%d , %d)\n",i,pre[i],post[i]);

    for(i=ind-1;i>=0;i--)
        printf("%d\t",top[i]);
}

int main(){
    int i,j;
    scanf("%d %d",&n,&e);
    int graph[n+1][n+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
            graph[i][j] = 0;
    }


    for(i=0;i<e;i++){
        int m,n;
        scanf("%d %d",&m,&n);
        graph[m][n]  = 1;
    }
    dfs(graph,1);
    return 0;
   
}