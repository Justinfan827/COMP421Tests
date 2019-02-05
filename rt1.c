#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void reader1(void *);

int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);

    ThreadCreate(reader1, NULL);

    ThreadWaitAll();

    exit(0);
}

void
reader1(void *arg)
{
    char buf[10];

    ReadTerminal(1, buf, 10);
    printf("read in %s", buf);
}
