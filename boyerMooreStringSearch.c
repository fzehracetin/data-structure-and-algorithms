#include <stdio.h>

int main(int argc, char **argv)
{
    int i, flag = 0, n = 25, m = 4, j, skip;
    char str[n] = "did i say that i need you";
    char pattern[m] = "need";
    char right[26];
    
    
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
	return 0;
}
