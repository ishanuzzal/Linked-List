#include <stdio.h>
#include <stdlib.h>

typedef struct nodelist
{
    struct nodelist *pre;
    int n;
    struct nodelist *next;
}nodes;

nodes *head=NULL;

void input(){
        nodes *node,*temp;
        int n;
        scanf("%d",&n);

        while(n!=0){
            node=(nodes *)malloc(sizeof(nodes));
            node->n=n;
            node->pre=NULL;
            node->next=NULL;
            if(head==NULL){
                head=node;
                temp=head;
            }
            else{
                temp->next=node;
                node->pre=temp;
                temp=temp->next;
            }
            scanf("%d",&n);
        }

}
void read(){
        nodes *temp;
        temp=head;
        if(temp==NULL){
            printf("List is empty\n");
            return;
        }
        while(temp!=NULL){
            printf("%d\n",temp->n);
            temp=temp->next;
        }

}

void insert(){
    nodes *temp, *node;
    int n;
    temp=head;
    node=(nodes *)malloc(sizeof(nodes));

    printf("Enter a new node\n");
    scanf("%d",&n);

    node->n=n;
    node->pre=NULL;
    node->next=NULL;

    if(head->pre==NULL){
        node->next = head;
        head->pre = node;
        head = node;
    }

}


int main()
{
    int n;
    input();
    printf("\nDoubly Linked list before inserting any node\n");
    read();
    insert();
    printf("\nDoubly Linked list after  inserting node to the 1st place\n");
    read();
    return 0;
}

