#include <iostream>
#include <cmath>
using namespace std;

float f(int x, int y)     //f=dy/dx
{
    return x - y;
}

float Eulers(float x, float y, float h, float xn)
{
    while (x < xn)
    {
        y = y + h * f(x, y);
        x = x + h;
        cout << "(" << x << "," << y << ")" << endl;
    }
    return y;
}
int main()
{   
    float y = Eulers(0, 1, 0.2, 1);
    cout << "The solution of dy/dx=x-y at x=1 is y= " << y;
    return 0;
}