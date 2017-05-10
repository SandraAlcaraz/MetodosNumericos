#include <iostream>
#include <cmath>
//Riemman
using namespace std;

double real = 9;//Variable que refleja el valor real la integral evaluada.

double funcion(double x) { //Método que evalúa la función en un valor de x.
 return  pow(x-1,2)+2; //PONER FUNCION A EVALUAR
}

double error(double res) { //Método que obtiene el error con base en el valor real.
 return abs((real - res) / real) * 100;
}

void RiemannDerecha(double a, double b, int n) { //Sumas de Riemann por la derecha.

 double h = (b - a) / n; //Calcula el área, inicializa la variable de la respuesta.
 double res = 0.0;

 for (double i = a + h; i <= b; i+=h) { //Empieza a sumar desde la esquina derecha del primer rectángulo.
 res += funcion(i)*h;
 }

 cout << "Area aproximada: " << res << endl; //Despliega resultados.
 cout << "Error: " << error(res) << endl;
}

void RiemannIzquierda(double a, double b, int n) {

 double h = (b - a) / n; //Calcula el área, inicializa la variable de la respuesta.
 double res = 0.0;

 for (double i = a; i + h <= b; i += h) { //Empieza a sumar desde la esquina izquierda del primer rectángulo.
 res += funcion(i)*h;
 }

 cout << "Area aproximada: " << res << endl; //Despliega resultados.
 cout << "Error: " << error(res) << endl;

}

int main() {
 RiemannDerecha(-1, 2, 100);//PARAMETROS UNO Y DOS SON LIMITES A,B Y EL TERCER PARAMETRO NUM DE RECTANGULOS
 RiemannIzquierda(-1, 2, 100);

 return 0;
}
