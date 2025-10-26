#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void abort_handler(int sig) {
printf("Caught signal %d (SIGABRT)! Program aborted intentionally.\n", sig);
}
int main() {
signal(SIGABRT, abort_handler);
printf("Program started. PID = %d\n", getpid());
printf("Simulating an error condition...\n");
sleep(2);
abort();
printf("This line will not be executed.\n");
return 0;
}
