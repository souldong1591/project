/*************************************************************************
	> File Name: arr_malloc.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月09日 星期三 15时56分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int i, j, k = 0;
    int **a = (int **)malloc(5 * sizeof(int*));
    for(i = 0; i != 5; i++)
    {
        a[i] = (int*)malloc(3*sizeof(int));
    }
    
    
    for (i = 0; i < 5; i++) 
    {
        for(j = 0; j < 3; j++)
        {
            a[i][j] = k;
            k++;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    } 

    printf("free\n");
    for (i = 0; i < 5; i++) 
    {
        free(a[i]);
    }
    free(a);

    for (i = 0; i < 5; i++) 
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    } 
    return 0;
}
