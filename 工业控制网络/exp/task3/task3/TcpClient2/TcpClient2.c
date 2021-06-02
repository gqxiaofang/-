#include <stdio.h>
#include <winsock2.h>
#include <Windows.h>
#include "pthread.h"

#define  PORT 8888
// #define  IP_ADDRESS "192.168.1.103"
#define IP_ADDRESS "127.0.0.1"
#define MAX_LEN 1024

void* RecvNetData(void* p);

int main(int argc, char* argv[])
{
    WSADATA  Ws;
    SOCKET hClient;
    struct sockaddr_in ServerAddr;
    int Ret = 0;
    //接收数据线程ID
    pthread_t threadRecv;
    char sendBuffer[MAX_LEN];
    
    if (WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        printf("初始化Windows Socket失败.\n");
        return -1;
    }
    //创建套接字
    hClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( hClient == INVALID_SOCKET )
    {
        printf("创建Socket失败.\n");
        return -1;
    }
    memset(&ServerAddr, 0 , sizeof(ServerAddr));
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    ServerAddr.sin_port = htons(8888);
    //连接服务器
    Ret = connect(hClient,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if ( Ret == SOCKET_ERROR )
    {
        printf("Tcp连接失败.\n");
        return -1;
    }
    else
    {
        printf("Tcp连接成功!\n");
    }
    //启动接收线程
    pthread_create(&threadRecv, NULL, RecvNetData, &hClient);
    while (1)
    {
        fgets(sendBuffer, sizeof(sendBuffer), stdin);
        Ret = send(hClient, sendBuffer, (int)strlen(sendBuffer), 0);
        if ( Ret == SOCKET_ERROR )
        {
            printf("发送数据失败.\n");
            break;
        }
    }
    system("pause");
    closesocket(hClient);
    WSACleanup();
    
    return 0;
}

//接收网络数据线程函数
void* RecvNetData(void* p)
{
    pthread_detach(pthread_self());
    printf("接收Tcp数据线程已启动……\n");
    SOCKET hSocket = *(SOCKET*)p;
    char recvData[MAX_LEN] = {0};
    int ret = 0;
    //循环等待接收数据
    while(1)
    {
        memset(recvData, 0, MAX_LEN);
        ret = recv(hSocket, recvData, MAX_LEN, 0);
        if (ret == -1)
        {
            printf("接收Tcp数据过程中出现错误.\n");
            return NULL;
        }
        else if (ret == 0)
        {
            printf("服务器已断开连接.\n");
            return NULL;
        }
        else
        {
            printf("接收到%d字节的数据:%s\n", ret-1, recvData);
        }
    }
    return NULL;
}
