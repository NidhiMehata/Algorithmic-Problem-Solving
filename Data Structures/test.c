#include<stdio.h>
int visited[10]={0};
int pre[10]={0},post[10]={0};
int counter=0;
int dfsrec(int graph[][5],int s){
    int i;
    visited[s]=1;
    printf("%d - %d -%d \n",s,pre[s],post[s]);
    pre[s]=counter++;
    for(i=0;i<5;i++){
        if(graph[s][i]==1 && !visited[i]){
            
            dfsrec(graph,i);
        }
    }
    post[s]=counter++;
}

int dfs(int graph[][5],int s){
    int i;
    // printf("%d\n",s+1);
    visited[s]=1;
    
    dfsrec(graph,s);
    for(i=0;i<5;i++){
        if(!visited[i]){
            visited[i]=1;
            dfsrec(graph,i);
        }
    }    
}



int main(){
    int i,e,n;
    scanf("%d %d",&n,&e);
    int graph[n][n];
    printf("Enter the edges : \n");
    for(i=0;i<e;i++){
        int m,n;
        scanf("%d %d",&m,&n);
        graph[m][n] = graph[n][m] = 1;
    }
    // int graph[][5]={
    //     {0, 1, 1, 0, 0},
    //     {1, 0, 0, 1, 1},
    //     {1, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0},
    //     {0, 1, 0, 0, 0},
    // };
    dfs(graph,2);
    for(i=0;i<5;i++){
        printf("%d(%d , %d)\n",i+1,pre[i],post[i]);
    }
}