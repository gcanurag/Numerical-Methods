#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no of unknown variables" << endl;
    cin >> n;
    float a[n+1][n + 2];
    float x[n+1];

    // reding the matrix;
    cout << "Enter the elements of augmented matrix" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cout << "a"
                 << "[" << i << "][" << j << "]"
                 << "=" << endl;
            cin >> a[i][j];
        }
    }

    // diagnolizing the matrix;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i != j)
            {
                float t = a[i][j] / a[j][j];
                for (int k = 1; k <= n + 1; k++)
                {
                    a[i][k] = a[i][k] - t * a[j][k];
                }
            }
        }
    }

    // optional   -> print the diagonalized matrix;
    cout << "The diagonalized matrix is" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cout << "a[" << i << "][" << j << "]=" << a[i][j] << endl;
        }
    }

    // calculating the value of variables;2
    cout << "The soluions are" << endl;
    for (int i = 1; i <= n;i++){
        x[i] = a[i][n + 1] / a[i][i];
        cout << "x" << i << "=" << x[i] << endl;
    }

    return 0;
}