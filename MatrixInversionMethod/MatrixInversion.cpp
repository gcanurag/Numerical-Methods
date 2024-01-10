#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of square matrix ";
    cin >> n;

    float a[n + 1][2 * n + 1];
    float x[n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j > n)
            {
                if (j == i + n)
                {
                    a[i][j] = 1;
                }
                else
                {
                    a[i][j] = 0;
                }
            }
            else
            {
                // cout << "a[" << i << "][" << j << "]= ";
                cin >> a[i][j];
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= 2 * n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i != j)
            {
                float t = a[i][j] / a[j][j];
                for (int k = 1; k <= 2 * n; k++)
                {
                    a[i][k] = a[i][k] - t * a[j][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        float t = a[i][i];
        for (int j = 1; j <= 2 * n; j++)
        {
            a[i][j] /= t;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}