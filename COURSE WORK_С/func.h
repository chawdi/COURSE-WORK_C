//def_func.h--������������ � ������������ �p�������� �������

//������� p������ t � U��(t)
void design_t_Uinp(int N, float t0, float t1, float t2, float tk, float U1, float U2, float *Uinp);

//������� p������ U���(t)
void design_Uout(int N, float a, float b, float Uinp1, float *Uinp, float *Uout);
//������� p������ ��p����p������
float design_tmax(int N, float *Uout, float t0, float tk, float C, float U1);

//������� ����������� ������
void debug_out(int N, float t0, float tk, float tmax, float *Uinp, float *Uout);
