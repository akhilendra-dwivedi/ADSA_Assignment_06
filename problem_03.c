#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
};
void deletion(struct Node *head,int target){
    struct Node *p=head;
    while(p){
        if(p->val==target){
            if(p==head){
                head=head->next;
                head->prev=NULL;
            }
            else if(p->next==NULL){
                p->prev->next=NULL;
            }
            else{
                p->prev->next=p->next;
                p->next->prev=p->prev;
            }
            printf("Deleted");
            return;
        }
        p=p->next;
    }
    printf("Target not found");
}
void display(struct Node *head){
    struct Node *p=head;
    while(p){
        printf("%d \t",p->val);
        p=p->next;
    }
}
int main(){
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    head->val=10;
    head->next=NULL;
    head->prev=NULL;
    int a[4]={20,30,40,50};
    struct Node *p=head;
    for(int i=0;i<4;i++){
        struct Node *t=(struct Node *)malloc(sizeof(struct Node ));
        t->val=a[i];
        p->next=t;
        t->prev=p;
        t->next=NULL;
        p=t;
    }
    printf("\n");
    display(head);
    deletion(head,40);
    display(head);

}