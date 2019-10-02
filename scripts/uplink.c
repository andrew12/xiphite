#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <netdb.h>
#include <fcntl.h>
#include <stdio.h>

int ptyps_socket() {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  fcntl(sock, O_NONBLOCK);
  return sock;
}

int ptyps_link(int sock, uint16_t port, char* host) {
  struct hostent *he = gethostbyname(host);
  
  if (he == NULL)
    return -2;
  
  struct sockaddr_in addr;
  
  addr.sin_addr = *((struct in_addr *) he->h_addr);
  addr.sin_port = htons(port);
  addr.sin_family = AF_INET;
  
  memset(&addr.sin_zero, '\0', 8);
  
  return connect(sock, (struct sockaddr *) &addr, sizeof(addr));
}

int ptyps_out(int sock, char* text) {
  return send(sock, text, strlen(text), MSG_DONTWAIT);
}

ssize_t ptyps_recv(int sock, void* buffer, size_t size) {
  return recv(sock, buffer, size, 64);
}
