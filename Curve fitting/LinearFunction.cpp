#include<iostream>
using namespace std;


int main()
{
    int n;
    float x[10] = {0.2, 0.4, 0.6, 0.7, 1, 1.2, 1.4, 1.6, 1.8, 2};
    float y[10] = {4, 5, 6, 7, 8, 9, 10, 11, 11.5, 13};
    float a;
    float b;
    n = 10;
    
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    float D = n * sumX2 - sumX * sumX;
    float D1 = sumY * sumX2 - sumX * sumXY;
    float D2 = n * sumXY - sumX * sumY;
    if(D!=0){
        a = D1 / D;
        b = D2 / D;
    }
    cout << "a = " << a << " b = " << b << endl;

    return  0;
}