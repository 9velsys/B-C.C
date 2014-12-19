#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100


int main()
{
    int swap,c,d,n,b =0,i,x,naum=0;
    char l[1];
    char big[MAX_STRING_LEN];
    char small[MAX_STRING_LEN];
    char sum[MAX_STRING_LEN];
    printf("Enter The small:");
    scanf("%s",&small);
    n = strlen(small);
    for (c = 0 ; c < ( n - 1 ); c++)
    {
        for (d = 0 ; d < n - c - 1; d++)
        {
            if (small[d] > small[d+1]) /* For decreasing order use < */
            {
                swap = small[d];
                small[d] = small[d+1];
                small[d+1] = swap;
            }
        }
    }
    for (c = 0 ,d = (n -1); c < (n - 1) || d>=0; c++,d--)
        big[c] = small[d];
    small[n]='\0';
    big[n]='\0';
    while(b<n&&small[0]=='0')
    {
        if (small[b]!='0')
        {
            small[0]=small[b];
            small[b]=48;
            break;
        }
        b++;
    }
     i = n - 1;
    while (i >= 0)
    {
        x = small[i] + big [i] - 2*48 + naum;
        if (x > 9)
        {
            naum = 1;
            x = x - 10;
        }
        else
            naum = 0;
        itoa(x,l,10);
        sum[i+1]=l[0];
        i=i-1;
    }
    printf("Small= %s",small);
    printf("\nBig= %s\n",big);
    if (naum == 1)
    {
        sum[0]='1';
        for (i=0;i<n;i++)
            printf("%c",sum[i]);
    }
    else
        for (i=0;i<(n-1);i++)
            printf("%c",sum[i]);
    return 0;
}
