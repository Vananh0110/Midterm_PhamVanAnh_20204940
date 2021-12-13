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

void Input()
{
   
    FILE *fp = fopen("input.txt","r");
    if(fp == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {   
        while(!feof(fp))
        {
            char name[MAX], telephone_number[MAX], email_address[MAX];
            fscanf(fp, "%s %s %s", name, telephone_number, email_address);
            EnQueue(name, telephone_number, email_address);
        }
    }
    fclose(fp);
}
void DeQueue()
{
    if(!EmptyQueue())
    {
        first = first->next;
    }
}

void searching(char name[])
{   
    int dem = 0;
    FILE *fp = fopen("outputtask1_3.txt","w+");
    while(!EmptyQueue)
    {
        Address *p = first;
        if(strcmp(name,p->name) == 0)
        {
            dem++;
            fprintf(fp,"%s %s %s\n", p->name, p-> telephone_number, p -> email_address);
        }
        DeQueue();
    }
    if(dem == 0) fprintf(fp,"Ten khong co trong danh sach.\n");
    fclose(fp);
}

void printinfor()
{   
    printf("Thong tin duoc nhap vao la:\n");
    Address *p;
    for(p = first; p != NULL; p = p->next)
    {
        printf("%s %s %s\n",p -> name, p -> telephone_number, p -> email_address);
    }
}

void main()
{
    InitQueue();
    Input();
    printinfor();
    printf("Nhap ten can tim kiem: ");
    char name[MAX];
    gets(name);
    searching(name);
}
