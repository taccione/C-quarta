// Threads

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // Dichiarazione delle variabili
    pid_t pid, padre;
    pid = fork();

    if (pid == 0) // dentro il figlio
    {
        padre = getppid();
        printf("Mio padre ha pid: %d\n", padre);
        sleep(5);
        exit(0); // killato il processo figlio
    }
    else
    {
        wait(&pid);
    }

    printf("\n\nProgramma terminato\n\n");

    return 0;
}
