#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap (int i, int j, int A[]) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] =  tmp;
}

int partition (int A[], int left, int right) {
    int pivot, i, j;
    pivot = A[left];
    i = left ; // do-while yapisi oldugu icin 
    j = right + 1; //normalde pivot +1 ile right arasi gezer
    do {
        do {
            i++;
        } while ( ( i <= j ) && ( A[i] <= pivot ) );
        
        do {
            j--;
        } while ( ( i <= j ) && ( A[j] > pivot ) );
        swap (i, j, A);
    } while (i < j);
    swap (i, j, A);
    swap(left, j, A);
    return j;
}


int partitionW (int A[], int left, int right) {
    for (int i = left; i < right + 1; i++) {
        printf("%d ", A[i]);
    } printf("\n");
    int pivot, i, j;
    i = left + 1;
    j = right;
    pivot = A[left];
    while ( i < j ) {
        while ( (i < j) && (A[i] <= pivot))
            i++;
        while ( (i <= j ) && (A[j] > pivot))
            j--;
        swap(i, j, A);
    }
    swap(i, j, A);
    swap(left, j, A);
    for (int i = left; i < right + 1; i++) {
        printf("%d ", A[i]);
    } printf("\n");
    return j;
}


int partition_r ( int A[], int left, int right) {
    srand( time(NULL) );
    int r = rand() % (right - left) + left;
    printf("%d \n", r);
    swap( r, left, A);
    return partition(A, left, right);
}

int partition_B(int B[], int left, int right, int aranan) {
    int i = left, flag = 1;
    while ((i < right) && (flag)){
        if (B[i] == aranan)
            flag = 0;
        else 
            i++;
    }
    swap(i , left, B);
    return partition(B, left, right);
}

void quickSort ( int A[], int left, int right ) {
    int s;
    if ( left < right ) {
        s = partitionW(A, left, right);
        quickSort(A, left, s - 1);
        quickSort(A, s + 1, right);
    }
}

int main(int argc, char **argv)
{
	int A[5] = { 5, 1, 3, 2, 4};
    //int B[5] = { 1, 4, 5, 3, 2};
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    } printf("\n");
    
    /*for (int i = 0; i < 5; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");*/
    //int x = partition_r(B, 0, 4);
    //printf("%d        ", x);
    //partition_r(B, 0, 4);
    
    quickSort(A, 0, 4);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    } printf("\n");
    
    /*for (int i = 0; i < 5; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");*/
	return 0;
}
