#include <stdio.h>

int main(int argc, char **argv)
{
    char str[30] = "Did i say that i need you?";
    char pattern[4] = "need";
    int k = 25, m = 4, flag = 0, i = 0, j = 0;
    
    while ( ( !flag ) && ( i <= k - m ) ) 
    {
        j = 0;
        while ( (j < m) && ( str[i + j] == pattern[j] ) ) 
	{ //i+j yapmazsan indis degeri bozuluyor bu onemli
            j++;
        }
        if ( j == m) 
            flag = 1;
        else
            i++; 
    }
    if ( flag ) 
        printf( "Aranan string bulundu indis = %d \n", i);
    else 
        printf( "Pattern textte yok. . . \n");
    
	return 0;
}
