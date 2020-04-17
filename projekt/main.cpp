#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void display(double **X, int H, int W);
void getdata1(FILE *f, int w, int k);
void getdata2(FILE *f,double **A, int wa, int ka); 
void complete(double **A, int wa, int ka);
void save(double **A, int wa, int ka, FILE*f);
void add(double **A, double **B, double **C, int ka, int wa, int kb, int wb);
void substruct(double **A, double **B,double **C, int ka, int wa, int kb, int wb);
void multiplying(double **A, double **B, double **C, int ka, int wa, int kb, int wb);
int main()
{
	double **A, **B, **C1, **C2, **D;
	int i, j;
	int wa,wb, ka, kb;
	wa=0;
	wb=0;
	ka=0;
	kb=0;
	srand ( time (NULL) );
	FILE *f = fopen("Dane1.txt", "r");
	FILE *g = fopen("Dane2.txt", "r");
	FILE *h = fopen("Wynik.txt", "w");
	fscanf(f, "%d %d", &wa, &ka);
	fscanf(g, "%d %d", &wb, &kb);
	A = (double**)malloc(wa*sizeof(double*)); //tworzymy 4 tablice dynamiczne  
    for(i=0; i<wa; ++i) 
		A[i] = (double*)malloc(ka*sizeof(double));
    B = (double**)malloc(wb*sizeof(double*));
	for(i = 0; i<wb; ++i)
		B[i] = (double*)malloc(kb*sizeof(double));
	C1 = (double**)malloc(wa*sizeof(double*));
    for(i = 0; i<wa; ++i)
		C1[i] = (double*)malloc(ka*sizeof(double));
	C2 = (double**)malloc(wa*sizeof(double*));
    for(i = 0; i<wa; ++i)
		C2[i] = (double*)malloc(ka*sizeof(double));
	D= (double**)malloc(wa*sizeof(double*));  // 5-ta tablica stworzona dla mnozenia 
    for(i=0; i<wa; ++i) 
		D[i] = (double*)malloc(kb*sizeof(double));
	//complete(A, wa, ka);
	getdata2(f, A, wa, ka);
	display(A, wa, ka);
	printf("\n \n");
	//complete(B, wb, kb);
	getdata2(g, B, wb, kb);
	display(B, wb, kb);printf("\n \n");
	add(A, B, C1, ka, wa, kb, wb);
	printf("\n \n");
	if( (ka==kb)&&(wa==wb) )
	{
		save(C1, wa ,ka ,h);
		fprintf(h, "\n");
	}
	substruct(A, B, C2, ka ,wa, kb, wb);
	printf("\n \n");
	multiplying(A, B, D, ka, wa, kb,wb);
	if( (ka==kb)&&(wa==wb) )
	{
		save(C2, wa ,ka ,h);
		fprintf(h, "\n");
	}
	if(ka==wb)
	{
	save(D, wa ,kb ,h);
	}
	for(i = 0; i<wa; ++i)
	{
		free(A[i]);
        free(B[i]);
		free(C1[i]);
		free(C2[i]);
		free(D[i]);
	}
	free(A);
	free(B);
	free(C1);
	free(C2);
	free(D);
	fclose(f);
	fclose(g);
	fclose(h);
	system("pause");
	return 0;
}


void getdata1(FILE*f, int w, int k)
{
	fscanf(f, "%d %d", &w, &k);
}
void getdata2(FILE*f, double **A, int wa, int ka)
{
	int i,j;
	for (i=0; i<wa; ++i)
	{
		for(j=0; j<ka; ++j) fscanf(f, "%lf", &A[i][j]);
	}
}

void complete(double **A, int wa, int ka)
{
	int i,j;
	for (i=0; i<wa; ++i)
	{
		for(j=0; j<ka; ++j)
		{
			A[i][j]=(double)rand()/RAND_MAX*100;
		}
	}
}
void save(double **A, int wa, int ka, FILE *f)
{
	int i, j;
	for(i=0; i<wa; ++i)
	{
		for(int j=0; j<ka; ++j)
		{
			fprintf(f, "%lf \t", A[i][j]);
		}
		fprintf(f, "\n");
	}
}

void display(double **X, int H, int W)
{
	int i,j;
    for(i=0; i<H; ++i){
        for(j=0; j<W; ++j){
            printf("%.1lf \t",X[i][j]);
        }
        printf("\n");
    }		
}
void add(double **A, double **B, double **C, int ka, int wa, int kb, int wb)
{
	int i,j;
	if( (ka==kb)&&(wa==wb) )
	{
		for(i=0; i<wa; i++)
		{
			for (j=0; j<ka; j++)
				C[i][j]=A[i][j]+B[i][j];
		}
		display(C,wa , ka);
	}
	else 
	{
		printf("You cannot add these matrixes\n");
		for(i=0; i<wa; i++)
		{
			for (j=0; j<ka; j++)
				C[i][j]=0.0;
		}
	}
}

void substruct(double **A, double **B,double **C, int ka, int wa, int kb, int wb)
{
	int i,j;
	if( (ka==kb)&&(wa==wb) )
	{
		for(i=0; i<wa; i++)
		{
			for (j=0; j<ka; j++)
				C[i][j]=A[i][j]-B[i][j];
		}
	display(C, wa, kb);
	}
	else 
	{
		printf("You cannot make a substruction of these matrixes\n");
		for(i=0; i<wa; i++)
		{
			for (j=0; j<ka; j++)
				C[i][j]=0.;
		}
	}
}
void multiplying(double **A, double **B, double **C, int ka, int wa, int kb, int wb)
{
	
	int i,j,k ;
	for(i=0; i<wa; i++)
	{
			for (j=0; j<kb; j++)
			{
				C[i][j]=0.0;
			}
	}
	if( ka==wb )
	{
		for(i=0; i<wa; i++)
		{
			for (j=0; j<kb; j++)
			{
				for(k=0; k<ka; k++)
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	display(C, wa, kb);
	}
	else 
	{
		printf("You cannot multiply these matrixes\n");
	}
}



