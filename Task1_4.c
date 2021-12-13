#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct Address
{
    char name[MAX];
    char telephone_number[MAX];
    char email_address[MAX];
    struct Address *next;
}Address;

Address *first, *last;


void InitQueue()
{
    first = NULL;
    last = NULL;
}

int EmptyQueue()
{
    return first == NULL && last == NULL;
}

Address *makenodeList(char name[], char telephone_number[], char email_address[])
{
    Address *Node = (Address *) malloc(sizeof(Address));
    strcpy(Node->name, name);
    strcpy(Node->telephone_number, telephone_number);
    strcpy(Node->email_address, email_address);
    Node -> next = NULL;
    return Node;
}

void EnQueue(char name[], char telephone_number[], char email_address[])
{
    Address *p = makenodeList(name, telephone_number, email_address);
    if(first == NULL&& last == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
       last -> next = p;
       last = p;
    }
}
void DeQueue()
{
    if(!EmptyQueue())
    {
        first = first->next;
    }
}

int sizeQueue()
{
    int size = 0;
    Address *p;
    for(p = first; p != NULL; p = p->next)
    {
        size = size + 1;
    }
    return size;
}

void main()
{   
    Address A[11];
    Address *B;
    int i;
    printf("Address List:\n");
    for(i = 0; i < 11; i++)
    {   
        printf("Address %d:\n",i+1);
        printf("Name: ");
        gets(A[i].name);
        printf("Telephone number: ");
        gets(A[i].telephone_number);
        printf("Email Address: ");
        gets(A[i].email_address);
        EnQueue(A[i].name, A[i].telephone_number, A[i].email_address);
    }
    if(sizeQueue() > 10)
    {
        printf("Hang doi day.\n");
        B = first;
        DeQueue();
    }
    printf("Thong tin bi loai bo la:\n");
    printf("%s %s %s\n", B->name, B->telephone_number, B->email_address);
}
