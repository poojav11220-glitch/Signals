#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void signal_handler(int sig) {
    printf("Received signal %d\n", sig);
}
int main() {
    signal(SIGINT, signal_handler);
    printf("Press Ctrl+C to see signal handling...\n");
    while (1) {
        printf("Running... PID: %d\n", getpid());
        sleep(2);
    }
    return 0;
}
