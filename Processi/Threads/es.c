    // Threads

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>

    int main(int argc, char *argv[])
    {
        // Dichiarazione delle variabili
        pid_t p;

        printf("Sono il padre, pid = %d\n", getpid());
        p = fork(); // genero il processo figlio, p = PID del figlio
        // p del figlio sara' uguale a 0

        // if (p > 0) -> padre
        if (p == 0)
        {
            printf("Sono il figlio, PID = %d\n", getpid());
            printf("Mio padre ha PID = %d\n", getppid());
        }

        return 0;
    }
