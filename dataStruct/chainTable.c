
/*
    单链表实现
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int length;
    struct Node *next;
} * Table, T;

//init
Table init_chainTable()
{
    Table H = (Table)malloc(sizeof(T));
    if(H == NULL)
    {
        perror("malloc error");
        exit(-1);
    }
    H->next = NULL;
    H->length = -1;
    

    return H;
}

//insert 头插法
void insert_linkList(Table H, int data)
{
    Table newNode = (Table)malloc(sizeof(T));
    if(newNode == NULL)
    {
        perror("newNode malloc error");
        return ;
    }
    newNode->data = data;
    newNode->next = H->next;
    H->next = newNode;
    H->length++;
}

//迭代反转链表
void iteration_reverse_linkList(Table H)
{
    Table begin = NULL;
    Table mid = H;
    Table end = H->next;
    
}

void show(Table H)
{
    Table pH = H->next;
    while(pH)
    {
        printf("%d ", pH->data);
        pH = pH->next;
    }

    puts("");
    
}

void test()
{
    Table H = init_chainTable();
    int i = 0;
    for (i = 0; i < 5;i++)
    {
        insert_linkList(H, i);
    }
    show(H);
}

int main()
{
    test();

    return 0;
}