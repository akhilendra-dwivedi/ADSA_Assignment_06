#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
};


void insertion_end(struct Node *head,int data){
    struct Node *p;
    p=head;
    while(p->next)p=p->next;
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->val=data;
    t->prev=p;
    p->next=t;
    t->next=NULL;
}

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
    printf("Enter first node:");
    head->val=10;
    head->next=NULL;
    head->prev=NULL;
    insertion_end(head,20);
    insertion_end(head,30);
    insertion_end(head,40);
    display(head);
    deletion(head,20);
    display(head);
}