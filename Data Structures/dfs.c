#include<stdio.h>
int n,e;

int counter=0;
int dfsrec(int graph[][n+1],int s,int visited[],int pre[],int post[]){
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

int dfs(int graph[][n+1],int s){
    int i;
    int visited[n+1];
    int pre[n+1],post[n+1],j;
    for(i=0;i<=n;i++){
        pre[i] = post[i] = visited[i] = 0; 
    }
    // printf("%d\n",s+1);
    visited[s]=1;

    dfsrec(graph,s,visited,pre,post);
    for(i=1;i<=n;i++){
        if(!visited[i]){    
            //visited[i]=1;
            dfsrec(graph,i,visited,pre,post);
        }
    }   
     for(i=1;i<=n;i++){
        printf("%d(%d , %d)\n",i,pre[i],post[i]);
    } 
}

int main(){
    int i,j;
    scanf("%d %d",&n,&e);
    int graph[n+1][n+1];
    printf("Enter the edges : \n");
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
            graph[i][j] = 0;
    }


    for(i=0;i<e;i++){
        int m,n;
        scanf("%d %d",&m,&n);
        graph[m][n] = graph[n][m] = 1;
    }
 
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
            printf("%d\t",graph[i][j]);
        printf("\n");
    }

    int src;
    printf("Please enter source :");
    scanf("%d",&src);
    dfs(graph,src);
   
}