#include <stdio.h>
#include <stdlib.h> // malloc

#define MAX_TERMS 100

typedef struct element
{
    int row;
    int col;
    int value;
} Element;

typedef struct sparesMatrix
{
    Element elements[MAX_TERMS];
    int rows;  // 행의 갯수
    int cols;  // 열의 갯수
    int terms; // 항의 갯수
} SparesMatrix;

SparesMatrix *matrixTranspose(SparesMatrix *originalMatrix)
{
    // 결과 marix / 임시 matrix 를 초기화 합니다.
    SparesMatrix *tempMatrix = (SparesMatrix *)malloc(sizeof(SparesMatrix));
    int index;

    // 임시 행렬을 초기화 합니다.
    tempMatrix->rows = originalMatrix->rows;
    tempMatrix->cols = originalMatrix->cols;
    tempMatrix->terms = originalMatrix->terms;
    // terms => 항의 갯수.
    // 항의 갯수가 0보다 클때 까지만 작동
    if (originalMatrix->terms > 0)
    {
        index = 0;
        // 행열의 위치를 바꾸는 반복문입니다.
        // original 열의 갯수만큼 반복합니다.
        for (int col = 0; col < originalMatrix->cols; col++)
        {
            // 행의 갯수만큼 반복합니다.
            for (int term = 0; term < originalMatrix->terms; term++)
            {
                // 같은것이 나오면 행열 위치를 바꿉니다.
                if (originalMatrix->elements[term].col == col)
                {
                    // 행열을 바꾸는 부분입니다.
                    tempMatrix->elements[index].row = originalMatrix->elements[term].col;
                    tempMatrix->elements[index].col = originalMatrix->elements[term].row;
                    tempMatrix->elements[index].value = originalMatrix->elements[term].value;
                    index++;
                }
            }
        }
    }
    // 행열의 위치가 바뀐 matrix를 return 합니다.
    return tempMatrix;
}

/** 행렬을 출력해주는 함수 */
void printMatrix(SparesMatrix *matrix)
{
    printf("(row col value)\n");
    for (int i = 0; i < matrix->terms; i++)
    {
        printf("%d %d %d\n", matrix->elements[i].row, matrix->elements[i].col, matrix->elements[i].value);
    }
}

int main()
{
    int rows, cols, temrs;
    printf("Enter the size of rows and columns. the number of non-zero terms : ");
    scanf("%d %d %d", &rows, &cols, &temrs);

    printf("Enter row, column, and value pairs in order: \n");
    SparesMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.terms = temrs;

    for (int i = 0; i < temrs; i++)
    {
        scanf("%d %d %d", &(matrix.elements[i].row), &(matrix.elements[i].col), &(matrix.elements[i].value));
    }

    SparesMatrix *resultMatrix = matrixTranspose(&matrix);
    printf("The transposed matrix is: \n");
    printMatrix(resultMatrix);
    printf("============================\n");
    free(resultMatrix);
    system("pause"); // console 창 꺼지지 않기위해 사용합니다.
}