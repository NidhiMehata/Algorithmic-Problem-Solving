#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node Node;


Node * insert_start(Node *start){
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL)
    {
        printf("Memory full\n");
        return start;
    }
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(start == NULL){
        return newnode;
    }else{
        newnode->next = start;
        return newnode;
    }
}


Node * insert_end(Node *start){
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL)
    {
        printf("Memory full\n");
        return start;
    }
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    
    if(start == NULL){
        return newnode;
    }
    Node *temp = start;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return start;
}

Node * insert_pos(Node *start){
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL)
    {
        printf("Memory full\n");
        return start;
    }

    Node *temp = start;
    int i,pos;
    printf("Enter pos to insert at : ");
    scanf("%d",&pos);

    if(pos == 1){
        insert_start(start);
        return start;
    }

    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    for(i=0;i<pos-2;i++)
        temp = temp->next ;
    newnode -> next = temp->next;
    temp->next = newnode;
    return start;
}

Node *delete_end(Node * start){
    if(start == NULL){
        printf("List Empty\n");
        return start;
    }

    if(start->next == NULL)
    {
        free(start);
        return NULL;
    }

    Node *curr = start , *prev = NULL;
    while(curr -> next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return start;
}


Node *delete_start(Node * start){
    if(start == NULL){
        printf("List Empty\n");
        return start;
    }

    if(start->next == NULL)
    {
        free(start);
        return NULL;
    }
    Node *temp = start->next;
    free(start);
    return temp;
}

void display(Node * start){
    if(start == NULL){
        printf("Queue Empty");
        return;
    }
    Node *temp = start;
    while(temp->next != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}



int main(){
    Node * start;
    start = NULL;
    int ch  ;
    while(1){
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at end\n6.Display\n7.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                start = insert_start(start);
                break;
            case 2:
                start = insert_end(start);
                break;
            case 3:
                start = insert_pos(start);
                break;
            case 4:
                start = delete_start(start);
                break;
            case 5:
                start = delete_end(start);
                break;
            case 6:
                display(start);
                break;
            default:
                printf("Exiting\n");
                return 0;
        }
    }
} 