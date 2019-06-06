#include <stdio.h>

int bruteForce(char str[], char pattern[], int k, int m) 
{
    int flag = 0, i = 0, j = 0;
    
    while ( ( !flag ) && ( i <= k - m ) ) 
    {
        j = 0;
        while ( (j < m) && ( str[i + j] == pattern[j] ) ) 
        { 
            j++;
        }
        if ( j == m) 
            flag = 1;
        else
            i++; 
    }
    if ( !flag ) 
        i = -1;
    
    return i;
}

int main(int argc, char **argv)
{
    int k = 25, m = 4, index;
    char str[30] = "Did i say that i need you?";
    char pattern[4] = "need";
    
    index = bruteForce(str, pattern, k, m);
    
    if (index != -1) 
        printf("Pattern starts from index %d \n", index);
    else 
        printf("Pattern does not exists in the text \n");
    
	return 0;
}
