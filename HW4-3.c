//PROBLEM 3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);


    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child 1 (pid:%d)\n", (int) getpid());
 sleep(1);
    exit(0);


    } else {
        // parent goes down this path (original process)
        int wc = waitpid(rc, NULL, 0);
        printf("hello, I am parent of child 1 %d (wc:%d) (pid:%d)\n",rc, wc, (int) getpid());


//Process 1 Ends:

// Process 2 Starts:

      
    int rc1 = fork();
    if (rc1 < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);


    } else if (rc1 == 0) {
        // child (new process)
        printf("hello, I am child 2 (pid:%d)\n", (int) getpid());
	sleep(1);
    exit(0);

      
    } else {
        // parent goes down this path (original process)
        int wc1 = waitpid(rc1, NULL, 0);
        printf("hello, I am parent of 2 %d (wc:%d) (pid:%d)\n",rc1, wc1, (int) getpid());
    }


      
   printf("hello, I am parent boffum (pid:%d) both children are done", (int) getpid());
    return 0;
}
}
