 
#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<arpa/inet.h> 
 
int main() 
{ 
    int s; 
    struct sockaddr_in server; 
    char buffer[100]; 
 
    s = socket(AF_INET, SOCK_STREAM, 0); 
 
    server.sin_family = AF_INET; 
    server.sin_port = htons(5000); 
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
 
    connect(s, (struct sockaddr*)&server, sizeof(server)); 
 
    read(s, buffer, sizeof(buffer)); 
 
    printf("Server Time: %s", buffer); 
 
    close(s); 
 
    return 0; 
} 
