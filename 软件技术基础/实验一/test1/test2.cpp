// #include <iostream>
// #include <iomanip>
#include <stdio.h>
#include<stdlib.h>
// using namespace std;

typedef struct Lnode{
    int data;
    struct Lnode *next;
}node;

//查找第 K 个节点，返回该节点前一个节点的地址，否则返回 NULL
node *find(node *head,int k)
{
    if(head==NULL)
    {
        printf("链表为空,无节点可删!\n");
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
//建立一条升序单链表
node *create_sort(void)
{
    node *head=NULL;
    int a;
    printf("建立一条有序链表,请输入数据,以-1结束:\n");
    // cout<<"建立一条有序链表,请输入数据,以-1 节束:\n";
    scanf("%d",&a);
    // while(!(cin>>a)) //输入整数，若不为整数则重输
    // {
    //     // cerr << "输入错误！请重新输入：";
    //     // cin.clear();
    //     // cin.sync();
    // }
    while(a!=-1)
    {
        head=insert(head,a);
        // while(!(cin>>a)) //输入整数，若不为整数则重输
        // {
        //     cerr << "输入错误！请重新输入：";
        //     cin.clear();
        //     cin.sync();
        // }
        scanf("%d",&a);
    }
    return(head);
}
//输出链表上各个节点的值
void print(const node *head)
{
    const node *p;
    p=head;
    printf("链表上各个节点的数据为:\n");
    // cout<<"链表上各个节点的数据为:\n";
    while(p!=NULL)
    {
        // cout<<p->data<<'\t';
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    // cout<<'\n';
}
//删除链表上具有指定值的一个节点
node *delete_one_node(node *head,int num)
{
    node *p1,*p2;
    if(head==NULL){
        printf("链表为空,无节点可删!\n");
        // cout<<"链表为空,无节点可删!\n";
        exit(0);
    }
    if (head->data==num)
    {
        p1=head;
        head=head->next;
        delete p1;
        // system("cls");
        // cout<<"删除了一个节点!\n";
        printf("删除了一个节点!\n");
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
            // cout<<"删除了一个节点!\n";
            printf("删除了一个节点!\n");
        }
        else 
        // cout<<num<<"链表上没找到要删除的节点!\n";
            printf("%d链表上没找到要删除的节点!\n");
    }
    return(head);
}
//求链表的节点数
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
//释放链表的节点空间
void deletechain(node *h)
{
    node *p1;
    while(h){
        p1=h;
        h=h->next;
        delete p1;
    }
    printf("已释放链表的节点空间!\n");
    // cout<<"已释放链表的节点空间!\n";
}
//删除链表上第 k 个节点
node *delete_k_node(node *head,int k)
{
    // while((find(head,k)==NULL)&&(k!=1)) //如果此序号，则重新输入
    // {
    //     // cout<<"该列表无此序号!请重新输入：";
    //     while(!(cin>>k)) //输入序号，若不为整数则重输
    //     {
    //         cerr << "输入错误！请重新输入：";
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
        // cout<<"成功删除了第一个节点!\n";
        printf("删除了第1个节点\n");
    }
    else{
        p=find(head,k); //查找第 k-1 个节点,并由 p 指向该节点
        p1=p->next;
        p->next=p1->next;
        delete p1;
        // system("cls");
        // cout<<"成功删除了第"<<k<<"个节点!\n";
        printf("删除了第%d个节点\n",k);
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
    // cout<<"节点数:"<<count(head)<<"\n";
    printf("节点数:%d\n",count(head));

    printf("输入要删除节点上的序号\n");
    // cout<<"输入要删除节点上的序号!\n";
    // cin>>num;
    scanf("%d",&num);
    head=delete_k_node(head,num);
    print(head);

    printf("输入要删除节点上的整数\n");
    scanf("%d",&num);
    // cout<<"输入要删除节点上的整数!\n";
    // cin>>num;
    head=delete_one_node(head,num);
    print(head);
    // deletechain(head);

    // cout<<"输入要插入的整数!\n";
    // cin>>num;
    printf("输入要插入的整数!\n");
    scanf("%d",&num);    
    head=insert(head, num);
    print(head);

    system("pause");
    return 0;
}