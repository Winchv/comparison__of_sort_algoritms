#include <stdio.h> 
#include <time.h> 
#include "sortw.h" 

#define MAX 70000 

int main(void) 
{ 
int fi, si; 
long t; 

void(*Fill[])(float *a, int n) = 
{ 
FillDecr, FillMostly, FillRand, FillEq, FillIncr 
}; 

void(*Sort[])(float *a, int n) = 
{ 
BubbleSort1, InsertionSort, SelectionSort, MergeSort, QuickSort, HeapSort 
}; 

const char (*SortNames[]) = 
{ 
"BubbleSort1", "InsertionSort", "SelectionSort", "MergeSort", "QuickSort", "HeapSort" 
}; 

static float mas[MAX]; 

printf("SORT PROJECT\n"); 

for (si = 0; si < sizeof(Sort) / sizeof(Sort[0]); si++) 
{ 
printf("Sort: %s\n", SortNames[si]); 
for (fi = 0; fi < sizeof(Fill) / sizeof(Fill[0]); fi++) 
{ 
Fill[fi](mas, MAX); 
t = clock(); 
Sort[si](mas, MAX); 
t = clock() - t; 
if (CheckSort(mas, MAX)) 
printf(" %10.5f ", t / (double)CLOCKS_PER_SEC); 
else 
printf(" FAIL "); 
} 
printf("\n"); 
} 
getchar(); 
return 0; 
}
