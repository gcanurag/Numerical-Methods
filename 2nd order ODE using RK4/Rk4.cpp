#include<iostream>
using namespace std;

float f(float x, float y, float z)
{
    return z;
}

float g(float x, float y, float z){
    return y-3*z;
}

float Rk4(float x ,float y, float z, float h, float xn){
    while(x<xn){
        float k1 = h * f(x, y, z);
        float l1 = h * g(x, y, z);
        float k2 = h * f(x + h / 2, y + k1 / 2, z + l1 / 2);
        float l2 = h * g(x + h / 2, y + k1 / 2, z + l1 / 2);
        float k3 = h * f(x + h / 2, y + k2 / 2, z + l2 / 2);
        float l3 = h * g(x + h / 2, y + k2 / 2, z + l2 / 2);
        float k4 = h * f(x + h, y + k3, z + l3);
        float l4 = h * g(x + h, y + k3, z + l3);
        float k = (k1 + 2 * (k2 + k3) + k4) / 6;
        float l = (l1 + 2 * (l2 + l3) + l4) / 6;
        x += h;
        y += k;
        z += l;
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }
    cout << "The solution  is y= " << y;
    cout << "\n The solution of y' is y' =" <<z;
}


int main(){
    float y = Rk4(0,0,0.5,0.1,0.1);
   
    return 0;

}