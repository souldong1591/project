/*************************************************************************
	> File Name: arr_para.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月09日 星期三 15时13分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10
#define N 10

typedef struct _ARR
{
    int A[M][N];
    int m_;
    int n_;
}ARR;

void print(ARR *arr)
{
    int i, j;
    for (i = 0; i < arr->m_; i++) {
        for (j = 0; j < arr->n_; j++) {
            printf("%d ", arr->A[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char *argv[])
{
    ARR arr;
    int i, j, k = 0;
    arr.m_ = 2;
    arr.n_ = 2;
    for (i = 0; i < arr.m_; i++) {
        for(j = 0; j < arr.n_; j++)
        {
            arr.A[i][j] = k;
            k++;
        }
    }
    print(&arr);
    return 0;
}
