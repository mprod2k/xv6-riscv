#include "kernel/types.h"
#include "user/user.h"
#define BUFFERSZ 500
int
main(int argc, char **argv)
{
char *buffer;
char *heap_ptr;
heap_ptr = getheapptr();
printf("Heap Before Malloc: %p\n", getheapptr());
printf("Process is using: %ld bytes\n\n", (uint64)heap_ptr);
buffer = malloc(sizeof(char) * BUFFERSZ + 1);
/* Print the Alphabet over and over */
for (int i = 0; i < BUFFERSZ; i++) buffer[i] = 'a' + (i % 26);
buffer[BUFFERSZ] = '\0';
printf("My buffer at %p contains: %s\n\n", buffer, buffer);
heap_ptr = getheapptr();
printf("Heap After Malloc: %p\n", getheapptr());
printf("Process is using: %ld bytes\n\n", (uint64)heap_ptr);
free(buffer);
heap_ptr = getheapptr();
printf("Heap After Free: %p\n", heap_ptr);
printf("Process is using: %ld bytes\n", (uint64)heap_ptr);
return 0;
}