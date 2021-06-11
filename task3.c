
#include <stdio.h>
#include <stdlib.h>

typedef struct nodelist
{
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
            node->next=NULL;
            if(head==NULL){
                head=node;
                temp=head;
            }
            else{
                temp->next=node;
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
        nodes *temp, *node,*temp2;
        temp=head;
        int n,v,count=0;
        printf("Enter which index you want to insert a node");
        scanf("%d",&n);
        node=(nodes *)malloc(sizeof(nodes));
        printf("Enter the node value\n");
        scanf("%d",&v);
        node->n=v;

        while(count<n-1){
            temp=temp->next;
            count++;
        }
        temp2=temp->next;
        temp->next=node;
        node->next=temp2;
}


int main()
{
    int n;
    input();
    insert();
    read();

    return 0;
}
