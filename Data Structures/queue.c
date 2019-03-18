#include<stdio.h>
#define max_size 5
struct queue{
    int a[max_size];
    int front;
    int rear;
};
typedef struct queue Q;

void enqueue(Q *q){
    if(q->rear == max_size-1)
        printf("Queue Full");
    else{
        int x;
        printf("Enter the item : ");
        scanf("%d",&x);
        q->a[++(q->rear)] = x;
    }
}
void dequeue(Q *q){
    if(q->front > q->rear)
        printf("Queue empty");
    else{
        int x;
        x = q->a[(q->front)++];
        printf("Popped item : %d\n",x);
    }
}

void display(Q q){
    int i;
    for(i=q.front;i<=q.rear;i++){
        printf("%d\t",q.a[i]);
    }
}

int main(){
    int ch;
    Q q;
    q.front = 0;
    q.rear = -1;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1 :
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(q);
                break;
            default:
                printf("Exiting\n");
                return 0;
        }
    }
}