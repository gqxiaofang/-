#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>

int main(/*int argc, char* argv[]*/)
{
    WSADATA wsaData;
    SOCKET hServer, hClient;
    SOCKADDR_IN servAddr, clntAddr;
    char msg[] = "Hello, Client!";

    // if (argc != 2)
    // {
    //     printf("提供的运行参数错误。用法: %s <Port> \n", argv[0]);
    //     return 1;
    // }

    //Init Windows Socket
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0 )
    {
        printf("初始化Windows Socket失败.\n");
        return -1;
    }

    //Create Socket
    hServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( hServer == INVALID_SOCKET )
    {
        printf("创建Server Socket失败.\n");
        return -1;
    }
    memset(&servAddr, 0 , sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi("8888"));

    if (bind(hServer, (SOCKADDR*)&servAddr,
             sizeof(servAddr))== SOCKET_ERROR)
    {
        printf("Server Socket绑定失败.\n");
        return -1;
    }
    if (listen(hServer, 10) == SOCKET_ERROR)
    {
        printf("Server 监听失败.\n");
        return -1;
    }
    int szClntAddr = sizeof(clntAddr);
    hClient = accept(hServer, (SOCKADDR*)&clntAddr, &szClntAddr);
    if (hClient == INVALID_SOCKET)
    {
        printf("Server接受Client失败.\n");
        return -1;
    }
    send(hClient, msg, sizeof(msg), 0);
    system("pause");
    closesocket(hClient);
    closesocket(hServer);
    WSACleanup();
    return 0;
}
