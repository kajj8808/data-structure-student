#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 10

typedef struct
{
    /* data */
    short r;
    short c;
} mazeElement;

// 스택 /////////////////////////
typedef struct
{
    mazeElement* data;
    int capacity;
    int top;
} StackType;

StackType* create(int size)
{
    StackType* sp; // stack pointer
    sp = malloc(sizeof(StackType));
    sp->capacity = size;
    sp->data = malloc(size * sizeof(mazeElement));
    sp->top = -1;
    return sp;
}

int isFull(StackType* sp)
{
    return (sp->top == (sp->capacity - 1));
}

void push(StackType* sp, mazeElement item)
{
    if (isFull(sp))
    {
        sp->capacity *= 2; // 배열의 길이
        sp->data = (mazeElement*)realloc(sp->data, sp->capacity * sizeof(mazeElement));
    }
    sp->top++;
    sp->data[sp->top] = item;
}

int isEmpty(StackType* sp)
{
    return (sp->top == -1);
}

mazeElement pop(StackType* sp)
{
    /* if (isEmpty(sp)) // main 코드에서 처리를 해주기에 주석!
    {
        fprintf(stderr, "stack 공백 에러 \n");
        return -1;
    } */
    mazeElement result = sp->data[sp->top];
    sp->top--;
    return result;
}

/////////////////////////////////
// 미로 /////////////////////////

mazeElement here = { 1, 0 }, entry = { 1, 0 };
int notPushCount = 0;
bool isPushed = false;

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'e', '1', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'0', '1', '0', '0', '0', '1', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '1', '1', '0', '1', '1', '0', '1'},
    {'1', '1', '0', '0', '0', '0', '0', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void pushLoc(StackType* stack, int row, int column)
{
    if (row < 0 || column < 0)
        return;
    // 막혀있거나 이미 지나온 길이 아니라면 push!
    if (maze[row][column] != '1' && maze[row][column] != '.')
    {
        mazeElement temp;
        temp.r = row;
        temp.c = column;
        push(stack, temp);
        isPushed = true;
    }
    return;
}

// 미로를 프린트합니다.
void mazePrint(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    for (int row = 0; row < MAZE_SIZE; row++)
    {
        for (int column = 0; column < MAZE_SIZE; column++)
        {
            printf("%c ", maze[row][column]);
        }
        printf("\n");
    }
}

int main()
{
    int row, column;
    StackType* stack = create(MAX_STACK_SIZE);
    here = entry;
    // 출구 까지
    while (maze[here.r][here.c] != 'x')
    {
        /* code */
        row = here.r;
        column = here.c;
        maze[row][column] = '.'; // 이미 지나온 곳은 . 으로 표기합니다.
        mazePrint(maze);
        pushLoc(stack, row - 1, column);
        pushLoc(stack, row + 1, column);
        pushLoc(stack, row, column - 1);
        pushLoc(stack, row, column + 1);

        if (!isPushed) // push 되지 않앗나. 즉 더이상 움직일수 없엇던 경우!
        {
            notPushCount++;
        }
        else
        {
            isPushed = false; // 정상적으로 push 막힘없이 길을 찾앗을경우 다시 push되었나를 확인하기위해 사용합니다.
        }

        if (isEmpty(stack))
        {
            printf("이 미로에는 나가는 곳이 없습니다.\n");
            return 0;
        }
        here = pop(stack);
    }
    printf("미로를 성공적으로 나갔습니다!\n");
    printf("더이상 움직일수 없엇던 경우: %d\n", notPushCount);
    return 0;
}
