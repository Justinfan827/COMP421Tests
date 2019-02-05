#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void writer1(void *);
void writer2(void *);
// Reduce the size of the output buffer and overfill it
char string1[] = "aaa";
char string2[] = "bbb";
int length1 = sizeof(string1) - 1;

int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer2, NULL);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer2, NULL);
    ThreadCreate(writer1, NULL);
    sleep(10);

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

void
writer2(void *arg)
{
    int status;

    status = WriteTerminal(1, string2, length1);
    if (status != length1)
        fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
                status, length1);
}

