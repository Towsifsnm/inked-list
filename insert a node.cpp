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


//insert node at particular position
void add_Node_n_position(int position,int data)
{
    struct Node *ptr=NULL;
    struct Node *temp=NULL;
    ptr=head;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    int i=0;
    while(i!=position-1)
    {
        ptr=ptr->next;
        i++;
    }
    temp->next=ptr->next;
    ptr->next=temp;

}

//delete Node at n position
void del_n_position(int position)
{
    if(head->next==NULL)
    {
        head=NULL;
    }
    else{
        struct Node *ptr;
        ptr=head;
        int i=0;
        while(i!=position-1)
        {
            ptr=ptr->next;
            i++;
        }
        ptr->next=ptr->next->next;
    }
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
    printf("\n\n");
    printf("After Extend Link: \n");
    add_Node_n_position(2,25);
    del_n_position(1);
   add_Node_n_position(2,20);
    del_n_position(3);
    printNode();
    printf("\n\n\n");

    return 0;
}
