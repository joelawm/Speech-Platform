/* ****************
Jarvis Speech Drive
Created By: Joe Meyer
Purpose: Add networking functionality to speak to a python application, as well as add fucntons for cluster programming.
***************** */
#ifndef NETWORK_H
#define NETWORK_H
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 2340

struct sockaddr_in address;

class Network
{
public:
	//variables
	int server_fd, new_socket, valread;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };
	char *hello = "Hello from server";
	//functions
	void createSocket();
	void manageSockets();
	void send();
	void read();
};

void Network::manageSockets()
{

}

//this funcction creates the sockets to be used. It creates not manages all of them.
void Network::createSocket()
{
	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
		&opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address,
		sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
		(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
}

void Network::read()
{
	valread = read(new_socket, buffer, 1024);
}

void Network::send()
{
	send(new_socket, hello, strlen(hello), 0);
}
#endif