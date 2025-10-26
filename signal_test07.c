#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void trap_handler(int sig) {
    printf("Caught signal %d (SIGTRAP) — breakpoint or trap detected!\n", sig);
}

int main() {
signal(SIGTRAP, trap_handler);
printf("Program PID = %d\n", getpid());
printf("Raising SIGTRAP manually...\n");
raise(SIGTRAP);
printf("Continuing program after handling SIGTRAP.\n");
while (1) {
printf("Running normally...\n");
sleep(3);
}
return 0;
}
