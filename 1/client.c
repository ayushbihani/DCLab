#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include <arpa/inet.h> 
#include<sys/socket.h>

int main()
{
    int sock, cs, len;
    struct sockaddr_in client;
    char buf[50], buf1[50];
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    client.sin_port = htons(5000);

    int connection = connect(sock,(struct sockaddr *)&client,sizeof(client));
    {
        puts("connected to server");
        puts("Enter message");
        fgets(buf,50,stdin);
        send(sock,buf,50,0);
        close(sock);
    }
    return 0;
}