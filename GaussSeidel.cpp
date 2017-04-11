
#include <iostream>
#include <cmath>
using namespace std;
//despeja las variables en las ecuaciones que te den

double fx(double y, double z) {
    return (14+(4*y)+(3*z))/8;

}

double fy(double x, double z) {
    return (-1-(2*x)-(3*z))/-5;

}

double fz(double x, double y) {
    return (9+(3*x)-y)/9;
}

int main() {

    double x, y, z;
    double error = pow(10, -6);
    int i;
    x = y = z = 0.0;
    i=0;

    do {

        x = fx(y, z);
        y = fy(x, z);
        z = fz(x, y);
        i++;
        cout << x << " | " << y << " | " << z << " | " << i << endl;
    }
    while(abs(8*x -4*y - 3*z - 14)>error || abs(2*x - 5*y + 3*z  +1)>error || abs(-3*x + y +9*z - 9)>error);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "i = " << i << endl;

}
