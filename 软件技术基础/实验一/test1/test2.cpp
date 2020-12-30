// #include <iostream>
// #include <iomanip>
#include <stdio.h>
#include<stdlib.h>
// using namespace std;

typedef struct Lnode{
    int data;
    struct Lnode *next;
}node;

//���ҵ� K ���ڵ㣬���ظýڵ�ǰһ���ڵ�ĵ�ַ�����򷵻� NULL
node *find(node *head,int k)
{
    if(head==NULL)
    {
        printf("����Ϊ��,�޽ڵ��ɾ!\n");
        exit(0);
    }
    if (k<2)
    {
        return NULL;
    }
    else
    {
        node *p;
        p=head;
        int i;
        for(i=2;(i<k)||(p->next==NULL);i++)
        {
            if(p->next==NULL)
            {
                return NULL;
            }
            p=p->next;
        }
    return p;
    }
}
node *insert(node *head,int num)
{
    node *p1;
    p1=new node;
    p1->data=num;
    p1->next=NULL;
    if(head==NULL)
    {
        return p1;
    }
    else
    {
        node *p2;
        p2=head;
        if((p2->data)>(p1->data))
        {
            p1->next=p2;
            return p1;
        }
        while(p2->next!=NULL)
        {
            if(((p2->data)<=(p1->data))&&((p2->next->data)>=(p1->data)))
            {
                p1->next=p2->next;
                p2->next=p1;
                return head;
            }
            p2=p2->next;
        }
        p2->next=p1;
        return head;
    }
}
//����һ����������
node *create_sort(void)
{
    node *head=NULL;
    int a;
    printf("����һ����������,����������,��-1����:\n");
    // cout<<"����һ����������,����������,��-1 ����:\n";
    scanf("%d",&a);
    // while(!(cin>>a)) //��������������Ϊ����������
    // {
    //     // cerr << "����������������룺";
    //     // cin.clear();
    //     // cin.sync();
    // }
    while(a!=-1)
    {
        head=insert(head,a);
        // while(!(cin>>a)) //��������������Ϊ����������
        // {
        //     cerr << "����������������룺";
        //     cin.clear();
        //     cin.sync();
        // }
        scanf("%d",&a);
    }
    return(head);
}
//��������ϸ����ڵ��ֵ
void print(const node *head)
{
    const node *p;
    p=head;
    printf("�����ϸ����ڵ������Ϊ:\n");
    // cout<<"�����ϸ����ڵ������Ϊ:\n";
    while(p!=NULL)
    {
        // cout<<p->data<<'\t';
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    // cout<<'\n';
}
//ɾ�������Ͼ���ָ��ֵ��һ���ڵ�
node *delete_one_node(node *head,int num)
{
    node *p1,*p2;
    if(head==NULL){
        printf("����Ϊ��,�޽ڵ��ɾ!\n");
        // cout<<"����Ϊ��,�޽ڵ��ɾ!\n";
        exit(0);
    }
    if (head->data==num)
    {
        p1=head;
        head=head->next;
        delete p1;
        // system("cls");
        // cout<<"ɾ����һ���ڵ�!\n";
        printf("ɾ����һ���ڵ�!\n");
    }
    else{
        p2=p1=head;
        while(p2->data!=num&&p2->next!=NULL){
            p1=p2;
            p2=p2->next;
        }
        if (p2->data==num){
            p1->next=p2->next;
            delete p2;
            // system("cls");
            // cout<<"ɾ����һ���ڵ�!\n";
            printf("ɾ����һ���ڵ�!\n");
        }
        else 
        // cout<<num<<"������û�ҵ�Ҫɾ���Ľڵ�!\n";
            printf("%d������û�ҵ�Ҫɾ���Ľڵ�!\n");
    }
    return(head);
}
//������Ľڵ���
int count(node *head)
{
    int n;
    node *p;
    p=head;
    n=0;
    while(p!=NULL){
        n=n+1;
        p=p->next;
    }
    return(n);
}
//�ͷ�����Ľڵ�ռ�
void deletechain(node *h)
{
    node *p1;
    while(h){
        p1=h;
        h=h->next;
        delete p1;
    }
    printf("���ͷ�����Ľڵ�ռ�!\n");
    // cout<<"���ͷ�����Ľڵ�ռ�!\n";
}
//ɾ�������ϵ� k ���ڵ�
node *delete_k_node(node *head,int k)
{
    // while((find(head,k)==NULL)&&(k!=1)) //�������ţ�����������
    // {
    //     // cout<<"���б��޴����!���������룺";
    //     while(!(cin>>k)) //������ţ�����Ϊ����������
    //     {
    //         cerr << "����������������룺";
    //         cin.clear();
    //         cin.sync();
    //     }
    // }
    int j=1;
    node *p,*p1;
    p=head;
    if (k==1){
        p=head;
        head=head->next;
        delete p;
        system("cls");
        // cout<<"�ɹ�ɾ���˵�һ���ڵ�!\n";
        printf("ɾ���˵�1���ڵ�\n");
    }
    else{
        p=find(head,k); //���ҵ� k-1 ���ڵ�,���� p ָ��ýڵ�
        p1=p->next;
        p->next=p1->next;
        delete p1;
        // system("cls");
        // cout<<"�ɹ�ɾ���˵�"<<k<<"���ڵ�!\n";
        printf("ɾ���˵�%d���ڵ�\n",k);
    }
    return(head);
}
int main()
{
    node *head;
    int num;
    int k;
    head= create_sort ();
    print(head);
    // cout<<"�ڵ���:"<<count(head)<<"\n";
    printf("�ڵ���:%d\n",count(head));

    printf("����Ҫɾ���ڵ��ϵ����\n");
    // cout<<"����Ҫɾ���ڵ��ϵ����!\n";
    // cin>>num;
    scanf("%d",&num);
    head=delete_k_node(head,num);
    print(head);

    printf("����Ҫɾ���ڵ��ϵ�����\n");
    scanf("%d",&num);
    // cout<<"����Ҫɾ���ڵ��ϵ�����!\n";
    // cin>>num;
    head=delete_one_node(head,num);
    print(head);
    // deletechain(head);

    // cout<<"����Ҫ���������!\n";
    // cin>>num;
    printf("����Ҫ���������!\n");
    scanf("%d",&num);    
    head=insert(head, num);
    print(head);

    system("pause");
    return 0;
}