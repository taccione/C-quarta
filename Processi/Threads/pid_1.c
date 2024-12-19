#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p = fork(); // genero processo figlio ; p = PID del figlio
                    // p del figlio sarà uguale a 0

    if (p > 0)
    {
        printf("Sono il padre, mio figlio ha PID = %d\n", p);
    }
    else if (p < 0)
    {
        printf("Errore nella generazione del figlio\n");
    }
    else
    {
        printf("Sono il figlio, PID = %d ", getpid());
        printf("Mio padre ha PID = %d", getppid());
    }

    return 0;
}
