#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 

#define PORT 8080
#define BUFFER_SIZE 1024
   
int main(int argc, char const *argv[]) 
{ 
    int socket_fd; 
    struct sockaddr_in server_address; 

    char buffer[BUFFER_SIZE] = {'\0'};

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){ 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
    
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(PORT); 
        
    if(inet_pton(AF_INET, "0.0.0.0", &server_address.sin_addr)<=0){ 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
    
    if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){ 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    while(1){
        if(fgets(buffer, 1024, stdin)){
            send(socket_fd, buffer, strlen(buffer), 0);
        }
    }

    close(socket_fd);
    return 1;
} 