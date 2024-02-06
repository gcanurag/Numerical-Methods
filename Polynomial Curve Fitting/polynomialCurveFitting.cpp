#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void printMatrix(float matrix[][50],int d)
{
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d + 1; j++)
        {
            cout << "M[" << i << "][" << j << "]=" << matrix[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    int n,d;
    cout << "Enter the degree of the curve";
    cin >> d;
    cout << "\n Enter the no of data items";
    cin >> n;
    float x[50], y[50], M[50][50], C[50];
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

    //code to generate the augmented matrix
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d + 1; j++)
        {
            float sum = 0;
            for (int k = 0; k <= n - 1; k++)
            {
                if(j==d+1){
                    sum += pow(x[i], i) * y[i];
                }else{
                    sum += pow(x[i], (i + j));
                }
            }
            M[i][j] = sum;
        }
    }
    // print augmented matrix;
    printMatrix(M, d);

    //diaginalizing the matrix
    for (int j = 0; j <= d; j++)
    {
        if(fabs(M[j][j])<=0.005)
        {
            cout << "Pivot is zero";
            exit ;
        }
        for (int i = 0; i <= d; i++)
        {
            if(i!=j)
            {
                float temp = M[i][j] / M[j][j];
                for (int k = 0; k <= d + 1; k++)
                {
                    M[i][k] = M[i][k] - temp * M[j][k];
                }
            }
        }
    }

    //print diagonalized matrix
    cout << "diaginalized matrix"<<endl;
    printMatrix(M, d);

    for (int i = 0; i <= d; i++)
    {
        C[i] = M[i][d + 1] / M[i][i];
        cout << "C" << i << "=" << C[i] << endl;
    }

        return 0;
}