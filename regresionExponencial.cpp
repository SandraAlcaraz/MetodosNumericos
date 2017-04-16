#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {

 
    double x, y, xy, xsq, avy, xMes, yMes, yPros, sr, st, n, i, a1, a0;
    x = y = xy = xsq = avy = xMes = yMes = yPros = i = 0;
    cout << "Write n: ";
    cin >> n;

    ifstream myX("xx.txt");
    ifstream myY("yy.txt");

    // Loop to get a0 and a1
    for(i; myX && myY && i < n; i++) {
        double tx, ty;
        myX >> tx;
        myY >> ty;
        cout << tx << " | " << ty << endl;
        x += tx;
        y += log(ty);
        xy += tx*log(ty);
        xsq += pow(tx, 2);

    }


    myX.close();
    myY.close();

    // Get alpha (a0) and beta (a1)
    a1 = (n*xy - x*y)/(n*xsq - pow(x, 2));
    avy = y/n;
    a0 = exp(avy - a1*(x/n));

    ifstream myErrX("x.txt");
    ifstream myErrY("y.txt");

    // Loop to get errors
    for(int i = 0; i < n; i++) {
        myErrY >> yMes;
        myErrX >> xMes;
        yPros = a0*exp(a1*xMes);
        sr += pow(yMes - yPros, 2);
        st += pow(yMes - avy, 2);
    }

    myErrX.close();
    myErrY.close();

    // Get Std. Error and Correlation Coef (r)
    double stdError = sqrt(sr/(n-2));
    double r = sqrt((st-sr)/st);

    cout << "beta = " << a1 << "\t teta = " << a0 << endl;
    cout << "funcion es igual a teta * e^(beta * x)";
    cout << "Std. Error = " << stdError << "\tCorrelation Coefficient = " << r << endl;

}
