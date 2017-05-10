// LagrangeNewtonPolynomial.cc: Miguel Montoya
// Description: LagrangeNewton Polynomial Interpolation
/*
f(x)= (((x-x1)(x-x2))/((x0-x1)(x0-x2)))*f(x0)+ (((x-x0)(x-x2))/((x1-x0)(x1-x2)))*f(x1)+ (((x-x0)(x-x1))/((x2-x0)(x2-x1)))*f(x2);
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double NewtonInterpolation(double xAprox, int l, double* x, double* y) {

    double yAprox = 0;

    for(int i = 0; i < l; i++) {
        double aproxIt = y[i];
        for(int j = 0; j < l; j++) {
            if(j == i) {
                continue;
            }
            aproxIt *= (xAprox-x[j])/(x[i]-x[j]);
        }
        yAprox += aproxIt;
    }

    return yAprox;
}

int main() {

    double xAprox, yAprox;
    int l;

    cout << "Write the number of coordinates ";
    cin >> l;

    cout << "Write the x to aproximate y: ";
    cin >> xAprox;

    double x[l];
    double y[l];

    ifstream myX("x.txt");
    ifstream myY("y.txt");

    for(int i = 0; i < l && myX && myY; i++) {
        myX >> x[i];
        myY >> y[i];
    }

    myX.close();
    myY.close();

    yAprox = NewtonInterpolation(xAprox, l, x, y);

    cout << "f(x) = " << yAprox;

}
