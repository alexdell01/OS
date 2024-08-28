// PROBLEM 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
        printf("hello, I am child (pid:%d)\n", (int) getpid());

        execl("bin/ls", "ls", NULL);    

        char *envp[] = {NULL};
        execle("/bin/ls", "ls", NULL, envp);

        execpl("ls",)
          
        printf("this shouldn't print out");
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;
}

// These exec()'s are all just different varfients of the same thing, essentially just letting you slightly modify how you want to access the path. Some 
//allow for searching the entire path, while others may only allow for a path to be searched via array, arguments, enviornments, etc... 
