#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

// Type characters and then backspace
int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    HardwareInputSpeed(1, .1);
    sleep(30);
    exit(0);
}

