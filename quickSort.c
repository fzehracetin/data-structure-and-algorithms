#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap (int i, int j, int A[]) 
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] =  tmp;
}

int partition (int A[], int left, int right) 
{
    int pivot, i, j;
    pivot = A[left];
    i = left ; // do-while yapisi oldugu icin 
    j = right + 1; //normalde pivot +1 ile right arasi gezer
    do 
    {
        do 
	{
            i++;
        } 
	while ( ( i <= j ) && ( A[i] <= pivot ) );
        
        do 
	{
            j--;
        } 
	while ( ( i <= j ) && ( A[j] > pivot ) );
        
	swap (i, j, A);
    } 
    while (i < j);
    swap (i, j, A);
    swap(left, j, A);
    return j;
}

void quickSort ( int A[], int left, int right ) {
    int s;
    if ( left < right ) 
    {
        s = partitionW(A, left, right);
        quickSort(A, left, s - 1);
        quickSort(A, s + 1, right);
    }
}

int main(int argc, char **argv)
{
    int A[5] = { 5, 1, 3, 2, 4};
    
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", A[i]);
    } 
    printf("\n");
    quickSort(A, 0, 4);
    
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", A[i]);
    } 
    printf("\n");
    
	return 0;
}
