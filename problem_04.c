#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
};
void reverse_list(struct Node **head){
    struct Node *p=*head;
    struct Node *t;
    while(p){
        t=p->prev;
        p->prev=p->next;
        p->next=t;
        p=p->prev;
    }
    if(t){
        *head=t->prev;
    }
    printf("Reversed\n");
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
    reverse_list(&head);
    display(head);

}