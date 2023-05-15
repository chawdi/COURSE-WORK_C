#define _CRT_SECURE_NO_WARNINGS
#define Nmax 1000
#include <stdio.h>
#include <math.h>
#include "func.h"
#include "func.c"

void main()
{
    float Uinp[Nmax + 1], Uout[Nmax + 1];
    float t0, t1, t2, tk, tmax, tmax1, U1, U2, a, b, Uinp1, C, eps, dTUMAXC;
    int N, N0;
    char DEBUG;
    printf("Enter values: \nEnter tstart, t1, t2, tend:\n");
    scanf("%f %f %f %f", &t0, &t1, &t2, &tk);
    printf("Enter a, b:\n");
    scanf("%f %f", &a, &b);
    printf("Enter U1, U2:\n");
    scanf("%f %f", &U1, &U2);
    printf("Enter N:\n");
    scanf("%d", &N0);
    printf("Enter Epsilon:\n");
    scanf("%f", &eps);
    printf("Enter C:\n");
    scanf("%f", &C);
    system("cls");
    printf("Debug mode? [Y/N]");
    DEBUG = getch();
    system("cls");
    N = N0;
    dTUMAXC = eps + 1;
    while (N <= Nmax && dTUMAXC >= eps)
    {
        design_t_Uinp( N, t0, t1, t2, tk, U1, U2, Uinp);
        design_Uout(N,  a, b, Uinp1, Uinp, Uout);
        tmax = design_tmax(N, Uout, t0, tk, C, U1);
        if (DEBUG == 'y' || DEBUG == 'Y')
        {
            debug_out(N, t0, tk, tmax, Uinp, Uout);
        }
        if (N != N0)
        {

                dTUMAXC = fabs(tmax1 - tmax) / tmax;
        }
        tmax1 = tmax;
        N *= 2;
    }
    if (N > Nmax)
	{
		printf("Specified accuracy is not achieved\n");
		printf("Actual margin of error is %lf", dTUMAXC);
	}
	else
	{
		N = N / 2;
		printf("Moment of time when Uout > C*Umax: %lf\n", tmax);
		printf("Specified accuracy is achieved at N = %d\n", N);
		printf("Actual margin of error is %lf\n", dTUMAXC);
	}
	system("pause");
}

