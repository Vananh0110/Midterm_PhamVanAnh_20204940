#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct Address
{
    char name[MAX];
    char telephone_number[MAX];
    char email_address[MAX]; 
}Address;

Address A[MAX];

void input()
{
    FILE *f = fopen("input.txt", "r");
    if(f == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {   
        int i;
        for(i = 0; i < 10; i++)
        {
            fscanf(f,"%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address );
        }
        fclose(f);
    }
}

void output(int i)
{   
    FILE *fp = fopen("outputtask1.txt","w+");
    if(i==-1)
        fprintf(fp,"Ten khong co trong danh sach.\n");
    else
    {
        fprintf(fp,"%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address);
    }
        fclose(fp);
}

int BinarySearch(Address A[], char name[], int N)
{
    int low, mid, high;
    low = 0;
    high = N-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(strcmp(A[mid].name,name)<0)
            low = mid + 1;
        else if(strcmp(A[mid].name,name)>0)
            high = mid - 1;
        else return mid;
    }
    return -1;
}
void printinfor()
{
    printf("Thong tin duoc nhap vao la:\n");
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address);
    }
}
void main()
{
    input();
    printinfor();
    char name[MAX];
    printf("Nhap ten can tim kiem: ");
    gets(name);
    output(BinarySearch(A,name,10));
}