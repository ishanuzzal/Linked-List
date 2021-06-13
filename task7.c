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


int main()
{
    int n;
    input();
    read();

    return 0;
}

