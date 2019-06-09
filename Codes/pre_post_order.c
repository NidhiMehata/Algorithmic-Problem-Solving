#include<stdio.h>
int visited[6],notvisited[100],processed[100],dist[100],pre[6],post[6];
int counter = 1;
void dfsrec(int g[][6],int s){
    int i;
    pre[s]=counter++;
    visited[s]=1;
    for(i=0;i<6;i++){
        if(g[s][i] && !visited[i]){
            dfsrec(g,i);  
            
        }
    }
    post[s]=counter++;    
}
int count=0;
void dfs(int g[][6]){
    int i;
    for(i=0;i<6;i++){
        visited[i]=0;
    }
    
    for(i=0;i<6;i++){
        if(!visited[i]){
            count++;
            dfsrec(g,i);
        }
    }
}


int main(){
    int n=6,e=5;
    int i,j;
    int graph[][6]= {
                {0, 1, 1, 1, 0, 0},
                {1, 0, 1, 0, 0, 0},
                {1, 1, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 1, 0},
    };

    dfs(graph);
    
    for(i=0;i<6;i++){
        printf("%d : %d/%d\n",i,pre[i],post[i]);
    }


}