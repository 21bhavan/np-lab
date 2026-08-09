#include<stdio.h> 
#include<unistd.h> 
#include<netinet/in.h> 
#include<netinet/tcp.h> 
 
int main() 
{ 
    int s,opt; 
    socklen_t len=sizeof(opt); 
 
    FILE *fp=fopen("options.txt","w"); 
 
    s=socket(AF_INET,SOCK_STREAM,0); 
 
    getsockopt(s,IPPROTO_IP,IP_TTL,&opt,&len); 
    fprintf(fp,"IP Layer Option (TTL) = %d\n",opt); 
 
    getsockopt(s,IPPROTO_TCP,TCP_NODELAY,&opt,&len); 
    fprintf(fp,"TCP Layer Option (NODELAY) = %d\n",opt); 
 
    fclose(fp); 
    close(s); 
 
    printf("Options written to options.txt\n"); 
}
