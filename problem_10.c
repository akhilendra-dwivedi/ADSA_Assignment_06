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
void display(struct Node*head){
    struct Node *p=head;
    printf("%d\t",p->val);
    p=p->next;
    while(p!=head){
        printf("%d\t",p->val);
        p=p->next;
    }
}
int len(struct Node * head){
    int c=1;
    struct Node *p=head;
    if(head->next){
        p=p->next;
    }
    while(p->next!=head){
        p=p->next;
        c++;
    }
    return c;
}
struct Node *[] halves(struct Node*head,int c){
    struct Node *p=head,*q;
    c=c/2;
    while(c){
        p=p->next;
        c--;
    }
    p->next=head;
    q=p;
    while(q->next!=head){
        q=q->next;
    }
    q->next=p;
    return {head,p};
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
    struct Node *x[]=halves(head,len(head));
    
}