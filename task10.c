#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist{

    int a;
    struct Nodelist *pre;
    struct Nodelist *next;
}nodes;

nodes *head=NULL;

void input(){
    nodes *temp, *node;
    int i,n,num;
    printf("How many nodes you want to insert\n");
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        printf("Enter %d node: ",i);
        scanf("%d",&num);
        //allocating memory
        node=(nodes *)malloc(sizeof(nodes));
        node->a=num;
        node->pre=NULL;
        node->next=NULL;
        //inserting first node address to head
        if(head==NULL){
            head=node;
            temp=head;
        }
        else{
           temp->next=node;
           node->pre=temp;
           temp=node;

        }
    }
}
void read(){
    nodes *temp;
    temp=head;

    while(temp!=NULL){
        printf("%d ",temp->a);
        temp=temp->next;
    }
}

void insertIndexNode(){
    nodes *temp,*node,*temp2;
    int num,n,count=1;
    temp=head;

    printf("\nInsert the index you want to insert a node\n");
    scanf("%d",&n);
    //allocating memory for last node
    node = (nodes *)malloc(sizeof(nodes));
    printf("\nEnter data for last node\n");
    scanf("%d",&num);
    node->a=num;
    node->pre=NULL;
    node->next=NULL;
    //traversing previous node index
    while(count<n-1){
        temp=temp->next;
        count++;
    }
    //temp2 containing nth index's next index
    temp2=temp->next;
    node->next=temp2->next;
    temp2->pre=node;
    temp->next=node;
    node->pre=temp;
}




int main()
{
    input();
    printf("Nodelist before inserting any nodes\n");
    read();
    insertIndexNode();
    printf("\nNodelist after inserting nth index nodes\n");
    read();



    return 0;
}

