#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sig_handler(int signum){
printf("Inside handle function\n");
alarm(2);
}
int main(){
signal(SIGALRM, sig_handler);
alarm(2);
for(int i=1;  ; i++){
printf("%d : Inside main function\n",i);
sleep(1);
}
return 0;
}
