#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    float x[5] = {1, 2, 3, 4, 5};
    float Y[5] = {2, 4, 5, 4, 5};
    float a, A;
    float b;
    n = 5;
    
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += Y[i];
        sumXY += x[i] * Y[i];
        sumX2 += x[i] * x[i];
    }

    float D = n * sumX2 - sumX * sumX;
    float D1 = sumY * sumX2 - sumX * sumXY;
    float D2 = n * sumXY - sumX * sumY;
    if (D != 0)
    {
        A = D1 / D;
        b = D2 / D;
        a = exp(A);
    }
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}