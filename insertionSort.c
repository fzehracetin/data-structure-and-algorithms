#include <stdio.h>
#define n 10

int main(int argc, char **argv)
{
    int a[n] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i, j, tmp;
    
    for(i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    
	for (i = 1; i< n; i++) {
        j = i - 1;
        tmp = a[i];
        
        while( (tmp < a[j]) && (j >= 0) ) {
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = tmp;
    }
    for(i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
	return 0;
}
