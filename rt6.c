#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void reader1(void *);
void reader2(void *);
void reader3(void *);
void reader4(void *);

int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);

    ThreadCreate(reader1, NULL);
    ThreadCreate(reader2, NULL);
    ThreadCreate(reader3, NULL);
    ThreadCreate(reader4, NULL);

    ThreadWaitAll();

    exit(0);
}

void
reader1(void *arg)
{
    char buf1[2];
    char buf2[10];
    char buf3[10];
    char buf4[10];
    ReadTerminal(1, buf1, 2);
    printf("1.1 read in %s", buf1);
    ReadTerminal(1, buf2, 10);
    printf("1.2 read in %s", buf2);
    ReadTerminal(1, buf3, 10);
    printf("1.3 read in %s", buf3);
    ReadTerminal(1, buf4, 10);
    printf("1.4 read in %s", buf4);
}
void
reader2(void *arg)
{
    char buf[10];

    ReadTerminal(1, buf, 10);
    printf("2.1 read in %s", buf);
}
void
reader3(void *arg)
{
    char buf[10];

    ReadTerminal(1, buf, 10);
    printf("3.1 read in %s", buf);
}
void
reader4(void *arg)
{
    char buf[10];

    ReadTerminal(1, buf, 10);
    printf("4.1 read in %s", buf);
}


