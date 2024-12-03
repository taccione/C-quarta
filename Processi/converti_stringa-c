/* Data una stringa letta da riga di comando si scriva un programma in linguaggio C
che istanzi un processo figlio il quale converta la stringa da minuscolo a maiuscolo

esempio di esecuzione:
$./a.out ciao
la stringa in maiuscolo è CIAO */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore argomenti");
        return 0;
    }

    // Dichiarazione delle variabili
    __pid_t pid;
    char stringa[strlen(argv[1])];

    pid = fork();

    if (pid == 0)
    {
        printf("Stringa convertita in maiuscolo: %c\n", toupper(stringa);
        sleep(5);
        exit(0);
    }
    else
    {
        wait(&pid);
    }

    printf("\nProgramma terminato\n");

    return 0;
}
