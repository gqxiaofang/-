#include <stdio.h>
#include <winsock2.h>
#include <Windows.h>

#define  PORT 8888
#define  IP_ADDRESS "127.0.0.1"
#define  MAX_LEN 1024

int main(int argc, char* argv[])
{
    WSADATA  Ws;
    SOCKET hClient;
    struct sockaddr_in ServerAddr;
    int Ret = 0;

    char SendBuffer[MAX_LEN];
    char RecvBuffer[MAX_LEN];
    //Init Windows Socket
    if (WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
    {
        printf("Init Windows Socket Failed.");
        return -1;
    }
    //Create Socket
    hClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( hClient == INVALID_SOCKET )
    {
        printf("Create Socket Failed.");
        return -1;
    }
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    ServerAddr.sin_port = htons(PORT);

    Ret = connect(hClient,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if ( Ret == SOCKET_ERROR )
    {
        printf("Connect Error.");
        return -1;
    }
    else
    {
        printf("Connect OK!");
    }

    while ( 1 )
    {
        fgets(SendBuffer, sizeof(SendBuffer), stdin);
        Ret = send(hClient, SendBuffer, (int)strlen(SendBuffer), 0);
        if ( Ret == SOCKET_ERROR )
        {
            printf("Send Info Error.");
            break;
        }
        Ret = recv(hClient, RecvBuffer, sizeof(RecvBuffer), 0);
        if (Ret == SOCKET_ERROR)
        {
            printf("Recv Info Error.");
            break;
        }
        printf("Received data: %s.\n", RecvBuffer);
        memset(RecvBuffer, 0, MAX_LEN);
    }
    system("pause");
    closesocket(hClient);
    WSACleanup();
    return 0;
}
