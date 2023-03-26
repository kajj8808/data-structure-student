#include <stdio.h>
#include <stdbool.h>
#define MAX_DEGREE 20

typedef struct item
{
    int value;
    int degree;
} Item;

typedef struct polynomial
{
    Item items[MAX_DEGREE];
    int maxDegree;
} Polynomial;

/** 찾지못한다면 -1 을 찾는다면 찾은 위치의 index 를 반환해주는 함수 */
int findPolynomialDegree(Polynomial polynomial, int targetDegree)
{
    for (int i = 0; i <= polynomial.maxDegree; i++)
    {
        if (polynomial.items[i].degree == targetDegree)
        {
            return i;
        }
    }
    return -1;
}

Polynomial polynomialMultiplication(Polynomial p1, Polynomial p2)
{
    Polynomial result, temp;
    int cPos = 0;

    int maxDegree = p1.maxDegree > p2.maxDegree ? p1.maxDegree : p2.maxDegree;
    temp.maxDegree = maxDegree;
    result.maxDegree = maxDegree;
    while (true)
    {
        int p1DegreePos = findPolynomialDegree(p1, cPos);
        int p2DegreePos = findPolynomialDegree(p2, cPos);

        if (p1DegreePos != -1 && p2DegreePos != -1)
        {
            temp.items[cPos].degree = cPos;
            temp.items[cPos].value = p1.items[p1DegreePos].value * p2.items[p2DegreePos].value;
            cPos++;
            continue;
        }

        if (p1DegreePos != -1)
        {
            temp.items[cPos].degree = cPos;
            temp.items[cPos].value = p1.items[p1DegreePos].value;
            cPos++;
            continue;
        }

        if (p2DegreePos != -1)
        {
            temp.items[cPos].degree = cPos;
            temp.items[cPos].value = p2.items[p2DegreePos].value;
            cPos++;
            continue;
        }

        if (cPos <= maxDegree)
        {
            temp.items[cPos].value = -1;
            cPos++;
        }
        else
            break;
    }
    for (int i = maxDegree; i >= 0; i--)
    {
        result.items[i] = temp.items[maxDegree - i];
    }

    return result;
}

void printPol(Polynomial pol)
{
    for (int i = 0; i <= pol.maxDegree; i++)
    {
        if (pol.items[i].value <= 0 || pol.items[i].value == -1)
            continue;

        printf("%d^%d ", pol.items[i].value, pol.items[i].degree);
    }
    printf("\n");
}

void printPolynomialQustionAndResult(char *qustionTitle, Polynomial pol_1, Polynomial pol_2)
{
    printf("%s\n", qustionTitle);
    printPol(pol_1);
    printf("*\n");
    printPol(pol_2);
    printf("=\n");
    Polynomial resultPol = polynomialMultiplication(pol_1, pol_2);
    printPol(resultPol);
    printf("==========================================\n");
}

void Q1()
{
    Polynomial pol_1 = {
        .maxDegree = 3,
        .items = {
            {.degree = 3, .value = 4},
            {.degree = 2, .value = 3},
            {.degree = 1, .value = 2},
            {.degree = 0, .value = 1},
        },
    };

    Polynomial pol_2 = {
        .maxDegree = 2,
        .items = {
            {.degree = 2, .value = 3},
            {.degree = 1, .value = 2},
            {.degree = 0, .value = 8},
        },
    };

    printPolynomialQustionAndResult("1.", pol_1, pol_2);
}

void Q2()
{
    Polynomial pol_1 = {
        .maxDegree = 6,
        .items = {
            {.degree = 6, .value = 7},
            {.degree = 3, .value = 5},
            {.degree = 2, .value = 9},
            {.degree = 0, .value = 1},
        },
    };

    Polynomial pol_2 = {
        .maxDegree = 3,
        .items = {
            {.degree = 3, .value = 5},
            {.degree = 2, .value = 2},
            {.degree = 1, .value = 1},
            {.degree = 0, .value = 10},
        },
    };

    printPolynomialQustionAndResult("2.", pol_1, pol_2);
}

int main()
{
    Q1();
    Q2();
    getchar();
}