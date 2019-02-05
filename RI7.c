#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

// Type some characters and then backspace
int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    HardwareInputSpeed(1, 10000);
    sleep(30);
    exit(0);
}

