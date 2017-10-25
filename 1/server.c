#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
int main()
{
    int sock, cs, len;
    struct sockaddr_in client, server;
    char buf[50];
    pid_t pid;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5000);
    bind(sock,(struct sockaddr *)&server, sizeof(server));
    puts("Binding done");
    puts("listening on port 5000");
    listen(sock,5);

    while(1) //Wait for connection to be made
    {
        len = sizeof(client);
        cs = accept(sock,(struct sockaddr*)&client, &len);
        puts("Connected to client");
        if((pid=fork())==0)
        {
            puts("Child created");
            close(sock);
            recv(cs,buf,50,0);
            fputs(buf, stdout);
            close(cs);
            exit(EXIT_SUCCESS);
        }
        close(cs);
    }
    return 0;
}
