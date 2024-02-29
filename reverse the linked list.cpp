#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Node *head=NULL;

void firstNode(int data)
{
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=data;
    head->link=NULL;
}
void addNode(int data)
{
    struct Node*temp;
    struct Node *ptr;
    ptr=head;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void reverse()
{
    struct Node *prev=NULL;
    struct Node *ptr=head;
    struct Node *next=NULL;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    head=prev;

}

void printNode()
{
    struct Node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }

}

int main()
{
    printf("Linked List: ");
    firstNode(5);
    addNode(25);
    addNode(20);
    printNode();
    printf("\n\n");
    printf("Reverse the linked list: ");
    reverse();
    printNode();
    printf("\n\n");

    return 0;

}
