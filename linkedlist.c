#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};

struct linkedlist *head = NULL;

struct linkedlist* createNode(int i) {
    struct linkedlist *newNode = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    newNode -> data = i;
    newNode -> next = NULL;
    return newNode;
};

void insertEnd(int i) {
    struct linkedlist *newNode = createNode(i);
    struct linkedlist *temp = head;
    if (head == NULL)
    {
        head = newNode;
    } else {
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
    
    
}

void insertBetween(int i, int count) {
    struct linkedlist *newNode = createNode(i );
    struct linkedlist *temp = head;
    if (head == NULL)
    {
        head = newNode;
    } else {
        for (int j=1; j<count-1; j++) 
        {
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    
}

void deleteEnd() {
    struct linkedlist *temp;
    struct linkedlist *prevtemp;
    temp = head;
    while (temp -> next != NULL)
    {
        prevtemp = temp;
        temp = temp -> next;
    }
    prevtemp -> next = NULL;
    free(temp);
}

void delete(int count) {
    int j = 1;
    struct linkedlist *temp;
    struct linkedlist *nxttemp;
    temp = head;
    while (j < count - 1)
    {
        temp = temp -> next;
        j++;
    }
    nxttemp = temp -> next;
    temp -> next = nxttemp -> next;
     free(nxttemp);
}

void find(int givenData) {
    struct linkedlist *temp;
    struct linkedlist *nxttemp;
    temp = head;
    while (temp -> data != givenData)
    {
        temp = temp -> next;

    }
    nxttemp = temp -> next;
    temp -> next = nxttemp -> next;
     free(nxttemp);
}  

void check(int count, int prevCount) {
struct linkedlist *temp;    
struct linkedlist *prevtemp;
    temp = head;
    prevtemp = head;

    for (int i = 0; i < count - 1; i++)
   {
       temp = temp -> next;
   }
   for (int i = 0; i < prevCount - 1; i++)
   {
       prevtemp = prevtemp -> next;
   }

    if (temp -> data == prevtemp -> data)
    {
        if (count++ == prevCount--) {
            printf("1.Palindrone\n");
        } else {       
        printf("Checking other nodes\n");
        for (int i = 1; i < count/2; i++)
        {
            count += count;
        }
        for (int i = 1; i < prevCount/2; i++)
        {
            prevCount -= prevCount;
        } 
        while (count == prevCount)
        {
            for (int i = 0; i < count - 1; i++)
            {
                temp = temp -> next;
            }
            for (int i = 0; i < prevCount - 1; i++)
            {
                prevtemp = prevtemp -> next;
            }
        }
        while (1)
        {
            if (temp -> data == prevtemp -> data){
                printf("Pali\n");
            } else {
                printf("Not\n");
            }
        }
        }
    }
    else {
        printf("Not Palindrone\n");
    }
}

void display() {
    struct linkedlist *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
    
}

int main(int argc, char const *argv[])
{
    return 0;
}

