#include <stdio.h> 
#include <stdlib.h> 
#include "SortW.h" 

void FillEq(float *A, int N) 
{ 
int i; 
float x; 

for (x = (float)((rand() - 100) / 100.0), i = 0; i < N; i++) 
A[i] = x; 
} 

void FillDecr(float *A, int N) 
{ 
int i; 

for (A[0] = 30 * 30, i = 1; i < N; i++) 
A[i] = A[i - 1] - (float)(rand() % 30 / 10.0); 
} 

void FillIncr(float *A, int N) 
{ 
int i; 

for (A[0] = -30, i = 1; i < N; i++) 
A[i] = A[i - 1] + (float)(rand() % 30 / 10.0); 
} 

void FillRand(float *A, int N) 
{ 
int i; 

for (i = 0; i < N; i++) 
A[i] = (float)((rand() - RAND_MAX / 2) / 100.0); 
} 

void Swap(float *A, float *B) 
{ 
float tmp = *A; 
*A = *B; 
*B = tmp; 
} 

void Output(float *A, int N) 
{ 
int i; 

for (i = 0; i < N; i++) 
printf("%.3fl ", A[i]); 
printf("\n"); 
} 

void FillMostly(float *A, int N) 
{ 
int i; 

FillIncr(A, N); 
for (i = 0; i < N / 20; i++) 
Swap(&A[rand() % N], &A[rand() % N]); 
} 

int CheckSort(float *A, int N) 
{ 
int i; 

for (i = 0; i < N - 1; i++) 
if (A[i] > A[i + 1]) 
return 0; 
return 1; 
}
