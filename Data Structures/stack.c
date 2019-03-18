#include<stdio.h>
#include <stdlib.h>
#define max_size 5

struct stack{
    int items[max_size];
    int top;
};
typedef struct stack S;


void push(S *s){
    if(s->top == max_size - 1)
        printf("Stack Full\n");
    else{
        int x;
        printf("Enter the item to push : ");
        scanf("%d",&x);
        s->items[++(s->top)] = x;
    }
}

void pop(S *s){
    if(s->top == -1)
        printf("Stack Empty");
    else{
        int x;
        x = s->items[(s->top)--];
        printf("%d popped\n",x);
    }
}

void peek(S s){
    if(s.top == -1)
        printf("Stack Empty\n");
    else{
        int x;
        x = s.items[s.top];
        printf("%d peek item\n",x);
    }
}
void display(S s){
    int i;
    for(i=0;i<=(s.top);i++){
        printf("%d\t",s.items[i]);
    }
    printf("\n");
}

int main(){
    S s;
    s.top = -1;
    int ch;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice  : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push(&s);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(s);
                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("Exiting\n");
                return 0;
        }
    }
}