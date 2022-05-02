#include <bits/stdc++.h>
#include <string>

typedef struct nd
{
    char c;
    struct nd *next;
} node[50];
node *top = NULL;

void *push(char ch)
{
    node *n = (node*)malloc(sizeof(node));
    n->next = top;
    top = n;
    n->c = ch;
}

char *pop()
{
    char p[50];
    node *n;
    n = top;
    top = top->next;
    for(int i = 0 ; i<strlen(n->c) ; i++){
        p[i] = n->c[i];
    }
    free(n);
    return p;
}
char stacktop()
{
    if(top == NULL )
        return NULL;
    else
        return top->c[strlen(top->c)];
}
int main()
{
    push("sdgrtgtdg");
    printf("%s",pop());
    return 0;
}
