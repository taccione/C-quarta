// Threads

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // Dichiarazione delle variabili
    pid_t figlio, padre;
    figlio = fork();

    if (figlio == 0) // dentro il figlio
    {
        padre = getppid();
        printf("Mio padre ha pid: %d\n", padre);
        sleep(5);
        exit(0);
    }
    else
    {
        wait(&figlio);
    }

    printf("\n\nProgramma terminato\n\n");

    return 0;
}
