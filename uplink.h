#include <stdint.h>
#include <stddef.h>

typedef signed long long ssize_t;

extern int ptyps_socket(void);
extern int ptyps_link(int sock, uint16_t port, char* host);
extern int ptyps_out(int sock, char* text);
extern ssize_t ptyps_recv(int sock, void* buffer, size_t size);
