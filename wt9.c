#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void writer1(void *);
// Reduce the size of the read buffer and overfill it
char string1[] = "ab";
int length1 = sizeof(string1) - 1;

int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer1, NULL);
    sleep(5);

    ThreadWaitAll();

    exit(0);
}

void
writer1(void *arg)
{
    int status;

    status = WriteTerminal(1, string1, length1);
    if (status != length1)
        fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
                status, length1);
}

