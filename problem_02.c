#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
};
void insert_at_a_position(struct Node *head,int pos,struct Node *insert){
    struct Node *p=head;
    while(pos-2){
        p=p->next;
        pos--;
    }
    insert->next=p->next;
    p->next->prev=insert;
    p->next=insert;
    insert->prev=p;
    printf("Inserted\n");
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
    struct Node *insert=(struct Node*)malloc(sizeof(struct Node));
    insert->val=100;
    insert_at_a_position(head,3,insert);
    display(head);
}