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
void insert_after_a_node(struct Node *prev_node,int data){
    if(prev_node==NULL){
        printf("List is empty");
    }
    struct Node * t=(struct Node *)malloc(sizeof(struct Node));
    t->val=data;
    t->next=prev_node->next;
    prev_node->next=t;
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
    insert_after_a_node(head->next,200);
    display(head);
    
}