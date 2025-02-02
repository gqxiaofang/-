#include <ws2tcpip.h>
#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma comment(lib, "ws2_32.lib")

// #define bzero(a, b)             memset(a, 0, b)

#define  PORT 6000
int main(int argc, char* argv[])
{
	//初始化网络环境
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("WSAStartup failed\n");
		return -1;
	}
	//建立一个UDP的socket
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sockClient == INVALID_SOCKET)
	{
		printf("create socket failed\n");
		return -1;
	}
	// 申明一个网络地址信息的结构体，保存服务器的地址信息
	struct sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
 
	char buf[512] = "client test!";
	//发送数据
	int dwSent = sendto(sockClient, buf, strlen(buf), 0, (SOCKADDR *)&addr, sizeof(SOCKADDR));
	if (dwSent == 0)
	{
		printf("send %s failed\n", buf);
		return -1;
	}
	printf("send msg:%s\n", buf);
 
	char recvBuf[512];
	memset(recvBuf, 0, 512);
 
	struct sockaddr_in addrSever = { 0 };
	int nServerAddrLen=sizeof(struct sockaddr_in);
	// 接收数据
	// int dwRecv = recvfrom(sockClient, recvBuf, 512, 0, (SOCKADDR *)&addrSever,&nServerAddrLen);
	// printf("Recv msg from server : %s\n", recvBuf);
    while(1){
        memset(buf,0,512);
        scanf("%s", buf);
        int dwSent = sendto(sockClient, buf, strlen(buf), 0, (SOCKADDR *)&addr, sizeof(SOCKADDR));
        if (dwSent == 0)
        {
            printf("send %s failed\n", buf);
            return -1;
        }
        printf("send msg:%s\n", buf);

        memset(recvBuf, 0, 512);
        struct sockaddr_in addrSever = { 0 };
        int nServerAddrLen=sizeof(struct sockaddr_in);
        // 接收数据
        int dwRecv = recvfrom(sockClient, recvBuf, 512, 0, (SOCKADDR *)&addrSever,&nServerAddrLen);
        printf("Recv msg from server : %s\n", recvBuf);
    }
	//关闭SOCKET连接
	closesocket(sockClient);
	//清理网络环境
	WSACleanup();
	system("pause");
	return 0;
}