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
void delete(struct Node**head,int target){
    if(!*head){
        printf("List is empty\n");
        return;
    }
    struct Node *p=*head,*t,*q=*head;
    //deletion of first elm
    if(*head->val==target){
        if(*head->next==*head){//single elm
            free(*head);
            return;
        }
        while(p->next!=*head){
            p=p->next;
        }
        p->next=*head->next;
        free(p);
        *head=q;
        return;
    }
    //deletion of other node
    while(p->next->val!=target){
        p=p->next;
    }
    p->next=p->next->next;
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
    delete(&head,20);
}