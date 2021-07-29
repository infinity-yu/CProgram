#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct Seq
{
    int arr[SIZE];
    int length;
} * S, seq;

//init
S seq_init()
{
    static seq s;
    memset(&s, 0, sizeof(s));
    // s->length = 0;
    return &s;
}

//insert
void seq_insert(S s, int pos, int data)
{
    if (s->length == SIZE || pos < 0 || pos > s->length)
        return;
    int i = 0;
    for (i = s->length; i > pos; i--)
    {
        s->arr[i] = s->arr[i - 1];
    }
    s->arr[pos] = data;
    s->length++;
}

//delete
void seq_del(S s, int pos, int *data)
{
    // printf("pos:[%d], len:[%d]\n", pos, s->length);
    if (pos >= s->length || pos < 0 || s->length == 0)
    {
        printf("pos is illegal or seqList is empty\n");
        return;
    }

    *data = s->arr[pos];
    while (pos < s->length - 1)
    {
        s->arr[pos] = s->arr[pos + 1];
        pos++;
    }
    s->length--;
}

//modify
void seq_modify(S s, int pos, int data)
{
    if (pos >= s->length || pos < 0 || s->length == 0)
        return;

    s->arr[pos] = data;
}

//query
void seq_query(const S s, int data)
{
    if (s->length == 0)
        return;

    int i = 0;
    for (i = 0; i < s->length; i++)
    {
        if (s->arr[i] == data)
        {
            printf("[%d] is located in [%d]\n", data, i);
            return;
        }
    }
    printf("[%d] is not in this seqlist\n", data);
}

//show
void show(const S s)
{
    int *p = s->arr;
    int len = s->length;
    while (len--)
    {
        printf("%d ", *p++);
    }
    puts("");
}

//test
void test()
{
    S s = seq_init();
    // printf("length:[%d]\n", s->length);

    srand(time(NULL));
    int i = 0;
    int pos = 0;
    puts("---------insert");
    for (i = 0; i < 5; i++)
    {
        pos = rand() % (i + 1);
        // printf("----%d\n", pos);
        seq_insert(s, pos, i);
    }

    show(s);

    puts("--------del");
    int data;
    // printf("length:[%d]\n", s->length);
    i = rand() % 4;
    seq_del(s, i, &data);
    show(s);
    printf("\ni:[%d], data:[%d]\n", i, data);

    puts("-------modify");
    seq_modify(s, rand() % 3, rand() % 10 + 1);
    show(s);

    puts("-----query");
    seq_query(s, rand() % 5 + 1);
}

int main()
{
    test();

    return 0;
}
