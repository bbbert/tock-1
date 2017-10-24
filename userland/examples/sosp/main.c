#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <timer.h>
#include <console.h>
#include <ambient_light.h>

char buf[300];

static void print_complete(int a __attribute__((unused)),
                           int b __attribute__((unused)),
                           int c __attribute__((unused)),
                           void* d __attribute__((unused)))
{
  // The message has been printed to the console
}

int main(void)
{
  int n = snprintf(buf, sizeof(buf), "From tock app: \"%s\"\n", "Hello, World!");
  putnstr_async(buf, n, print_complete, NULL);

  return 0;
}
