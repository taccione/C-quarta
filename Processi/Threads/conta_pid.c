#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p = fork(); // genero processo figlio ; p = PID del figlio
                    // p del figlio sarà uguale a 0
    int conta_padre = 20;
    int conta_figlio = 10;

    if (p > 0)
    {
        printf("Sono il padre, mio figlio ha PID = %d\n", p);
        for (int i = 0; i < conta_padre; i++)
        {
            printf("%d ", i);
        }
        printf("Ho contato fino a 19\n");
    }
    else if (p < 0)
    {
        printf("Errore nella generazione del figlio\n");
    }
    else
    {
        printf("Sono il figlio, PID = %d ", getpid());
        printf("Mio padre ha PID = %d\n", getppid());
        for (int i = 0; i < conta_figlio; i++)
        {
            printf("%d ", i);
        }
        printf("Ho contato fino a 9\n");
    }

    return 0;
}
