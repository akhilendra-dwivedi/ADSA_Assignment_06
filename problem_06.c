#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

void instertion_at_end(struct Node *head,int data){
    struct Node *p=head,*t,*q=head;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->val=data;
    while(p->next!=q){
        p=p->next;
    }
    p->next=t;
    t->next=q;
}
void instertion_at_begin(struct Node **head,int data){
    struct Node *p=*head,*t,*q=*head;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->val=data;
    while(p->next!=q){
        p=p->next;
    }
    p->next=t;
    t->next=*head;
    *head=t;
}
void display(struct Node*head){
    struct Node *p=head;
    printf("%d\t",p->val);
    p=p->next;
    while(p!=head){
        printf("%d\t",p->val);
        p=p->next;
    }
}
int main(){
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    //first node
    head->val=10;
    head->next=head;
    instertion_at_end(head,20);
    instertion_at_end(head,30);
    instertion_at_end(head,40);
    display(head);
    printf("Inster at end:\n");
    instertion_at_begin(&head,110);
    display(head);
}