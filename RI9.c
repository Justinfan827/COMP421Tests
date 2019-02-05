#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

// Type some and then backspace up to the newline character
int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
    sleep(30);
    exit(0);
}

