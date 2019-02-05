#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void writer1(void *);
void writer2(void *);
void writer3(void *);
// Type in all of the different windows

int
main(int argc, char **argv)
{
    InitTerminalDriver();

    ThreadCreate(writer1, NULL);
    ThreadCreate(writer2, NULL);
    ThreadCreate(writer3, NULL);

    sleep(30);

    ThreadWaitAll();

    exit(0);
}

void
writer1(void *arg)
{
    InitTerminal(1);
}

void
writer2(void *arg)
{
    InitTerminal(2);
}

void
writer3(void *arg)
{
    InitTerminal(3);
}
