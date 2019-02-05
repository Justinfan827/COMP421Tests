#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

// Change size of the echo buffer before running this test and then overflow it
int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    HardwareOutputSpeed(1, 100000);
    sleep(30);
    exit(0);
}

