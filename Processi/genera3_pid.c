#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Dichiarazione delle variabili
    int b = fork();

    printf("Io sono il padre A, il mio PID = %d\n", getpid());
    if (b > 0) // dentro B
    {
        int c = fork();
        if (c == 0) // dentro C
        {
            printf("Io sono il figlio C, il mio PID = %d, il mio nome è Quo\n", getpid());
        }
        else if (c > 0)
        {
            int d = fork();
            if (d == 0) // dentro D
            {
                printf("Io sono il figlio D, il mio PID = %d, il mio nome è Qua\n", getpid());
            }
        }
        else
        {
            printf("Errore nella generazione del figlio C");
        }
    }
    else if (b == 0)
    {
        printf("Io sono il figlio B, il mio PID = %d, il mio nome è Qui\n", getpid());
    }
    else
    {
        printf("Errore nella fork del figlio B");
    }

    return 0;
}
