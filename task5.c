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
            printf("%d ",temp->n);
            temp=temp->next;
        }

}
void reverse(){
        nodes *temp, *temp2;
        temp=NULL;
        temp2=NULL;

        while(head != NULL){
            temp2=head->next;
            head->next=temp;
            temp=head;
            head=temp2;
        }
        head=temp;


}


int main()
{
    int n;
    input();
    printf("Linked list before reversing it\n");
    read();
    reverse();
    printf("\nLinked list after reversing it\n");
    read();


    return 0;
}
