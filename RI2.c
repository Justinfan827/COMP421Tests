#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

// Type letters, make sure they work
int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    HardwareOutputSpeed(1, 10000);
    sleep(30);
    exit(0);
}

