#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void tabellina(int n)
{
    printf("P4: Tabellina del numero %d\n", n);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

void conto_alla_rovescia(int n)
{
    printf("P5: Conto alla rovescia del numero %d\n", n);
    for (int i = n; i >= 0; i--)
    {
        printf("%d\n", i);
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    // Dichiarazione delle variabili
    pid_t P1, pid, P2, P3, P4, P5;
    int n;

    printf("P1: mio PID = %d, mio figlio P2 ha PID = %d\n", P1, getpid());
    do
    {
        printf("P1: Inserisci un numero intero compreso tra 3 e 10 (estremi compresi): ");
        scanf("%d\n", &n);
        if (n < 3 || n > 10)
        {
            printf("Inserisci un numero valido!\n");
        }
    } while (n < 3 || n > 10);

    P2 = fork();
    if (P2 == 0) // dentro p2
    {
        printf("P2: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
        exit(0);
    }
    P3 = fork();

    if (P3 == 0) // dentro p3
    {
        printf("P3: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
        P4 = fork();
        P5 = fork();
        tabellina(n);

        if (P4 == 0)
        {
            printf("P4: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
            exit(0);
        }

        if (P5 == 0)
        {
            printf("P5: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
            conto_alla_rovescia(n);
            exit(0);
        }
        exit(0);
    }

    printf("\n\nProgramma terminato\n\n");

    return 0;
}
