/*************************************************************************
	> File Name: sort.h
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 18 Jun 2014 12:46:36 PM CST
 ************************************************************************/

#ifndef __SORT__
#define __SORT__
#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *a, int len);		
void insert_sort(int *a, int len);
void select_sort(int *a, int len);
void quick_sort(int *a, int len);
void show_sort(char *s, int *a, int len);
#endif
