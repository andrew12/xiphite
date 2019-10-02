#include <string.h>

#define ptyps_strech(dl, next, array) \
  for (next = strtok(array, dl); next != NULL; next = strtok(NULL, dl))

extern char* ptyps_format(char* format, ...);
extern void ptyps_echo(char* format,...);
extern void ptyps_log(char* format,...);
extern int ptyps_strcnt(char* dl, char* text);
extern int ptyps_strstrw(char* text, char* pre);