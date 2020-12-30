#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int start, stop; //clock_t为clock()函数返回的变量类型
double duration;
const int N=1000;

int main()
{   
    int data[N],data1[N],data2[N],data3[N],data4[N],data5[N];
    int i=0;
    srand((unsigned)time(NULL));
    for(i = 0; i < N; i++)
    {
        data[i] = rand();
        data1[i] = data[i];
        data2[i] = data[i];
        data3[i] = data[i];
        data4[i] = data[i];
        data5[i] = data[i];
        printf("%d ",data[i]);
    }
    printf("\n");

    //快速顺序法
    start = 0;
    stop = 0;
    duration = 0;
    printf("快速排序法:\n");
    start=clock();
    quick_sort(data2,0,N-1);
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC;
    print(data2,N);
    printf("运行时间:%dms\n",stop-start);
    //堆排序
    start = 0;
    stop = 0;
    duration = 0;
    printf("堆排序:\n");
    start=clock();
    heapsort(data3,N);
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC; //CLK_TCK为clock()函数的时间单位，即时钟打点
    print(data3,N);
    printf("运行时间:%dms\n",stop-start);
    //直接选择法排序
    start = 0;
    stop = 0;
    duration = 0;
    printf("直接排序法:\n");
    start=clock();
    SeletedSont(data4,N);
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC; //CLK_TCK为clock()函数的时间单位，即时钟打点
    print(data4,N);
    printf("运行时间:%dms\n",stop-start);
    //希尔排序
    start = 0;
    stop = 0;
    duration = 0;
    printf("希尔排序法:\n");
    start=clock();
    shellSort1(data5,N);
    stop=clock();
    duration=(double)(stop-start)/*/CLOCKS_PER_SEC*/; //CLK_TCK为clock()函数的时间单位，即时钟打点
    print(data5,N);
    printf("运行时间:%dms\n",stop-start);
        //冒泡顺序法
    printf("冒泡排序法:\n");
    start=clock();
    Bubblesort(data1,N);
    stop=clock();
    // duration=(double)(stop-start)/CLK_TCK; //CLK_TCK为clock()函数的时间单位，即时钟打点
    print(data1,N);
    printf("运行时间:%dms\n",stop-start);
    system("pause");
    return 0;
}