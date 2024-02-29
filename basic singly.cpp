#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

//Fisrst Node Create
void firstNode(int data)
{
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=data;
    head->next=NULL;
}

//Add nodes at end
void addNode(int data)
{
    struct Node *ptr;
    ptr=head;
    struct Node *temp=NULL;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
}

//travers Node & print
void printNode()
{
    struct Node *temp;
    temp=head;
    printf("Linked List: ");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

int main()
{
    firstNode(5);
    addNode(10);
    addNode(15);
    printNode();

    return 0;
}
