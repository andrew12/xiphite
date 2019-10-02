#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

char* ptyps_format(char* format, ...) {
  va_list(argl);
  va_start(argl, format);
  
  int len = vsnprintf(NULL, 0, format, argl);
  len++; // strings are defined by ending with \0
  
  va_start(argl, format);
  
  char* buffer = malloc(len);
  
  vsnprintf(buffer, len, format, argl);
  va_end(argl);
  
  return buffer;
}

void ptyps_echo(char* format,...) {
  va_list(argl);
  va_start(argl, format);
  vfprintf(stdout, format, argl);
  va_end(argl);
}

void ptyps_log(char* format,...) {
  va_list(argl);
  va_start(argl, format);
  vfprintf(stdout, format, argl);
  va_end(argl);
  fprintf(stdout, "\n");
}

int ptyps_strcnt(char* dl, char* text) {
  int count = 0;
  
  for (int i = 0; i < strlen(text); i++)
    if (text[i] == *dl)
      count++;
  
  return count;
}

int ptyps_strstrw(char* text, char* pre) {
  return strncmp(pre, text, strlen(pre)) == 0;
}