#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void handler(int sig){
switch(sig){
case SIGINT:
printf("Received SIGINT(Ctrl+C)\n");
break;
case SIGTERM:
printf("Received SIGTERM(kill -15)\n");
break;
case SIGUSR1:
printf("Received SIGUSR1(kill -10)\n");
break;
case SIGUSR2:
printf("Received SIGUSR2(kill -12)\n");
break;
case SIGCHLD:
printf("Received SIGCHLD(child terminated)\n");
break;
default:
printf("Received signal %d\n", sig);
break;
}
}
int main(){
printf("My PID:%d\n", getpid());
printf("Send signal using 'Kill -SIGNAL %d'\n",getpid());
signal(SIGINT, handler);
signal(SIGTERM, handler);
signal(SIGUSR1, handler);
signal(SIGUSR2, handler);
signal(SIGCHLD, handler);
while(1){
printf("Running...PID: %d\n",getpid());
sleep(5);
}
return 0;
}
