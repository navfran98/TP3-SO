#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080
   
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    //char *hello = "entendido\n"; 
    char buffer[1024] = {0}; 

    char * mensaje;
    pid_t readingPid;

    //char* fgets(mensaje, 200, stdin);

   


            if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
            { 
                printf("\n Socket creation error \n"); 
                return -1; 
            } 
           
            serv_addr.sin_family = AF_INET; 
            serv_addr.sin_port = htons(PORT); 
           // serv_addr.sin_addr = inet_addr("0.0.0.0");
               
            // Convert IPv4 and IPv6 addresses from text to binary form 
            if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
            { 
                printf("\nInvalid address/ Address not supported \n"); 
                return -1; 
            } 
           
            if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
            { 
                printf("\nConnection Failed \n"); 
                return -1; 
            } 

            readingPid = fork();
            if(readingPid == 0){
                while(1){
                    if(read(sock, buffer, 1024)){
                        printf("Received: \"%s\"\n", buffer);
                    }
                }

            }else if(readingPid > 0){
                while(1){
                    if(fgets(mensaje, 1024, stdin)){
                        send(sock, mensaje, strlen(mensaje), 0);
                    }
                }

            }else{  
                printf("ERROR!\n");


            }
            close(sock);
            return 1;

           /* send(sock , mensaje , strlen(mensaje) , 0 ); 
            printf("Hello message sent\n"); 
            valread = read( sock , buffer, 1024); 
            printf("EEEEEE%s\n",buffer ); 
            
        
    
    printf("dasdsad\n");
    return 0; */
} 