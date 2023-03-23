#include <stdio.h>

#define MAX_TERMS 100

typedef struct
{
    /* data */
    int row;   // 행의 개수
    int col;   // 열의 개수
    int value; // 0이 아닌 항의 개수
} element;

int main()
{
    // rows , cols , num 의 입력을 받습니다.
    int rows, cols, num;
    printf("행과 열의 크기, 0이 아닌 항의 숫자를 입력하세요: ");
    scanf("%d %d %d", &rows, &cols, &num);

    // 행렬을 동적으로 받습니다.
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)calloc(cols, sizeof(int));
    }

    // 메모리 해제
}
