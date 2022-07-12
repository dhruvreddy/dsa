 #  include <stdio.h>
#include <stdlib.h>

struct doubleLinkedlist
{
    int data;
    struct doubleLinkedlist *next;
    struct doubleLinkedlist *prev;
};

struct doubleLinkedlist *head = NULL;

struct doubleLinkedlist* create(int data) {
    struct doubleLinkedlist *newNode = (struct doubleLinkedlist*)malloc(sizeof(struct doubleLinkedlist));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void insertEnd(int data) {
    struct doubleLinkedlist *newNode = create(data);
    struct doubleLinkedlist *temp = head;
    if (head == NULL)
    {
        head = newNode;
    } else {
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        
        temp -> next = newNode;
        newNode -> prev = temp;
    }
    
}

void delete() {
    struct doubleLinkedlist *temp;
    struct doubleLinkedlist *prevtemp;
    temp = head;
    while (temp -> next != NULL)
    {
        prevtemp = temp;
        temp = temp -> next;
    }

    prevtemp -> next = NULL;
    temp -> prev = NULL;
    free(temp);
    
}

void display() {
    struct doubleLinkedlist *temp = head;
    while (temp != NULL){
        printf("%d", temp -> data);
         temp = temp -> next;
    }
    
}


int main(int argc, char const *argv[])
{
    return 0;
}
