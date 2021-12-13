#include<stdio.h>
char stack[100] ;
char A[100];
char B[100];
int dem = 0;
int top = -1;
int EmptyStack()
{
    if (top ==-1)
    return 1;
    else return 0;
}
int full()
{
    if (top ==999)
    return 1;
    else return 0;
}
void push(char x)
{   top++;
    stack[top]=x;
    
}
char pop()
{    top=top-1;
     return stack[top+1];
  
}

void get()
{
    char c;
    int i=0;
    printf("Nhap bieu thuc: ");
    scanf("%s",A);
}
int uutien1(char c)
    {
        if(c == '*' || c == '/')
            return 1;
        else return 0;
    }
 
int uutien2(char c)
    {
        if(c =='+' || c=='-')
            return 1;
        else return 0;
    }
void change()
{   
    int c=0;
    while (c==0)
    {
        B[dem] = pop();
        dem ++;
        c = EmptyStack();
    }
    
}   
void result(char x)
{   
    if('0'<= x && x <= '9')
    {
        B[dem]=x;
        dem++;}
    else if(uutien1(stack[top])==1 && uutien2(x)==1)
    {
        change();
        push(x);
    }
    else push(x);
}

int stack2[100] ;
char C[100];
char D[100];
int dem2=0;
int top2=-1;
int EmptyStack2()
{
    if (top2 ==-1)
    return 1;
    else return 0;
}
int full2()
{
    if (top2 == 100)
    return 1;
    else return 0;
}
void push2(char x)
{   top2++;
    stack2[top2]=x;
    
}
int pop2()
{   
    top2 =top2-1;
    return stack2[top2+1];
}
void result2(char x)
{   
    int a,b,c;
    if('0' <= x && x <= '9')
    push2(x-48);
    else if(x=='+')
    {
        a=pop2();
        b=pop2();
        c=a+b;
        push2(c);
        
    }
     else if(x=='*')
    {
        a=pop2();
        b=pop2();
        c=a*b;
        push2(c);
        
    }
}

void main()
{   get();
    int i=0;
    while(A[i]!='\0')
    {
        result(A[i]);
        i++;
    }
    change();
    int j = 0;
    while(B[j] != '\0')
    {
        C[j]=B[j];
        j++;
    }
    
    int z = 0;
    while(C[z]!='\0')
    {
        result2(C[z]);
        z++;
    }
    printf("%d",pop2());  
}