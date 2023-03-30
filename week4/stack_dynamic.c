#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 10

typedef int element;

typedef struct
{
    element *data;
    int capacity;
    int top;
} StackType;

StackType *create(int size)
{
    StackType *sp; // stack pointer
    sp = malloc(sizeof(StackType));
    sp->top = -1;
    return sp;
}

int isFull(StackType *sp)
{
    return (sp->top == (sp->capacity - 1));
}

void push(StackType *sp, element item)
{
    if (isFull(sp))
    {
        sp->capacity *= 2; // 배열의 길이
        sp->data = (element *)realloc(sp->data, sp->capacity * sizeof(element));
    }
    sp->top++;
    sp->data[sp->top] = item;
}

int isEmpty(StackType *sp)
{
    return (sp->top == -1);
}

element pop(StackType *sp)
{
    if (isEmpty(sp))
    {
        fprintf(stderr, "stack 공백 에러 \n");
        return -1;
    }
    element result = sp->data[sp->top];
    sp->top--;
    return result;
}

int main()
{
    srand(time(NULL));

    StackType *stack = create(MAX_STACK_SIZE);

    for (int i = 0; i < 30; i++)
    {
        int ranNum = rand() % 100 + 1; // 1~100
        if (ranNum % 2 == 0)
        {
            push(stack, ranNum);
        }
        else
        {
            element item = pop(stack);
            if (item != -1)
            {
                printf("pop : %d\n", item);
            }
        }
    }
}