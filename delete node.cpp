#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* temp = nullptr;
node* head = nullptr;
node* next = nullptr;

void addToBeginning(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void addToEnd(int data){
    node* newNode = new node;
    newNode->data = data;
    if(head == nullptr){
        head = newNode;
    }
    temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addToPosition(int position, int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;
    if(position == 1){
        newNode->next = head;
        head = newNode;
    }
    else{
    temp = head;
     for (int i = 1; i < position - 1 ; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(int position){
    if (position == 0){
        head = head->next;
    }
    temp = head;
    int i = 0;
    while (temp != nullptr){
        if (position == i){
            temp->next = temp->next->next;
        }
        i++;
        temp=temp->next;
    } 
}

void printList(){
    temp = head;
    cout << "Linked list : ";
    while (temp != 0)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

void reverseList(){
    node* current = head;
    node* previous = nullptr;
    node* next;

    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    head = previous;
}

int main(){
    addToBeginning(5);
    addToEnd(10);
    addToEnd(15);
    addToEnd(20);
    //deleteNode(2);
    //addToPosition(2,12);
    //reverseList();
    printList();
}
