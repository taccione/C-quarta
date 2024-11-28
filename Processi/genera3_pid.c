#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int p = fork();

    if (p > 0)
    {
        printf("Sono il padre A, il mio PID = %d\n", getpid());
    }
    else if (p < 0)
    {
        printf("Errore nella generazione dei figli");
    }
    else
    {
        printf("Sono il figlio B, PID = %d, il mio nome e': Qui\n", getpid());
        printf("Sono il figlio C, PID = %d, il mio nome e': Quo\n", getpid());
        printf("Sono il figlio D, PID = %d, il mio nome e': Qua\n", getpid());
    }
}
