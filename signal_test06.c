#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void quit_handler(int sig){
printf("\nCaught signal %d(SIGQUIT)\n", sig);
printf("Performing cleanup before exit...\n");
sleep(1);
printf("Goodbye!\n");
exit(0);
}
int main(){
signal(SIGQUIT, quit_handler);
printf("Program PID=%d\n", getpid());
printf("Press Ctrl+\\(backslash)to send SIGQUIT\n");
while(1){
printf("Running... press Ctrl+\\ to quit\n");
sleep(3);
}
return 0;
}
