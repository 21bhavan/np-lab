#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<arpa/inet.h> 
 
struct data{ 
    int a,b,c; 
}; 
 
struct result{ 
    int sum,diff,prod; 
}; 
 
 
 
 
int main() 
{ 
    int s; 
    struct sockaddr_in server; 
 
    struct data d; 
    struct result r; 
 
    s=socket(AF_INET,SOCK_STREAM,0); 
 
    server.sin_family=AF_INET; 
    server.sin_port=htons(5000); 
    server.sin_addr.s_addr=inet_addr("127.0.0.1"); 
 
    connect(s,(struct sockaddr*)&server,sizeof(server)); 
 
 printf("Enter 3 numbers: "); 
    scanf("%d%d%d",&d.a,&d.b,&d.c); 
 
    send(s,&d,sizeof(d),0); 
 
    recv(s,&r,sizeof(r),0); 
 
    printf("Sum = %d\n",r.sum); 
    printf("Difference = %d\n",r.diff); 
    printf("Product = %d\n",r.prod); 
 
    close(s); 
} 
