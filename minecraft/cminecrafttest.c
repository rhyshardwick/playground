//
//  Experimenting using sockets in C with minecraft pi
//
//  Rhys Hardwick
//

#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h> // inet_addr

int main(int argc, char *argv[])
{
	int debug = 1;
	int socket_desc;
	struct sockaddr_in server;
	char *message;
	
	// Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(4711);
	
	// Connect to server
	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	
	if (debug == 1)
	{
		puts("Connected to server");
	}
	
	message = "player.setPos(100,100,100)\n";
	if( send(socket_desc , message , strlen(message), 0) <0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Sent");
	
	
	return 0;
}
