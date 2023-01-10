#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include <stdlib.h>
void error(char *msg)
{
perror(msg);
exit(0);
}
int main(int argc,char *argv[])
{int sockfd,portno,n;
struct sockaddr_in serv_addr;
struct hostent *server;
char filepath[256],buf[3000];
if(argc < 3)
{
fprintf(stderr,"usage %s hostname port\n",argv[0]);
exit(0);
}
portno=atoi(argv[2]);
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
error("\nerror in opening socket");
printf("\nclient online");
server=gethostbyname(argv[1]);
if(server==NULL)
{
fprintf(stderr,"error ,no such host");
exit(0);
}
printf("\n server online");
bzero((struct sockaddr_in *)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
serv_addr.sin_port=htons(portno);
if(connect(sockfd,(struct sockaddr_in*)&serv_addr,sizeof(serv_addr))<0)
error("error writing to socket");
printf("\nclient:enter path with filename:\n");
scanf("%s",filepath);
n=write(sockfd,filepath,strlen(filepath));
if(n<0)
error("\nerror writing to socket");
bzero(buf,3000);
n=read(sockfd,buf,2999);
if(n<0)
error("\nerror reading to socket");
printf("\nclient:displaying from socket");

fputs(buf,stdout);
return 0;
}


/*OUTPUT
(base) [dr.d01@fedora cn5]$ gcc cn5client.c
cn5client.c: In function ‘main’:
cn5client.c:39:19: warning: passing argument 2 of ‘connect’ from incompatible pointer type [-Wincompatible-pointer-types]
   39 | if(connect(sockfd,(struct sockaddr_in*)&serv_addr,sizeof(serv_addr))<0)
      |                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                   |
      |                   struct sockaddr_in *
In file included from cn5client.c:3:
/usr/include/sys/socket.h:126:52: note: expected ‘const struct sockaddr *’ but argument is of type ‘struct sockaddr_in *’
  126 | extern int connect (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);
      |                                                    ^
cn5client.c:43:3: warning: implicit declaration of function ‘write’; did you mean ‘fwrite’? [-Wimplicit-function-declaration]
   43 | n=write(sockfd,filepath,strlen(filepath));
      |   ^~~~~
      |   fwrite
cn5client.c:47:3: warning: implicit declaration of function ‘read’; did you mean ‘fread’? [-Wimplicit-function-declaration]
   47 | n=read(sockfd,buf,2999);
      |   ^~~~
      |   fread
(base) [dr.d01@fedora cn5]$ ./a.out 127.0.0.1 8000

client online
 server online
client:enter path with filename:
cn5client.c

client:displaying from socket#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include <stdlib.h>
void error(char *msg)
{
perror(msg);
exit(0);
}
int main(int argc,char *argv[])
{int sockfd,portno,n;
struct sockaddr_in serv_addr;
struct hostent *server;
char filepath[256],buf[3000];
if(argc < 3)
{
fprintf(stderr,"usage %s hostname port\n",argv[0]);
exit(0);
}
portno=atoi(argv[2]);
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
error("\nerror in opening socket");
printf("\nclient online");
server=gethostbyname(argv[1]);
if(server==NULL)
{
fprintf(stderr,"error ,no such host");
exit(0);
}
printf("\n server online");
bzero((struct sockaddr_in *)&serv_addr,sizeof(serv_addr));
serv_addr.sin_family=AF_INET;
bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
serv_addr.sin_port=htons(portno);
if(connect(sockfd,(struct sockaddr_in*)&serv_addr,sizeof(serv_addr))<0)
error("error writing to socket");
printf("\nclient:enter path with filename:\n");
scanf("%s",filepath);
n=write(sockfd,filepath,strlen(filepath));
if(n<0)
error("\nerror writing to socket");
bzero(buf,3000);
n=read(sockfd,buf,2999);
if(n<0)
error("\nerror reading to socket");
printf("\nclient:displaying from socket");
fputs(buf,stdout);
return 0;
}
*/
