#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>


#define PORT 3550

int main(int argc, char const *argv[])
{
	char inputbuffer[2] = "f";
	int sockfd, clientfd;
	int sin_size;
	struct sockaddr_in serveraddr;
	struct sockaddr_in clientaddr;
	char buff[512];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&buff, 512);
	memset(&serveraddr, 0, sizeof(struct sockaddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);
	serveraddr.sin_addr.s_addr = INADDR_ANY;


	bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr));


	listen(sockfd, 20);

	sin_size = sizeof(struct sockaddr_in);
	clientfd = accept(sockfd, (struct sockaddr *) &clientaddr, &sin_size);
		
	recv(clientfd, buff, 512, 0);
	printf("%s\n", buff);

	close(clientfd);
	close(sockfd);

	return 0;
}