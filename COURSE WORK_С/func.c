void design_t_Uinp(int N, float t0, float t1, float t2, float tk, float U1, float U2, float *Uinp)
{
    float dt, t;
    t = t0;
    dt = (tk - t0)/N;
    for (int i = 0; i < N; i++)
    {
        if (t <= t1)
        {
            Uinp[i] =  (t - t0) * U1/(t1 - t0);
        }
        else if ((t > t1) && (t <= t2))
        {
            Uinp[i] = (t - t1) * (U2 - U1)/(t2 -t1) + U1;
        }
        else
        {
            Uinp[i] = (t -t2) * -U2/(tk -t2) + U2;
        }
        t += dt;
    }
}

void design_Uout(int N, float a, float b, float Uinp1, float *Uinp, float *Uout)
{
    Uinp1 = 10;
    for(int i = 0; i < N; i++)
    {
        if(Uinp[i] <= Uinp1)
        {
            Uout[i] = a;
        }
        else
        {
            Uout[i] = Uinp[i] * Uinp[i] * b;
        }
    }
}

float design_tmax(int N, float *Uout, float t0, float tk, float C, float U1)
{
    int i =1;
    float dt = (tk - t0)/N;
    float CUmax = C * U1;
    while (Uout[i] > CUmax || Uout[i-1] <= CUmax)
    {
        i++;
    }
    return (t0 + i * dt);
}

void debug_out(int N, float t0, float tk, float tmax, float *Uinp, float *Uout)
{
    float dt = (tk -t0) /N;
    int i = 0;
    printf("T\tUin\tUout\n");
    while (i <= N)
    {
        printf("%f %f %f\n", t0, Uinp[i], Uout[i]);
        t0 += dt;
        i ++;
    }
    printf("N=%d\nMoment of time when Uout < C*Umax: %f s\n", N, tmax);
	system("pause");
	system("cls");
}

