
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

void del(){
    nodes *temp,*temp2, *node;
    temp=head;

    if(head==NULL){
        return;
    }

    //deleting first node
    head=temp->next;
    free(temp);

    //deleting lastNode
    temp=head;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    free(temp);


}

int main()
{
    int n;
    input();
    printf("Nodes output before deleting any nodes\n");
    read();
    del();
    printf("Nodes output after deleting first node and last node\n");
    read();
    return 0;
}
