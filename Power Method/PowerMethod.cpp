#include <iostream>
#include <cmath>

using namespace std;

float findLargest(float matrix[], int n)
{
    float largest = matrix[1];
    for (int j = 1; j <= n; j++)
    {
        if (largest < abs(matrix[j]))
        {
            largest = matrix[j];
        }
    }

    return largest;
}

int main()
{
    float Dmax, Zmax;
    int n, count = 0;
    float D[50], a[50][50], z[50], x[50], y[50], d[50];

    cout << "Enter the order of matrix";
    cin >> n;
    cout << "\n Enter matrix";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "a"
                 << "[" << i << "][" << j << "]"
                 << "=" << endl;
            cin >> a[i][j];
        }
    }

    cout << "\n Enter the vector";
    for (int i = 1; i <= n; i++)
    {
        cout << "x[" << i << "]= ";
        cin >> x[i];
    }

    do
    {
        // performing a*x
        count++;
        if(count>=50){
            cout << "No convergence condition";
            exit(1);
        }
        for (int i = 1; i <= n; i++)
        {
            float sum = 0;
            for (int j = 1; j <= n; j++)
            {
                sum += a[i][j] * x[j];
            }
            z[i] = sum;
        }

        // finding the largest value of z;
        Zmax = findLargest(z, n);

        for (int k = 1; k <= n; k++)
        {
            y[k] = z[k] / Zmax;
            d[k] = abs(x[k] - y[k]);
            x[k] = y[k];
        }

        // finding the largest value of difference matrix;
        Dmax = findLargest(d, n);
    } while (Dmax > 0.005);

    float eigenValue = Zmax;
    cout << "Eigen value is" << Zmax << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << '\n';
    }

    return 0;
}