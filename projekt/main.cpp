#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

void completeA(double **A, int w, int k);
void completeM(double **A, int w, int k);
void display(double **A, int w, int k);
void save(FILE *f, double **A, int w, int k);
int main()
{
	FILE*f=fopen("Dane1.txt", "w");
	FILE*g=fopen("Dane2.txt", "w");
	double **A;
	double **B;
	int w1,k1,w2,k2, i,a, b;
	srand( time (NULL) );
	printf("Jakich rozmiarow macierze chcesz uzupelnic \n");
	scanf("%d%d%d%d", &w1, &k1, &w2, &k2);
	A = (double**)malloc(w1*sizeof(double*));  
    for(i=0; i<w1; ++i)
	{
		A[i] = (double*)malloc(k1*sizeof(double));
	}
	B = (double**)malloc(w2*sizeof(double*));  
    for(i=0; i<w2; ++i)
	{
		B[i] = (double*)malloc(k2*sizeof(double));
	}
	printf("Jak chcesz uzupelnic macierz 1?\n Jesli chcesz uzupelnic macierz automatycznie kliknij 1, jesli chcesz uzupelnij ja samodzielnie kliknij 2 \n \n UWAGA: \n Macierz automatycznie uzupelnia sie liczbami rzeczyiwstymi od -100 do 100 \n");
	scanf("%d", &a);
	if(a==1)
	{
		completeA(A, w1, k1);
	}
	else if(a==2)
	{
		completeM(A, w1, k1);
	}
	printf("Jak chcesz uzupelnic macierz 2?\n Jesli chcesz uzupelnic macierz automatycznie kliknij 1, jesli chcesz uzupelnij ja samodzielnie kliknij 2 \n \n UWAGA: \n Macierz automatycznie uzupelnia sie liczbami rzeczyiwstymi od -100 do 100 \n");
		scanf("%d", &b);
	if(b==1)
	{
		completeA(B, w2, k2);
	}
	else if(b==2)
	{
		completeM(B, w2, k2);
	}
	display(A,w1, k1);
	printf("\n");
	display(B, w2, k2);
	fprintf(f, "%d \t %d \n", w1, k1);
	fprintf(g, "%d \t %d \n", w2, k2);
	save(f, A, w1, k1);
	save(g, B, w2, k2);
	for(i=0; i<w1; ++i)
		free(A[i]);
	for(i=0; i<w2; ++i)
		free(B[i]);
	free(A);
	free(B);
	fclose(f);
	fclose(g);
	system("pause");
	return 0;
}

void completeA(double **A, int w, int k)
{
	int i, j;
	for(i=0; i<w; i++)
	{
		for(j=0; j<k; j++)
		{
			A[i][j]=(double)rand()*200/RAND_MAX-100;
		}
	}
}
void completeM(double **A, int w, int k)
{
	int i, j;
	for(i=0; i<w; i++)
	{
		for(j=0; j<k; j++)
		{
			scanf("%lf", &A[i][j]);
		}
	}
}
void display(double **A, int w, int k)
{
	int i, j;
	for(i=0; i<w; i++)
	{
		for(j=0; j<k; j++)
		{
			printf("%.1lf \t", A[i][j]);
		}
		printf("\n");
	}
}
void save(FILE *f, double **A , int w, int k)
{
	int i,j;
	for(i =0; i<w; i++)
	{
		for(j=0; j<k; j++)
		{
			fprintf(f,"%.2lf \t" ,A[i][j]);
		}
		fprintf(f, "\n");
	}
}
