#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int start, stop; //clock_tΪclock()�������صı�������
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

    //����˳��
    start = 0;
    stop = 0;
    duration = 0;
    printf("��������:\n");
    start=clock();
    quick_sort(data2,0,N-1);
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC;
    print(data2,N);
    printf("����ʱ��:%dms\n",stop-start);
    //������
    start = 0;
    stop = 0;
    duration = 0;
    printf("������:\n");
    start=clock();
    heapsort(data3,N);
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC; //CLK_TCKΪclock()������ʱ�䵥λ����ʱ�Ӵ��
    print(data3,N);
    printf("����ʱ��:%dms\n",stop-start);
    //ֱ��ѡ������
    start = 0;
    stop = 0;
    duration = 0;
    printf("ֱ������:\n");
    start=clock();
    SeletedSont(data4,N);
    stop=clock();
    duration=(double)(stop-start)/CLOCKS_PER_SEC; //CLK_TCKΪclock()������ʱ�䵥λ����ʱ�Ӵ��
    print(data4,N);
    printf("����ʱ��:%dms\n",stop-start);
    //ϣ������
    start = 0;
    stop = 0;
    duration = 0;
    printf("ϣ������:\n");
    start=clock();
    shellSort1(data5,N);
    stop=clock();
    duration=(double)(stop-start)/*/CLOCKS_PER_SEC*/; //CLK_TCKΪclock()������ʱ�䵥λ����ʱ�Ӵ��
    print(data5,N);
    printf("����ʱ��:%dms\n",stop-start);
        //ð��˳��
    printf("ð������:\n");
    start=clock();
    Bubblesort(data1,N);
    stop=clock();
    // duration=(double)(stop-start)/CLK_TCK; //CLK_TCKΪclock()������ʱ�䵥λ����ʱ�Ӵ��
    print(data1,N);
    printf("����ʱ��:%dms\n",stop-start);
    system("pause");
    return 0;
}