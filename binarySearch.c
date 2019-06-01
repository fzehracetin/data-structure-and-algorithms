#include <stdio.h>

void binarySearch(int wanted, int array[], int n) 
{
    int first, last, mid;
    first = 0;
    last = n;
    mid = (first + last)/2;
    while ( (last > first) && (array[mid] != wanted) ) 
    {
        if (array[mid] < wanted) 
            first = mid + 1;
        else 
            last = mid - 1;
        
        mid = (last + first) / 2;
    }
    if (array[mid] == wanted) 
        printf("Aranan kan bulundu indis : %d \n", mid);
}

int main(int argc, char **argv)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    binarySearch(8, array, n);
	return 0;
}
