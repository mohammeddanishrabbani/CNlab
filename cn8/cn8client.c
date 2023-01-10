#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#define FIFO1_NAME "fifo1"
#define FIFO2_NAME "fifo2"
int main()
{
char p[100],f[100],c[3000];
int num,num2,f1,fd,fd2;
mknod(FIFO1_NAME,S_IFIFO|0666,0);
mknod(FIFO2_NAME,S_IFIFO|0666,0);
printf("\n waiting for server...\n");
fd=open(FIFO1_NAME,O_WRONLY);
printf("\n SERVER ONLINE !\n CLIENT:Enter the path\n");
while(gets(p),!feof(stdin))
{
if((num=write(fd,p,strlen(p)))==-1)
perror("write error\n");
else
{
printf("Waiting for reply....\n");
fd2=open(FIFO2_NAME,O_RDONLY);
if((num2=read(fd2,c,3000))==-1)
perror("Transfer error!\n");
else{
printf("File recieved! displaying the contents:\n");
if(fputs(c,stdout)==EOF)
perror("print error\n");
exit(1);
}
}
}
}


/*OUTPUT
(base) [dr.d01@fedora cn8]$ gcc cn8client.c
cn8client.c: In function ‘main’:
cn8client.c:20:7: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
   20 | while(gets(p),!feof(stdin))
      |       ^~~~
      |       fgets
/usr/bin/ld: /tmp/ccvDqhdY.o: in function `main':
cn8client.c:(.text+0x133): warning: the `gets' function is dangerous and should not be used.
(base) [dr.d01@fedora cn8]$ ./a.out

 waiting for server...

 SERVER ONLINE !
 CLIENT:Enter the path
cn8client.c
Waiting for reply....
File recieved! displaying the contents:
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#define FIFO1_NAME "fifo1"
#define FIFO2_NAME "fifo2"
int main()
{
char p[100],f[100],c[3000];
int num,num2,f1,fd,fd2;
mknod(FIFO1_NAME,S_IFIFO|0666,0);
mknod(FIFO2_NAME,S_IFIFO|0666,0);
printf("\n waiting for server...\n");
fd=open(FIFO1_NAME,O_WRONLY);
printf("\n SERVER ONLINE !\n CLIENT:Enter the path\n");
while(gets(p),!feof(stdin))
{
if((num=write(fd,p,strlen(base) [dr.d01@fedora cn8]$ 

*/
