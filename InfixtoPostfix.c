#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(char ele)
{
    if (top==(MAX-1))
        printf("Stack Overflow");
    else
    {
        top = top + 1;
        stack[top] = ele;
    }
}

char pop() //fu'n need to be char
{
    if(top>=0)
    {
        char popele = stack[top];
        top--;
        return popele;
    }
    return '\0';
}

int prece(char ch)
{
    if (ch=='*' || ch=='/')
        return 2;
    else if (ch=='+' || ch=='-')
        return 1;
    else
        return 0;
}

int operand(char op)
{
    if ((op>='a' && op<='z') || (op>='A' && op<='Z'))
        return op;
    return '\0';
}

void inToPos (char ifix[], char pfix[])
{
    int i = 0, j = 0;
    char ch;
    while (ifix[i]!='\0')
    {
        ch = ifix[i];
        if (operand(ch))
            pfix[j++] = ch;
        else if (ch =='(')
            push(ch);
        else if (ch ==')')
        {
            while (stack[top]!='(')
            {
                pfix[j++] = pop();
            }
            pop(); //To remove (
        }
        else
        {
            // Very IMP
            while (top != -1 && prece(stack[top])>=prece(ch))
            {
                pfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while(top!=-1)
    {
        pfix[j++] = pop();
    }
    pfix[j] = '\0'; //to end the postfix string
}

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter Infix Operation: ");
    // gets(infix);
    fgets(infix, MAX, stdin);
    // scanf("%s", infix);
    inToPos(infix, postfix);
    printf("Postfix Expression: %s", postfix);
}