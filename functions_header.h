float sigmoid(float x);
float sigder(float x);
int write(char * filename, int message[], int n);
int read(char * filename, int pos); 
int randomf(int header[]);
void trainer (double trinput[][3], double troutput[], int q, double weights[3]);
double dot_product( double *v1, double *v2, int size);
double anal(double input[], double weights[3]);
void bmp_analyzer(int temp[], int header[], int start, double weights[3]);