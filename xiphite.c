#include "uplink.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  int sock = ptyps_socket();

  ptyps_link(sock, 6667, "irc.example.net");

  char buffer[1024];

  while(1) {
    memset(&buffer, '\0', 1024);

    ptyps_recv(sock, buffer, 1024);

    if (strlen(buffer) > 0) {
      char* line;

      ptyps_strech("\r\n", line, buffer) {
        ptyps_log("-> %s", line);
      }
    }
  }
}
