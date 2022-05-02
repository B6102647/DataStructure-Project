#include <bits/stdc++.h>
#include <string>
typedef struct nd{
    char c;
    struct nd *next;
} node;
node *top = NULL;

void push(char ch)
{
    node *n = (node*)malloc(sizeof(node));
    n->next = top;
    top = n;
    n->c = ch;
}

char pop()
{
    char p;
    node *n;
    n = top;
    top = top->next;
    p = n->c;
    free(n);
    return p;
}
char stacktop()
{
    if(top == NULL )
        return NULL;
    else
        return top->c;
}

int checkPriority(char c)
{
    int priority;
    if(c=='^')
        priority = 3;
    else if(c=='*'||c=='/')
        priority = 2;
    else if(c=='+'||c=='-')
        priority = 1;
    else
        priority = -1;
    return priority;
}

void checkOperator(char ch)
{
    if(stacktop() == NULL )
        push(ch);
    else
    {
        if(checkPriority(ch)<=checkPriority(stacktop()))
        {
            while(checkPriority(ch)<=checkPriority(stacktop())&& stacktop != NULL)
            {
                printf("%c ",pop());
            }
        }
        push(ch);
    }
}

bool isBasicOperator(char c)
{
    if(c == '+' || c == '-' ||c == '*' ||c == '/' ||c == '^' ||c == '(' ||c == ')'||c == '.')
        return true;
    else
        return false;
}
bool isOperator(char c)
{
    if(c == '+' || c == '-' ||c == '*' ||c == '/' ||c == '^' ||c == '(' ||c == ')')
        return true;
    else
        return false;
}
void infixToPostfix(char s[])
{
    char str[100]="",stck[50]="",str2[50]="";
    int num=1,x=0,index=0,index2=0;
    char p;
    printf("\n=============================================================================\n\n");
    printf("%-5s%-10s%-20s%-40s\n\n","Step","Symbol","Stack","Output");
    int i=0;
    while(i<strlen(s))
    {
        if(!isOperator(s[i]))
        {
            while(!isOperator(s[i])&&i+1<=strlen(s))
            {
                str2[index2++] = s[i++];
            }
            str2[index2++] = ' ';
            strcat(str,str2);
            x+=index2;
            printf("%-5d%-10s%-20s%-40s\n",num++,str2,stck,str);
            while(index2>0)
            {
                str2[index2--] = '\0';
            }
            str2[0] = '\0';
        }
        if(s[i] == '(')
        {
            push('(');
            stck[index++] = '(';
            stck[index++] = ' ';
            printf("%-5d%-10c%-20s%-40s\n",num++,s[i++],stck,str);
        }
        else if(s[i] == ')')
        {
            while(stacktop() != NULL && stacktop() != '(')
            {
                p = pop();
                str[x++] = p;
                str[x++] = ' ';
                stck[index--] = '\0';
                stck[index--] = '\0';
            }
            if(stacktop() == '(')
            {
                p = pop();
                stck[index--] = '\0';
                stck[index--] = '\0';
            }
            printf("%-5d%-10c%-20s%-40s\n",num++,s[i++],stck,str);
        }
        else
        {
            if(i<strlen(s))
            {
                if(stacktop() == NULL || (checkPriority(s[i]) > checkPriority(stacktop())))
                {
                    push(s[i]);
                    stck[index++] = s[i];
                    stck[index++] = ' ';
                }

                else
                {
                    while((stacktop() != NULL) && (checkPriority(s[i]) <= checkPriority(stacktop())))
                    {
                        p = pop();
                        str[x++] = p;
                        str[x++] = ' ';
                        stck[index--] = '\0';
                        stck[index--] = '\0';
                    }
                    push(s[i]);
                    stck[index++] = s[i];
                    stck[index++] = ' ';
                }
                printf("%-5d%-10c%-20s%-40s\n",num++,s[i++],stck,str);
            }
        }
    }
    while(stacktop() != NULL)
    {
        p = pop();
        str[x++] = p;
        str[x++] = ' ';
        stck[index--] = '\0';
        stck[index--] = '\0';
    }
    stck[index] = '\0';
    printf("%-5d%-10c%-20s%-40s\n\n",num++,' ',stck,str);
    printf("=============================================================================\n\n");
    printf("Postfix Equation : %s\n\n",str);
    printf("=============================================================================\n");
}


char checkString(char str[])
{
    for(int i=0 ; i<strlen(str) ; i++)
    {
        if(isalpha(str[i])||isdigit(str[i])) {}
        else if(isBasicOperator(str[i])) {}
        else
        {
            return str[i];
        }
    }
    return 'y';
}



int main()
{
    char infixString[100];
    //char ch[10000] = "A*(B+C^D)-E^F*(G/H)/A*(B+C^D)-E^F*(G/H)*A*(B+C^D)-E^F*(G/H)+A*(B+C^D)-E^F*(G/H)-A*(B+C^D)-E^F*(G/H)^A*(B+C^D)-E^F*(G/H)";
    //char ch[50] = "A-B*C/d^4+((E+F)-G*H)/Z";
    /*char f[5] = "3.2";
    float x = strtof(f,NULL);
    printf("%f\n",x);*/
    printf("============================= Infix to Postfix ==============================\n\n");
    printf("Enter an equation : ");
    gets(infixString);
    char c = checkString(infixString);
    if(c=='y')
        infixToPostfix(infixString);
    else
    {
        printf("%c not basic operand\n",c);
    }
    return 0;
}

