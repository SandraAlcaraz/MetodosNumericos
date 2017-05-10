#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f( double x){
   //return  400*pow(x,5)-900*pow(x,4)+675*pow(x,3)-200*pow(x,2)+25*x+0.2;

   return exp(pow(x,2));
}

double trapecio(double div, double  interI, int n){
    double sum=0;

    for(int i=0; i<n;i++){

      sum+=( (f(interI)+f(interI+div))*(div))/2;
       interI+=div;
    }
    return sum;
}


int main(){
   //definamos n
   int n=2;
//intervalos
    double inte1=0;
    double inte2=1;
    //factor de n
    double divN=abs(inte2-inte1)/n;

    double area= trapecio(divN,inte1, n);

    cout << "f(x) = " << area;

}

