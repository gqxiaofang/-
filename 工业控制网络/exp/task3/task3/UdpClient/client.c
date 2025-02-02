#include <stdio.h>
#include <winsock2.h>
#include <Windows.h>

#pragma comment(lib,"ws2_32.lib")

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;
int main(int argc, char* argv[])
{
    WORD socketVersion = MAKEWORD(2,2);
    WSADATA wsaData;
    if(WSAStartup(socketVersion, &wsaData) != 0)
    {
        return 0;
    }
    SOCKET sclient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    int len = sizeof(sin);

    char * sendData = "来自客户端的数据包.\n";
    sendto(sclient, sendData, strlen(sendData), 0, (sockaddr *)&sin, len);

    char recvData[255];
    int ret = recvfrom(sclient, recvData, 255, 0, (sockaddr *)&sin, &len);
    if(ret > 0)
    {
        recvData[ret] = 0x00;
        printf(recvData);
    }
    system("pause");
    closesocket(sclient);
    WSACleanup();
    return 0;
}