#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/** 소수인지 확인하는 함수. */
bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int result = 0;
    // 0부터 100
    for (int i = 0; i <= 100; i++)
    {
        // 소수인지 확인
        if (isPrime(i))
        {
            result += i;
        }
    }

    printf("%d\n", result);
}