#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 10

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == (MAX_STACK_SIZE - 1));
}

void push(element item)
{
    if (isFull())
    {
        fprintf(stderr, "stack 포화 에러 \n");
        return;
    }
    top++;
    stack[top] = item;
}

element pop()
{
    element resultElement;
    if (isEmpty())
    {
        fprintf(stderr, "stack 공백 에러 \n");
        return -1;
    }
    resultElement = stack[top];
    top--;
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 30; i++)
    {
        int ranNum = rand() % 100 + 1; // 1~100
        if (ranNum % 2 == 0)
        {
            push(ranNum);
        }
        else
        {
            element item = pop();
            if (item != -1)
            {
                printf("pop : %d\n", item);
            }
        }
    }
}