#include <stdio.h>
#include <stdlib.h>

void win() {
    printf("You won! Flag: FLAG{ret2win_overwrite_the_return_address}\n");
    fflush(stdout);
}

void vuln() {
    char buf[64];
    printf("Enter your name: ");
    scanf("%s", buf);
    printf("Hello, %s\n", buf);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    return 0;
}