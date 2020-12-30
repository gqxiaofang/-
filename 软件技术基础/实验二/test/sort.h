#ifndef __SORT__H
#define __SORT__H

//冒泡
void Bubblesort(int  r[], int n);
void swap(int *a,int *b);
//快速排序
void quick_sort(int num[],int low,int high);//递归实现快速排序
//堆排序
void creatheap(int r[],int i,int n);
//堆排序
void heapsort(int r[],int n);
void SeletedSont(int a[],int n);
void shellSort1(int a[],int n);
//输出数组的元素
void print(int r[],int n);

#endif /* __SORT__H */