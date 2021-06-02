#include <ws2tcpip.h>
#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma comment(lib, "ws2_32.lib")

#define bzero(a, b)             memset(a, 0, b)


#define  PORT 6000
 
int main(int argc, char* argv[])
{
	//��ʼ�����绷��
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("WSAStartup failed\n");
		return -1;
	}
 
	//����һ��UDP��socket
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock == SOCKET_ERROR)
	{
		printf("create socket failed\n");
		return -1;
	}
 
	//�󶨵�ַ��Ϣ
	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
 
	bind(sock, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr));
	
	char buf[512];
	while (TRUE)
	{
		memset(buf, 0, 512);
		// ����ڵ����Ϣ����������ͻ��˵�������Ϣ
		struct sockaddr_in clientAddr;
		memset(&clientAddr, 0, sizeof(struct sockaddr_in));
 
		int clientAddrLen = sizeof(struct sockaddr);
		//���տͻ��˷���������
		int ret = recvfrom(sock, buf, 512, 0,(struct sockaddr*) &clientAddr,&clientAddrLen );
		
		printf("Recv msg:%s from IP:[%s] Port:[%d]\n", buf,inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port));
		// ��һ�����ݰ����ظ��ͻ�
        memset(buf,0,512);
        scanf("%s",buf);
		sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&clientAddr, clientAddrLen);
		printf("Send msg back to IP:[%s] Port:[%d]\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
	}
    system("pause");
	return 0;
}