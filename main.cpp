#include <iostream>
#include <math.h>

using namespace std;

//Искомая функция
double J(double x){
    return x*x+2*x;
}

//Метод золотого сечения
double *zolot(double a, double b, double eps){
    double delta=eps/2,u1,u2,min_x;
    static double res[2];
    int i=0;
    while (fabs(b-a) > eps){
        u1 = a + (3-sqrt(5))*(b-a)/2;
        u2 = a + (sqrt(5) - 1)*(b-a)/2;
        if (J(u1) <= J(u2)){
            b = u2;
            min_x = u1;
        } else {
            a = u1;
            min_x = u2;
        }
        i++;
    };
    res[0] = i;
    res[1] = min_x;
    return res;
}

//Метод дихотомии
double *dychotomy(double a, double b, double eps){
    double delta=eps/2,u1,u2, min_x;
    static double res[2];
    int i=0;
    while (fabs(b - a) > eps){
        u1 = (a+b-delta)/2;
        u2 = (a+b+delta)/2;
        if (J(u1) <= J(u2)){
            b = u2;
            min_x = u1;
        } else {
            a = u1;
            min_x = u2;
        };
        i++;
    };
    res[0] = i;
    res[1] = min_x;
    return res;
}

int main()
{
    double a = -5, b = 5, eps = 1e-10;
    double *arr;
	
    printf("eps=%g\r\n[%g;%g]\r\n\r\n", eps, a, b);

    arr = zolot(a, b, eps);
    printf("zolot\r\ni=%g;min_x=%g\n", arr[0], arr[1]);

    arr = dychotomy(a, b, eps);
    printf("\r\ndychotomy\r\ni=%g;min_x=%g\n", arr[0], arr[1]);

    return 0;
}

