#include <stdio.h>
#include <stdlib.h>

typedef struct nodelist
{
    int n;
    struct nodelist *next;
} nodes;

nodes *head=NULL;

void input()
{

    nodes *temp, *node;
    int i,n,num;

    for(i=1; i<=5; i++)
    {
        scanf("%d",&n);
        node=(nodes *)malloc(sizeof(nodes));
        node->n=n;
        node->next=NULL;

        if(head==NULL)
        {
            head=node;
            temp=head;
        }
        else
        {
            temp->next=node;
            temp=temp->next;
        }

    }

}
void read()
{
    nodes *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->n);
        temp=temp->next;
    }

}
void del(){
    nodes *temp,*temp2;
    temp=head;
    int n,i;
    printf("\nEnter which index node u want to delete\n");
    scanf("%d",&n);
    //index start with 1
    for(i=1; i<n-1; i++){
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=temp2->next;

}


int main()
{
    int num,i,n;
    input();
    printf("Nodes before deleting\n");
    read();
    del();
    printf("\nNodes after deleting\n");
    read();
    return 0;
}
