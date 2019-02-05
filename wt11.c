#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void writer1(void *);
void writer2(void *);
void writer3(void *);
// While write terminal is happening, type a bunch of b's and confirm that they all get in there.
char string1[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
char string2[] = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
char string3[] = "ccccccccccccccccccccccccccccccccccccccccccc";
int length1 = sizeof(string1) - 1;
int length2 = sizeof(string2) - 1;
int length3 = sizeof(string3) - 1;

int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    InitTerminal(2);
    InitTerminal(3);
    ThreadCreate(writer1, NULL);
    ThreadCreate(writer2, NULL);
    ThreadCreate(writer3, NULL);
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

    status = WriteTerminal(2, string2, length2);
    if (status != length2)
        fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
                status, length1);
}


void
writer3(void *arg)
{
    int status;

    status = WriteTerminal(3, string3, length3);
    if (status != length3)
        fprintf(stderr, "Error: writer1 status = %d, length1 = %d\n",
                status, length1);
}


