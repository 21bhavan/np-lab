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
    int s,ns; 
    struct sockaddr_in server,client; 
 
gcc server2.c -o server 
gcc client2.c -o client 
./server 
 
./client 
 
    socklen_t len=sizeof(client); 
 
    struct data d; 
    struct result r; 
 
    s=socket(AF_INET,SOCK_STREAM,0); 
 
    server.sin_family=AF_INET; 
    server.sin_port=htons(5000); 
    server.sin_addr.s_addr=INADDR_ANY; 
 
  bind(s,(struct sockaddr*)&server,sizeof(server)); 
    listen(s,1); 
 
    ns=accept(s,(struct sockaddr*)&client,&len); 
 
    recv(ns,&d,sizeof(d),0); 
 
    r.sum=d.a+d.b+d.c; 
    r.diff=d.a-d.b-d.c; 
    r.prod=d.a*d.b*d.c; 
    send(ns,&r,sizeof(r),0) 
    close(ns); 
    close(s); 
} 
