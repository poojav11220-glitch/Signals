#include <stdio.h>
#include <signal.h>
#include <string.h>

int main() {
    printf("Signals available on this system:\n");

    for (int i = 1; i < NSIG; i++) {
        printf("%2d: %s\n", i, strsignal(i));
    }

    return 0;
}
