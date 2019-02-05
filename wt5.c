#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void writer1(void *);
void reader1(void *);
// Add print statements at end of writer and beginning of reader to confirm correct order they happen in
char string1[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
int length1 = sizeof(string1) - 1;

int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);

    ThreadCreate(writer1, NULL);
    sleep(1);
    sleep(2);

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
    reader1(NULL);
}

void
reader1(void *arg)
{
    char buf[10];
    ReadTerminal(1, buf, 10);
}

