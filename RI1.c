#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

// Type characters in here and make sure that they work :)
int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    sleep(30);
    exit(0);
}