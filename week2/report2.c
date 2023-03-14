#include <stdio.h>
double factorialIter(int num)
{
    double k, v = 1;
    for (k = num; k > 0; k--)
    {
        v = v * k;
    }
    return v;
}
double factorialRec(int num)
{
    if (num <= 1)
        return 1;
    return num * factorialIter(num - 1);
}
int main()
{
    int n = 20;
    double resultIter = factorialIter(n);
    double resultRec = factorialRec(n);
    printf("Iter Result : %.1f\n", resultIter);
    printf("Rec Result : %.1f", resultRec);
}