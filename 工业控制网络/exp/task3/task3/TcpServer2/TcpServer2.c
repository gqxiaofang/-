#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include <pthread.h>

#define MAX_LEN 1024

SOCKET hClient = 0;
SOCKET hServer = 0;
void* AcceptThread(void* p);
void* RecvClientThread(void* p);

int main(int argc, char* argv[])
{
    WSADATA wsaData;
    SOCKADDR_IN servAddr, clntAddr;
    char sendBuffer[MAX_LEN];
    int port = 8000;
    pthread_t tidAccept;
    //校验程序运行参数
    // if (argc != 2)
    // {
    //     printf("提供的运行参数错误。用法: %s <Port> \n", argv[0]);
    //     return 1;
    // }
    //初始化Socket 
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0 )
    {
        printf("初始化Windows Socket失败.\n");
        return -1;
    }
    //创建套接字
    hServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( hServer == INVALID_SOCKET )
    {
        printf("创建Server Socket失败.\n");
        return -1;
    }
    memset(&servAddr, 0 , sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(8888);
    // servAddr.sin_port = htons(a);
    //绑定套接字
    if (bind(hServer, (SOCKADDR*)&servAddr, sizeof(servAddr))== SOCKET_ERROR)
    {
        printf("Server Socket绑定失败.\n");
        return -1;
    }
    if (listen(hServer, 10) == SOCKET_ERROR)
    {
        printf("Server 监听失败.\n");
        return -1;
    }
    //启动接受客户端线程
    pthread_create(&tidAccept, NULL, AcceptThread, &clntAddr);
    while (1)
    {
        fgets(sendBuffer, sizeof(sendBuffer), stdin);
        if (sendBuffer[0] == 'q')
            break;
        if (hClient == 0)
        {
            printf("当前没有客户端连接.\n");
            continue;
        }
        int Ret = send(hClient, sendBuffer, (int)strlen(sendBuffer), 0);
        if ( Ret == SOCKET_ERROR )
        {
            printf("发送数据失败.\n");
            break;
        }
    }
    system("pause");
    closesocket(hClient);
    closesocket(hServer);
    WSACleanup();
    printf("Server程序退出.\n");
    return 0;
}

//接受客户端线程函数
void* AcceptThread(void* p)
{
    SOCKADDR_IN clntAddr = *(SOCKADDR_IN*)p;
    pthread_t tidHandle;
    while(1)
    {
        int szClntAddr = sizeof(clntAddr);
        hClient = accept(hServer, (SOCKADDR*)&clntAddr, &szClntAddr);
        if (hClient == INVALID_SOCKET)
        {
            printf("Server接受Client失败.\n");
            return NULL;
        }
        pthread_create(&tidHandle, NULL, RecvClientThread, (void*)&hClient);
        printf("已连接的客户端：%s:%d \n", inet_ntoa(clntAddr.sin_addr), clntAddr.sin_port);
    }
    return NULL;
}

//处理客户端连接线程
void* RecvClientThread(void* p)
{
    pthread_detach(pthread_self());
    SOCKET hClntSock = *(SOCKET*)p;
    char recvData[MAX_LEN] = {0};
    int ret = 0;
    //循环等待接收数据
    while(1)
    {
        memset(recvData, 0, MAX_LEN);
        ret = recv(hClntSock, recvData, MAX_LEN, 0);
        if (ret == -1)
        {
            printf("接收客户端数据过程中出现错误.\n");
            return NULL;
        }
        else if (ret == 0)
        {
            printf("客户端已断开连接.\n");
            return NULL;
        }
        else
        {
            printf("接收到客户端的数据:%s\n", recvData);
        }
    }
    return NULL;
}
