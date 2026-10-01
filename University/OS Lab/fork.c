#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("Parent PID: %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Child PPID: %d\n", getppid());
        printf("Child is running...\n");
        sleep(3);
        printf("Child terminated.\n");
        exit(0);
    } else {
        printf("\n--- Parent Process ---\n");
        printf("Child PID: %d\n", pid);
        printf("Parent is running...\n");
        wait(NULL);
        printf("Parent terminated.\n");
    }

    return 0;
}