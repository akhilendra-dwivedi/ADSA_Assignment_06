#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node *prev;
    struct Node *next;
};
int len(struct Node *head){
    struct Node *p=head;
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
int middle_elm(struct Node *head){
    struct Node *slow=head,*fast=head;
    while(fast->next){
        slow=slow->next;
        fast=fast->next;
        if(fast)fast=fast->next;
    }
    return slow->val;
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
    printf("Length is ->\t%d\n",len(head));
    printf("Middle elm is -> \t %d\n",middle_elm(head));

}