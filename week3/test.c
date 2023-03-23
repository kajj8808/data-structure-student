#include <stdio.h>
// typedef키워드는 c 언어에서 자료행을 새롭게 만들고 싶을떄 사용.

struct person
{
    /* data */
    char name;
    int age;
    char favFood[5];
};

int main()
{
    int a = 20;
    int *b = &a;
    printf("%d\n", b);
}