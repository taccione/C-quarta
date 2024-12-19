/* Scrivere un programma C che dato un array prestabilito, prenda in input da
riga di comando un numero e lo ricerchi all'interno dell'array.
La ricerca deve essere demandata ad un processo figlio e deve essere
implementata attraverso un'apposita funzione di nome ricerca. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define DIM 5

void ricerca(int n, int array[])
{
    int cont = 0; // quante volte compare n
    for (int i = 0; i < DIM; i++)
    {
        if (n == array[i])
        {
            cont++;
        }
    }
    printf("Il numero %d compare %d volte\n", n, cont);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore nel numero degli argomenti");
        return 0;
    }

    int array[] = {7, 2, 9, 4, 1};
    printf("Contenuto dell'array: ");
    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", array[i]);
    }

    pid_t pid, padre;
    int numero = atoi(argv[1]);

    if (pid == 0) // dentro il figlio
    {
        padre = getppid();
        printf("Mio padre ha pid: %d\n", padre);
        ricerca(numero, array);
        sleep(5);
        exit(0); // termina il processo figlio
    }
    else
    {
        wait(&pid);
    }

    printf("\n\nProgramma terminato\n\n");

    return 0;
}
