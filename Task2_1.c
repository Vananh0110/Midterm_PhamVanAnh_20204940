#include<stdio.h>
char stack[100] ;
char A[100];
char B[100];
int dem = 0;
int top = -1;
int empty()
{
    if (top == -1)
    return 1;
    else return 0;
}
int full()
{
    if (top == 100)
    return 1;
    else return 0;
}
void push(char x)
{   top++;
    stack[top]=x;
    
}
char pop()
{    
    top = top-1;
    return stack[top+1];
}

void get()
{   
    printf("Nhap bieu thuc: ");
    char c;
    int i=0;
    scanf("%s",A);
}
int uutien1(char c)
    {
        if(c == '*'|| c == '/')
        return 1;
        else return 0;
    }
 
int uutien2(char c)
    {
        if(c == '+'||c == '-')
        return 1; else return 0;
    }
void change()
{      
    int c=0;
    while (c==0)
    {
        B[dem] = pop();
        dem ++;
        c=empty();
    }
    
}   
void result(char x)
{   
    if('0'<= x && x <='9')
    {
        B[dem]=x;
        dem ++;
    }
    else if(uutien1(stack[top]) == 1 && uutien2(x) == 1) 
    {
        change();
        push(x);
    }
    else push(x);
}

void main()
{
    get();
    int i=0;
    while(A[i]!='\0')
    {
        result(A[i]);
        i++;
    }
    change();

    for(int i = 0 ;i <= 10; i++)
    {
        printf("%c",B[i]);
    }
}