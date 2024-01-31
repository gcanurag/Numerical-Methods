#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float x[50], y[50];
    int n;
    float xp;
    cout << "Enter the degree of";
    cin >> n;
    
    for (int i = 0; i <= n - 1; i++)
    {
        cout << "x[" << i << "]= ";
        cin >> x[i];
    }

    for (int i = 0; i <= n - 1; i++)
    {

        cout << "y[" << i << "]= ";
        cin >> y[i];
    }

    cout << "Enter xp";
    cin >> xp;
    float sum = 0;

    for (int i = 0; i <= n - 1; i++)
    {
        float product = 1;

        for (int j = 0; j <= n - 1; j++)
        {
            if (i != j)
            {
                product *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        sum += product * y[i];
    }
    float yp = sum;

    cout << yp;

    return 0;
}