#include <iostream>
#include <cmath>

using namespace std;

// Function to be integrated
double function(double x)
{
    return /* Your function here */;
}

// Trapezoidal Rule
double trapezoidal(double a, double b, int n)
{
    double h = (b - a) / n;
    double result = 0.5 * (function(a) + function(b));

    for (int i = 1; i < n; ++i)
    {
        result += function(a + i * h);
    }

    return h * result;
}

// Simpson's 1/3 Rule
double simpsonsOneThird(double a, double b, int n)
{
    double h = (b - a) / n;
    double result = function(a) + function(b);

    for (int i = 1; i < n; i += 2)
    {
        result += 4 * function(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2)
    {
        result += 2 * function(a + i * h);
    }

    return h * result / 3.0;
}

// Simpson's 3/8 Rule
double simpsonsThreeEighth(double a, double b, int n)
{
    double h = (b - a) / n;
    double result = function(a) + function(b);

    for (int i = 1; i < n; i += 3)
    {
        result += 3 * (function(a + i * h) + function(a + (i + 1) * h));
    }

    for (int i = 3; i < n - 2; i += 3)
    {
        result += 2 * function(a + i * h);
    }

    return 3 * h * result / 8.0;
}

int main()
{
    // Define integration bounds and number of subintervals
    double a =  1;
    double b = 3;
    int n = 4;

    // Calculate integrals using different methods
    double trapezoidalResult = trapezoidal(a, b, n);
    double simpsonsOneThirdResult = simpsonsOneThird(a, b, n);
    double simpsonsThreeEighthResult = simpsonsThreeEighth(a, b, n);

    // Display results
    cout << "Trapezoidal Rule result: " << trapezoidalResult << endl;
    cout << "Simpson's 1/3 Rule result: " << simpsonsOneThirdResult << endl;
    cout << "Simpson's 3/8 Rule result: " << simpsonsThreeEighthResult << endl;

    return 0;
}
