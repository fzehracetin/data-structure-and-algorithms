#include <stdio.h>
#include <stdlib.h>

void merge (int A[], int p, int q, int r) 
{
    int *B, m, i, j, k;
    m = r - p + 1;
    B = (int*) malloc(m*sizeof(int));
    if ( B == NULL) {
        printf("Yer acilamadi \n");
    }
    i = p, j = q + 1, k = 0;
    while ( (i <= q) && (j <= r) ) 
    {
        if ( A[i] < A[j]) 
            B[k++] = A[i++];
        else 
            B[k++] = A[j++];
    }
    while ( i <= q ) 
    {
        B[k++] = A[i++];
    }
    while ( j <= r ) 
    {
        B[k++] = A[j++];
    }
    for ( i = p, k = 0; i <= r; i++, k++) 
    {
        A[i] = B[k];
    }
    free(B);
}

void mergeSort(int A[], int p, int r) 
{
    int q;
    if ( p < r) 
    {
        q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(int argc, char **argv)
{
    int A[8] = { 9, 8, 7, 6, 5, 4, 7, 1};
    mergeSort( A, 0, 7);
    
    for (int i = 0; i < 8; i++) 
    {
        printf("%d ", A[i]);
    }
    printf("\n");
	return 0;
}
