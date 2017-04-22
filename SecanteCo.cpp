#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX_ITERACIONES 1000;

using namespace std;

double f(double x);
void secante(double x0, double x1, double tolerancia, double maxiteraciones);

int main()
{
    double x0,x1,tolerance;
    cout<< "Método de la secante";

    x0=-1;
     x1=0;

    tolerance=0.1;  //ERROR PARCIAL 2
    double max_iteraciones = MAX_ITERACIONES;
    secante(x0, x1, tolerance, max_iteraciones);
    cin.get();
    cin.get();
    cin.get();
    return 0;
}
double f(double x){
  return  (9*exp(-0.7*x)*cos(4*x))-3.5;

}
void secante(double x0,double x1, double tolerancia, double max_iteraciones){
    double xr;
    double error;  //ERROR PARCIAL2
    double porcentual;
    bool converge = true;
    int iteracion;
    iteracion = 1;
     cout << "Aproximacion inicial";

    do {
        if (iteracion > max_iteraciones){
            converge = false;
            break;
        }else {
            xr = x1 - ((f(x1)*(x0 - x1))/ (f(x0) - f(x1)));
            error = (fabs(xr - x1)/x1)*100;//error porcentual

            cout << "\a";

            cout << "\Iteracion #" << iteracion<< endl;
            cout << "\nx0" << iteracion << "   = " << x0 << "\n" << "x1" << iteracion << " = " << x1 << "\n" << "xr" << iteracion << " = " << xr<< "\n" << "error = " << error << endl;

        if(error<= tolerancia){//ERROR PARCIAL2
            converge = true;
            break;
        }else{
            x0 = x1;
            x1 = xr;

            iteracion++;
        }
    }
} while (1);

if(converge){
    cout << "\n\nPara una tolerancia de " << tolerancia << " la Raiz Aproximada de f es = " << xr << endl;

}else {
    cout << "\n\nSe sobrepasó la maxima cantidad de iteraciones permitodas " << endl;

}
}
