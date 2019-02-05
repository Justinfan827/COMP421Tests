#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <terminals.h>
#include <unistd.h>

void writer(void *);

// Change the size of your read buffer to 10 and confirm that the overflow is dealt with propersly in
// transmit interrupt
int
main(int argc, char **argv)
{
    InitTerminalDriver();
    InitTerminal(1);
//    HardwareOutputSpeed(1, 100);
    ThreadCreate(writer, NULL);
    exit(0);
}

void writer(void *arg) {
    int status;
    char string[] = "christy elizabeth warden";
    int length = sizeof(string) - 1;
    status = WriteTerminal(1, string, length);
    printf("Returned with status %d", status);
}

