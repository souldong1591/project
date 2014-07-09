/*************************************************************************
	> File Name: swap2.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月09日 星期三 10时24分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *m, int *n);
int main(int argc, const char *argv[])
{
    int i, j;
    int ********a = &i;
    int ********b = &j;
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
void swap(int *m, int *n)
{
    int *tmp ;
    tmp = *m;
    *m = *n;
    *n = tmp;
}

