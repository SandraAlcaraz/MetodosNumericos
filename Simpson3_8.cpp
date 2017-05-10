
// Description: Integral Simpson 3/8 Rule

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double simpsonIntegralThreeOcts(double a, double b, double *y) {
    double integral = (y[0] + 3*y[1] + 3*y[2] + y[3])*(b-1)/8;

    return integral;
}

int main() {

    int l, numberIntervals;
    l = numberIntervals = 0;
    double integral, realIntegral, a, b;
    integral = realIntegral = 0;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    double y[4];

    for(int i = 0; i < 4; i++) {
        cout << "y" << i << " = ";
        cin >> y[i];
    }

    integral = simpsonIntegralThreeOcts(a, b, y);

    cout << "Integral = " << integral << endl;

}
