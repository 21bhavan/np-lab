#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<arpa/inet.h> 
#include<time.h> 
 
int main() 
{ 
    int s, c; 
    struct sockaddr_in server, client; 
    char *msg; 
    socklen_t len; 
 
    s = socket(AF_INET, SOCK_STREAM, 0); 
 
    server.sin_family = AF_INET; 
    server.sin_port = htons(5000); 
    server.sin_addr.s_addr = INADDR_ANY; 
 
    bind(s, (struct sockaddr*)&server, sizeof(server)); 
 
    listen(s, 1); 
 
    len = sizeof(client); 
    c = accept(s, (struct sockaddr*)&client, &len); 
 
    time_t t = time(NULL); 
    msg = ctime(&t); 
 
    write(c, msg, strlen(msg)); 
 
    close(c); 
    close(s); 
 
    return 0; 
}
