#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "winsock2.h"
#include "ctype.h"
#include "time.h"

#pragma comment(lib,"WSOCK32")

#define SERVER_PORT 5000
#define DefaultHTML "login.htm"
SOCKET sockfd;


char *r200 = "HTTP/1.0 200\n";
char *r302 = "HTTP/1.0 302 Found\n";
char *notfound ="HTTP/1.0 404 Not Found\n";
char *header = "Content-type: text/html\n";
char *end = "\n";
char *version="0.1.0";


void WriteRedirect(SOCKET connfd,char *loc)
{
time_t now;
char Buffer[1025];

now=time(NULL);
send(connfd,r302,strlen(r302),0);
sprintf(Buffer,"Location: %s\n",loc);
send(connfd,Buffer,strlen(Buffer),0);
sprintf(Buffer,"Server: Web Chat Server %s\n",version);
send(connfd,Buffer,strlen(Buffer),0);
sprintf(Buffer,"Date: %s",ctime(&now)); /* ctime �����ʱ���Զ�����β���\n */
sprintf(Buffer,"Expires: %s",ctime(&now)); /* ctime �����ʱ���Զ�����β���\n */
sprintf(Buffer,"Last-Modified: %s",ctime(&now)); /* ctime �����ʱ���Զ�����β���\n */
send(connfd,Buffer,strlen(Buffer),0);

sprintf(Buffer,"Cache-Control: no-cache\nPragma: no-cache\n");
send(connfd,Buffer,strlen(Buffer),0);
send(connfd,header,strlen(header),0);
send(connfd,end,strlen(end),0);
}


void main()
{
char Server_name[128];
WSADATA wsaData;
struct hostent *hp;
struct sockaddr_in addrServer;
SOCKADDR addrtemp;
int nlen = sizeof(addrtemp); 
SOCKET connfd;
char *data="HTTP/1.1 200 OK\r\nDate: Tue, 21 Sep 2001 02:19:57 GMT\r\nServer: iis5\r\nContent-Type: text/html\r\n\r\n<html><head><title>Untitled Document</title><meta http-equiv='Content-Type' content='text/html; charset=gb2312'></head><body bgcolor=#FFFFFF text=#000000><center><br><br>����һ������</body></html>";

WSAStartup(0x202,&wsaData); //��ʼ��Winsock��Դ
sockfd = socket(AF_INET,SOCK_STREAM,0); //�����׽���
//AF_INET:TCP/IP��ַ��
//SOCK_STREAM:��������ʽ
gethostname(Server_name,128); //��ȡ����������
hp = gethostbyname(Server_name); //ͨ���������ƻ�ȡ��������Ϣ

//��ʼ��sockaddr_in�ṹ
//����IP��ַsin_addr��Э����sinfamily��ʹ�õĶ˿�sin_port
memset(&addrServer,0,sizeof(addrServer));
memcpy(&(addrServer.sin_addr),hp->h_addr,hp->h_length);
addrServer.sin_family = AF_INET;
addrServer.sin_port = htons((unsigned short)SERVER_PORT); 

if(SOCKET_ERROR == bind(sockfd,(LPSOCKADDR)&addrServer,sizeof(addrServer)))
{
printf("Bind Socket Error ! \r\n");
return;
}
else
printf("Bind Socket Success . . .\r\n");


listen(sockfd,5); //��socketServer�ϼ���������Ϣ
printf("Wait for a connection . . .\r\n");



for(;;)
{
  ZeroMemory((void*)&addrtemp,sizeof(addrtemp));
  nlen = sizeof(addrtemp);
  connfd = accept(sockfd,&addrtemp,&nlen); //����������������ר�õĽ���socket
  WriteRedirect(connfd,"chkusrpw.htm");
  closesocket(connfd);
}

closesocket(sockfd);
WSACleanup();
return;
}
