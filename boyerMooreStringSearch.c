#include <stdio.h>

int boyerMoore(char str[], char pattern[], int n, int m) 
{
    char right[26];
    int i, j, flag = 0, skip;
    
    for (i = 0; i < 26; i++) 
    {
        right[i] = -1;
    }
    for (i = 0; i < m; i++) 
    {
        right[ pattern[i] - 'a' ] = i;
    }
    
    while ( ( !flag ) && ( i <= n - m) ) 
    {
        j = m -1;
        while ( ( str[i + j] == pattern[j] ) && ( j >= 0 ) ) 
        {
            j--;
        }
        
        if ( j < 0 ) 
            flag = 1;
        else 
        {
            skip = j - right[ str[ i + j] - 'a'];
            if ( skip < 0 ) 
                i++;
            else
                i = i + skip;
        }
    }
    
    if (!flag) 
        i = -1;
    
    return i;
}

int main(int argc, char **argv)
{
    int n = 25, m = 4, index;
    char str[25] = "did i say that i need you";
    char pattern[4] = "need";
    
    index = boyerMoore(str, pattern, n, m);
	
    if (index != -1) 
        printf("Pattern starts from index %d \n", index);
    else 
        printf("Pattern does not exists in the text \n");
    
	return 0;
}

