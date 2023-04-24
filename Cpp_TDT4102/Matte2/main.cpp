//------------------------------------------------------------------------------'
double trapez_method(double (*f)(double), double a, double b, int n);

// C++ programs start by executing the function main
int main() {
    // Show a nice message in the Terminal window
    

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------

double trapez_method(double (*f)(double), double a, double b, int n){
    double h = (b-a)/n;
    double sum = 0.5*(f(a)+f(b));
    for (int i=1; i<n; i++){
        sum += f(a+i*h);
    }
    return h*sum;
}



