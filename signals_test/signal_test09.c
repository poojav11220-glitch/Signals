#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void term_handler(int sig) {
printf("\nCaught signal %d (SIGTERM)\n", sig);
printf("Performing cleanup before exiting...\n");
sleep(2);
printf("Cleanup done. Exiting now.\n");
exit(0);
}
int main()
{ 
signal(SIGTERM, term_handler);
printf("Program running with PID = %d\n", getpid());
printf("Use: kill -15 %d  (or just kill %d) from another terminal to send SIGTERM\n", getpid(), getpid());
while (1) {
printf("Working... (press Ctrl+Z or send SIGTERM to stop)\n");
sleep(3);
}
return 0;
}
