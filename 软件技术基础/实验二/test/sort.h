#ifndef __SORT__H
#define __SORT__H

//ð��
void Bubblesort(int  r[], int n);
void swap(int *a,int *b);
//��������
void quick_sort(int num[],int low,int high);//�ݹ�ʵ�ֿ�������
//������
void creatheap(int r[],int i,int n);
//������
void heapsort(int r[],int n);
void SeletedSont(int a[],int n);
void shellSort1(int a[],int n);
//��������Ԫ��
void print(int r[],int n);

#endif /* __SORT__H */