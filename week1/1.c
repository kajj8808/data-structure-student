#include <stdio.h>
// #include "myInclude" -> include 를 만들어 사용할떄는 이렇게 "" 으로 작성.
int sub(int a, int b)
{
    return a - b;
}

int main()
{
    int result = sub(5, 2);
    printf("%d\n", result);

    return 0;
}