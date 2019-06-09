#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int n,e;

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
}

int main(){
    int i,j,n;
    
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&n);
        int graph[n+1][n+1],arr[n+1],pre[n+1],post[n+1];
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++)
                graph[i][j] = 0;
        }
        for(i=1;i<=n;i++){
            scanf("%d %d %d",&arr[i],&pre[i],&post[i]);
        }
        int flag=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i!=j){   
                    if( ((pre[i] > pre[j]) && (post[i] < post[j])) || ((pre[i] < pre[j]) && (post[i] > post[j])) ||((pre[i] < pre[j]) && (post[i] < post[j]) ) ||((pre[i] > pre[j]) && (post[i] > post[j])){
                        continue;
                }else{
                    printf("0\n");
                    flag = 1;
                    break;
                }

            if(flag==1){
                break;
            }
        }
        if(flag==0){
            printf("1\n");
        }
        
    }
}
}
}
}
