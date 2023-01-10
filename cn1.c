//Write a program to implement RSA algorithm.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
unsigned long modexp(unsigned long msg,unsigned long exp,unsigned long n)
{
unsigned long i,k=1;
for(i=0;i<exp;i++)
k=(k*msg)%n;
return k;
}
int main()
{
unsigned long p,q,e,d,n,z,i,m,c;
int len;
char data[100];
printf("enter the value of p & q such that p*q>255\n");
scanf("%lu%lu",&p,&q);
n=p*q;
z=(p-1)*(q-1);
for(i=1;i<z;i++)
{
if((z%i)==0)
continue;
else
break;
}
e=i;
printf("\nencryption key is=%lu",e);
for(i=1;i<z;i++)
if(((e*i-1)%z)==0)
break;
d=i;
printf("\ndecryption key is=%lu",d);
printf("\nenter the msg:");
scanf("%s",data);
len=strlen(data);
for(i=0;i<len;i++)
{m=(unsigned long) data[i];
c=modexp(m,e,n);
printf("\nencrypted key and its representation is %lu\t%c\n",c,c);
m=modexp(c,d,n);
printf("\ndecrypted key and its representation is %lu\t%c\n",m,m);
}
printf("\n decrypted msg is %s\n%lu\n%lu",data,c,m);
}



/*OUTPUT
(base) [dr.d01@fedora CNlab]$ gcc cn1.c
(base) [dr.d01@fedora CNlab]$ ./a.out
enter the value of p & q such that p*q>255
5
3

encryption key is=3
decryption key is=3
enter the msg:danish

encrypted key and its representation is 10	


decrypted key and its representation is 10	


encrypted key and its representation is 13	

decrypted key and its representation is 7	

encrypted key and its representation is 5	

decrypted key and its representation is 5	

encrypted key and its representation is 0	

decrypted key and its representation is 0	

encrypted key and its representation is 10	


decrypted key and its representation is 10	


encrypted key and its representation is 14	

decrypted key and its representation is 14	

 decrypted msg is danish
14
*/
