//
//  main.cpp
//  9.18.03.c++
//
//  Created by s20181105879 on 2019/9/18.
//  Copyright © 2019 s20181105879. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *head;
    
    head = createlist();
    head = deleteeven(head);
    printlist(head);
    
    return 0;
}

struct ListNode *createlist()
{
    struct ListNode *head,*newhead,*p;
    head=newhead=(struct ListNode *)malloc(sizeof(struct ListNode));
    head->next=NULL;
    int n;
    scanf("%d",&n);
    while (1) {
        if(n==-1)
        {
            break;
        }
        p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->data=n;
        p->next=NULL;
        head->next=p;
        head=p;
       scanf("%d",&n);
    }
    return  newhead->next;
}
struct ListNode *deleteeven( struct ListNode *head1 )
{
    struct ListNode *head,*p,*q,*newhead;
    p=head1;
    head=head1;
    while(p&&p->data%2==0)
    {
        q=p->next;
        p->next=q->next;
        free(q);
    }
    head=p;
    
    while(p&&p->next)
    {
        while(p->next&& p->next->data%2==0)
        {
            q=p->next;
            p=p->next;
            free(q);
        }
        p=p->next;
    }
   return head;
    
}
