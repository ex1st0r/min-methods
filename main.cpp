#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

double func(double x){
    return x*x+2*x;
}

double *gold_ratio(double (*J)(double),double a, double b, double eps){
    double delta=eps/2,u1,u2,min_x,J1,J2;
    double *res = new double[2];
    int i=0;

    u1 = a + (3-sqrt(5))*(b-a)/2;
    u2 = a + (sqrt(5) - 1)*(b-a)/2;
    J1 = J(u1);
    J2 = J(u2);

    while (fabs(b-a) > eps){
        if (J1 <= J2){
            b = u2;
            u2 = u1;
            J2 = J1;
            u1 = a + (3 - sqrt(5))*(b-a)/2;
            J1 = J(u1);
        } else {
            a = u1;
            u1 = u2;
            J1 = J2;
            u2 = a + (sqrt(5) - 1)*(b-a)/2;
            J2 = J(u2);
        }
        i++;
    };
    res[0] = i;
    res[1] = (u1+u2)/2;
    return res;
}

double *dychotomy(double (*J)(double), double a, double b, double eps){
    double delta=eps/2,u1,u2, min_x;
    double *res = new double[2];
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
    res[0] = i * 2; //Количество вычислений функций
    res[1] = min_x;
    return res;
}

int main()
{
    double a = -7, b = 4, eps = 1e-10;
    double *arr;

    arr = gold_ratio(func, a, b, eps);
    printf("zolot\r\ni=%g;min_x=%g\n", arr[0], arr[1]);

    arr = dychotomy(func, a, b, eps);
    printf("\r\ndychotomy\r\ni=%g;min_x=%g\n", arr[0], arr[1]);


    return 0;
}

