#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

// Before running change READ_BUFFER to 5 and type more than five characters
int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    sleep(30);
    exit(0);
}

