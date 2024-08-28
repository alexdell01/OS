// PROBLEM 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main(int argc, char *argv[])
{

    int x = 100;

    printf("hello world (pid:%d), x=%d\n", (int) getpid(),x);

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n, x=%d\n", (int) getpid(),x);
        x = 200; //can comment out to test
        printf("hello, I am MODDED child (pid:%d)\n, x=%d\n", (int) getpid(),x);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n, n, x=%d\n", rc, (int) getpid(),x);
        x = 300; //can comment out to test
        printf("hello, I am MODDED parent of %d (pid:%d)\n, n, x=%d\n", rc, (int) getpid(),x);
    }

        //Parent + Child 
	    printf("process (pid:%d): final x equals: %d\n", (int) getpid(),x);
    
    return 0;
} 


// values in child/parent proccess stay at 100 if you do not change them.
// if you change them, they correspond to values you put in them




