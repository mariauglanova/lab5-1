#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double integral = 0.7468241328124;

int factorial(int n) {
    return (n < 2) ? 1 : factorial(n - 1) * n;
}

double get_series(double x, double eps=5e-5) {
    double result = 1;
    int n = 1;
    double temp;
    do {
        temp = pow(-1, n)*pow(x, 2*n)/factorial(n);
        result += temp;
        n++;
    } while(abs(temp) >= eps);
    return result;
}

double rectangle_left(double a, double b, double h){
    double result = 0;
    int i = 0;
    for(double x = a; x < b - h; x = a + i*h) {
       result += h*get_series(x);
       i++;
    }
    return result;
}

double trapezoidal_rule(double a, double b, double h){
    double result = h*0.5*(a + b);
    int i = 0;
    for(double x = a+h; x < b-h; x = a + h + i*h){
        result += h*get_series(x);
        i++;
    }
    return result;
}

int main() {
    double h = 5e-5;

    double result = rectangle_left(0, 1, h);

    double error = abs(integral - result);
    ofstream outf;
    outf.open("ans1.dat", ios_base::out);
    outf << result << " " << error << endl; 
    outf.close();

    h = 1e-5;
    result = trapezoidal_rule(0, 1, h);

    error = abs(integral - result);

    outf.open("ans2.dat", ios_base::out);
    outf << result << " " << error << endl; 
    outf.close();
    return 0;
}
