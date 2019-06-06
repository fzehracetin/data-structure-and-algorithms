#include <stdio.h>

void insertion(int a[], int n) 
{
    int i, tmp, j;
    for (i = 1; i< n; i++) 
    {
        j = i - 1;
        tmp = a[i];
        
        while( (tmp < a[j]) && (j >= 0) ) 
        {
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = tmp;
    }
}

int main(int argc, char **argv)
{
    int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i, n=10;
    
    for(i = 0; i<n; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
	insertion(a, n);
    
    for(i = 0; i<n; i++) 
    {
        printf("%d ", a[i]);
    }
	return 0;
}
