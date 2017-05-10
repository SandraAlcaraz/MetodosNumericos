// Description: Integral Simpson 1/3 Rule

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double simpsonIntegralOneThird(double a, double b, double *y, int intervals, int extraIntervals) {
    double h = (b-a)/(intervals);
    double simpsonB = 0;
    int index = intervals - extraIntervals;
    if(extraIntervals > 0 ) {
        simpsonB = b-h;
    }
    else {
        simpsonB = b;
    }
    double integral, preIntegral, extraIntegral;
    integral = preIntegral = extraIntegral = 0;

    for(int i = 1; i < index; i += 2) {
        preIntegral += 4*y[i];
    }

    for(int i = 2; i < index -1; i += 2) {
        preIntegral += 2*y[i];
    }

    integral = (h/3)*(y[0] + preIntegral + y[index]);
    cout << "Integral from " << a << " to " << simpsonB << " = " << integral << endl;

    if(extraIntervals > 0) {
        extraIntegral = (y[index]+y[intervals])*(b-simpsonB)/2;
        cout << "Integral from " << simpsonB << " to " << b << " (Using trapezium) = " << extraIntegral << endl;
    }



    return integral + extraIntegral;
}

int main() {

    int l, numberIntervals, numberSimpsonIntervals, extraIntervals;
    l = numberIntervals = numberSimpsonIntervals, extraIntervals = 0;
    double integral, realIntegral, a, b;
    integral = realIntegral = a = b = 0;

    cout << "Write the number of coordinates ";
    cin >> l;

    cout << "Initial integral limit a = ";
    cin >> a;
    cout << "Final integral limit b = ";
    cin >> b;

    cout << "The coordinates y are read y.txt" << endl;

    numberIntervals = l-1;
    numberSimpsonIntervals = numberIntervals/2;
    extraIntervals = numberIntervals%2;

    cout << "Number of regular intervals: " << numberIntervals << endl;
    cout << "Number of intervals to use Simpson 1/3: " << numberSimpsonIntervals << endl;
    cout << "Number of intervals where trapezoid integral will be used (Last): " << extraIntervals << endl;


    double y[l];

    ifstream myY("i.txt");

    for(int i = 0; i < l && myY; i++) {
        myY >> y[i];
    }

    myY.close();

    integral = simpsonIntegralOneThird(a, b, y, numberIntervals, extraIntervals);

    cout << "Integral = " << integral << endl;

}
