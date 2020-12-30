#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
//冒泡
void Bubblesort(int  r[], int n)
{
    int flag =1;
    int i=0,j=0;
    for(i=1; i<n; i++)
    {
        flag = 0;
        for(j=n-1; j>=0; j--)
            if(r[j] < r[j-1])
            {
                int t=r[j];
                r[j]=r[j-1];
                r[j-1]=t;
                flag = 1;
            }    
        if(flag == 0)
            return;    
    }
}

void swap(int *a,int *b)
{                            /*序列中元素位置的交换*/
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//快速排序
void quick_sort(int num[],int low,int high)//递归实现快速排序
{
	int left,right,key;
 
	left=low;
	right=high;
	key=num[low];
	
	if(low<high)
	{
		while(left<right)
		{
			while(left<right && num[right]>=key)
				right--;
			num[left]=num[right];
			while(left<right && num[left]<=key)
				left++;
			num[right]=num[left];
		}
		num[left]=key;
		quick_sort(num,low,left-1);
		quick_sort(num,left+1,high);
	}
}
//堆排序
void creatheap(int r[],int i,int n)
{
    int j;
    int t;
    t=r[i];
    j=2*i;
    while (j<n)
    {
        if((j<n)&&(r[j]<r[j+1]))j++;
        if(t<r[j])
        {
            r[i]=r[j];
            i=j;j=2*i;
        }
        else
        {
            j=n;
        }
        r[i]=t;
    }
}
//堆排序
void heapsort(int r[],int n)
{
    int i,t;
    for(i=n/2;i>=0;i--)
    {
        creatheap(r,i,n);
    }
    for(i=n-1;i>=0;i--)
    {
        t=r[0];
        r[0]=r[i];
        r[i]=t;
        creatheap(r,0,i-1);
    }
}

void SeletedSont(int a[],int n)
{
	int i,j,kmin,t;
	for(i=0;i<n-1;i++)
	{
		kmin=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[kmin])  kmin=j;
		
		}
			if(i-kmin){
				t=a[i];
				a[i]=a[kmin];
				a[kmin]=t;
							}
	}
 }
 //??????
void shellSort1(int a[],int n)
{
    int i,j,gap,temp;
    for(gap = n/2;gap>0;gap/=2){
        for(i=gap;i<n;i+=gap){
            temp = a[i];
            for(j = i-gap;j>=0&&a[j]>temp;j-=gap){
                a[j+gap] = a[j];
            }
            a[j+gap] = temp;
        }
    }
}
//输出数组的元素
void print(int r[],int n)
{
    int i=0;
    for(i=0;i<n-1;i++)
    {
        if(i%29==0)
            printf("\n");
        printf("% 6d",r[i]);
    }
    printf("\n"); 
}