#include <stdio.h>
#include <stdlib.h>

void insertInHeap(int *n, int HT[], int eleman) 
{
    int tmp, i;
    HT[++*n] = eleman;
    i = *n;
    int parent = (i-1)/2;
    while( (i >= 0)&& (HT[parent] > HT[i]) ) 
    {
        tmp = HT[parent];
        HT[parent] = HT[i];
        HT[i] = tmp;
        i = parent;
        parent = (i-1)/2;
    }
}

int findSmallestChild(int n, int HT[], int i) 
{
    if (n > 2*i + 2) 
    {
        if ( HT[2*i + 1] > HT[2*i + 2]) 
            return 2*i + 1;
        else
            return 2*i + 2;
    } 
    else if (n > 2*i + 1) 
        return 2*i + 1;
    else 
        return 0;
    
}

void removeMin(int *n, int HT[] ) 
{
    int tmp, i=0, adr;
    tmp = HT[0];
    HT[0] = HT[*n];
    HT[*n--] = tmp;
    adr = findSmallestChild(*n, HT, i);
    while (( adr ) && (HT[i] > HT[ adr])) 
    {
        tmp = HT[i];
        HT[i] = HT[adr];
        HT[adr] = tmp;
        i = adr;
        adr = findSmallestChild(*n, HT, i);
    }
}

void downHeap(int HT[], int i, int n) 
{
    int tmp, adr;
    adr = findSmallestChild(n, HT, i);
    while (( adr ) && (HT[i] > HT[ adr])) 
    {
        tmp = HT[i];
        HT[i] = HT[adr];
        HT[adr] = tmp;
        i = adr;
        adr = findSmallestChild(n, HT, i);
    }
}


int main(int argc, char **argv)
{
    int i, n = 7, m =7;
    int HT1[10] = { 9, 12, 15, 17, 25, 30, 20 };
    int HT2[10] = { 5, 4, 2, 3, 1, 9, 10};
    
    for (i = 0; i<n ; i++) {
        printf ("%d ", HT1[i]);
    }
    printf("\n");
	insertInHeap(&n , HT1, 3);
    for (i = 0; i<n ; i++) {
        printf ("%d ", HT1[i]);
    }
    printf("\n");
    for (i = 0; i<m ; i++) {
        printf ("%d ", HT2[i]);
    }
    printf("\n");
    heapSort(m, HT2);
    for (i = 0; i<m ; i++) {
        printf ("%d ", HT2[i]);
    }
    printf("\n");
    removeMin(&m, HT2);
    for (i = 0; i<m ; i++) {
        printf ("%d ", HT2[i]);
    }
	return 0;
}
