#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int size_of_row;

void print_square_matrix(double **A, double sol_vector[], int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << A[i][j] << "\t";
    }
    cout << "=\t" << sol_vector[i];
    cout << endl;
  }
}

void forward_elimination(double **A, double sol_vector[], int n) {
  double factor;
  for(int k = 0; k < n; k++) {
    for(int i = k+1; i < n; i++) {
        factor = A[i][k]/A[k][k];
        for(int j = k; j < n; j++) {
          A[i][j] = A[i][j] - factor*A[k][j];
        }
        sol_vector[i] = sol_vector[i] - factor*sol_vector[k];
      }
  }
}

void back_substitution(double **A, double sol_vector[], int n, double solution[]) {
  double sum;
  solution[n-1] = sol_vector[n-1]/A[n-1][n-1];
  for(int i = n-2; i >= 0; i--) {
    sum = 0;
    for(int j = i+1; j < n; j++) {
      sum = sum + A[i][j] * solution[j];
    }
    solution[i] = ( sol_vector[i] - sum ) / A[i][i];
  }
}

void print_poly(double v[], int n) {
  for(int i = 0; i < n; i++){
    cout << v[i];
    if(i != 0){
      cout << "*x^" << i;
    }
    if(i != n-1)
      cout << " + ";
  }
  cout << endl;
}

void print_vector(double v[], int n) {
  for(int i = 0; i < n; i++){
    cout << "a" << i << " = " << v[i];
    cout << endl;
  }
  cout << endl;
}

void polynomial_regression(double x[], double y[], const int degree, const int n) {
  double sum_x = 0, sum_xy = 0;
  size_of_row = degree + 1;
  double sol_vector[size_of_row];
  double **linear_equations;

  linear_equations = new double*[size_of_row];
  for(int i = 0; i < size_of_row; i++){
    linear_equations[i] = new double[size_of_row];
  }

  cout << "\nConstructing system of linear equations ..." << endl << "------------------------------------------" << endl;
  for(int i = 0; i < size_of_row; i++) {
    sum_xy = 0;

    for(int j = 0; j < n; j++)
      sum_xy += pow(x[j],i)*y[j];
    sol_vector[i] = sum_xy;

    for (int j = 0; j < size_of_row; j++) {
      sum_x = 0;
      if (i == 0 && j == 0)
        linear_equations[i][j] = n;
      else {
        //Calculate the sum of x to a certain power.
        for (int h = 0; h < n; h++)
          sum_x += pow(x[h],(j+i));
        linear_equations[i][j] = sum_x;
      }
    }
  }
  for(int i = 0; i < size_of_row; i++) {
    for(int j = 0; j < size_of_row; j++)
      cout << linear_equations[i][j] << "\t";
    cout << "=\t" << sol_vector[i];
    cout << endl;
  }
  cout << endl;

  double sum_y = sol_vector[0];

  cout << "\nGauss to get [a0...an] ..." << endl << "------------------------------------------" << endl;
  forward_elimination(linear_equations, sol_vector, size_of_row);
  print_square_matrix(linear_equations, sol_vector, size_of_row);

  double x_vector[size_of_row];

  back_substitution(linear_equations, sol_vector, size_of_row, x_vector);
  print_vector(x_vector, size_of_row);

  cout << "\nPolynomial ..." << endl << "------------------------------------------" << endl;
  print_poly(x_vector, size_of_row);

  cout << "\nErrors ..." << endl << "------------------------------------------" << endl;
	double e[n];
	for (int i = 0; i < n; i++) {
		double y_calculada = 0;
		for (int j = size_of_row - 1; j >= 1; j--)
			y_calculada += x_vector[j]*( pow( x[i], j ) );
		y_calculada += x_vector[0];
		e[i] = pow(y[i] - y_calculada,2);
	}

	double sr = 0;
	double st = 0;
	for (int i = 0; i < n; i++) {
		sr += e[i];
		st += pow(y[i] - (sum_y/n),2);
	}
	cout << "Sr = " << sr << endl;

	double syx = sqrt(sr/(n - size_of_row));
	cout << "St = " << st << endl;

	double r2 = (st-sr)/st;
	double r = sqrt(r2);
	cout << "Error Estandar (S y/x): " << syx << endl;
	cout << "Coeficiente de determinacion (r2): " << r2 << endl;
	cout << "Coeficiente de correlacion (r): " << r << endl;
	cout << endl;

}

int main() {
  int n, degree;
  cout << "n: ";
  cin >> n;
  cout << "degree: ";
  cin >> degree;

  ifstream inx("x.txt");
  ifstream iny("y.txt");

  if(!inx || !iny){
    cout << "Error" << endl;
  }

  double X[n], Y[n];

  cout << "\n  x\t  y" << endl << "-------------" << endl;
  for(int i = 0; inx && iny && i < n; i++) {
    inx >> X[i];
    iny >> Y[i];

    cout << X[i] << "\t" << Y[i] << endl;
  }

  inx.close();
  iny.close();

  polynomial_regression(X,Y,degree,n);

  return 0;
}

//Error estandar de estimación Sy/x = sqrt(sr/(n-(m+1)))
//r^2 = (st-sr)/st