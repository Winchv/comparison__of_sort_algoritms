#include "Sortw.h" 

void BubbleSort1(float *A, int N) 
{ 
int i, k; 

for (k = 0; k < N - 1; k++) 
for (i = 0; i < N - (1 + k); i++) 
if (A[i] > A[i + 1]) 
Swap(&A[i], &A[i + 1]); 
} 

void InsertionSort(float *A, int N) 
{ 
int i, j; 
float x; 

for (i = 1; i <= N - 1; i++) 
{ 
x = A[i]; 
j = i - 1; 

while (j >= 0 && A[j] > x) 
A[j + 1] = A[j], j--; 
A[j + 1] = x; 
} 
} 

void SelectionSort(float *A, int N) 
{ 
int i, j, min; 

for (j = 0; j <= N - 2; j++) 
{ 
min = j; 

for (i = j + 1; i < N; i++) 
if (A[i] < A[min]) 
min = i; 
Swap(&A[j], &A[min]); 
} 
} 

void HeapCorrection(float *A, int N, int I) 
{ 
int largest = I; 
int left = 2 * I + 1; 
int right = 2 * I + 2; 

if (left < N && A[left] > A[largest]) 
largest = left; 

if (right < N && A[right] > A[largest]) 
largest = right; 

if (largest != I) 
{ 
Swap(&A[I], &A[largest]); 
HeapCorrection(A, N, largest); 
} 
} 

void HeapSort(float *A, int N) 
{ 
int i; 
for (i = N / 2 - 1; i >= 0; i--) 
HeapCorrection(A, N, i); 
for (i = N - 1; i > 0; i--) 
{ 
Swap(&A[0], &A[i]); 
HeapCorrection(A, i, 0); 
} 
} 

void MergeSort(float *A, int N) 
{ 
int m, i, j, k; 
static float b[MAX]; 

if (N <= 1) 
return; 
m = N / 2; 
MergeSort(A, m); 
MergeSort(A + m, N - m); 
i = 0, j = m, k = 0; 
while (k < N) 
{ 
if (j >= N || (i < m && A[i] <= A[j])) 
b[k++] = A[i++]; 
else 
b[k++] = A[j++]; 
} 
for (i = 0; i < N; i++) 
A[i] = b[i]; 
} 

void QuickSort(float *A, int N) 
{ 
int b, e; 
float x; 
if (N < 2) 
return; 
x = A[N / 2]; 
b = 0; 
e = N - 1; 
while (b <= e) 
{ 
while (A[b] < x) 
b++; 
while (A[e] > x) 
e--; 
if (b <= e) 
{ 
if (b != e) 
Swap(&A[b], &A[e]); 
b++; 
e--; 
} 
} 
QuickSort(A, e + 1); 
QuickSort(A + b, N - b); 
}
