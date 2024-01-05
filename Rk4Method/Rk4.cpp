#include<iostream>
#include<cmath>
using namespace std;

float f(int x, int y) // f=dy/dx
{
    return x+y;
}

float Rk4(float x, float y, float h, float xn){
   while(x<xn){
       float k1 = h * f(x, y);
       float k2 = h * f(x + h / 2, y + k1 / 2);
       float k3 = h * f(x + h / 2, y + k2 / 2);
       float k4 = h * f(x + h, y + k3);
       float k = (k1 + 2*k2 + 2*k3 + k4) / 6;
       y =y+ k;
       x =x+ h;
       cout << "(" << x << "," << y << ")" << endl;
   }
   return y;
}
int main(){
    float y = Rk4(0, 1, 0.2, 1);
    cout << "The solution of dy/dx=x+y is y= " << y;
    return 0;
}