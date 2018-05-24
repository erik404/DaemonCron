#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {

    printf("Parent process started (pid:%d)\n", getpid());

    pid_t pid = fork();

    if (pid < 0) { // check if fork succeeded
        printf("fork failed!\n");
        exit(1);
    }

    if (pid > 0) { // parent process
        printf("Spawned child (pid:%d)\nTerminating parent process (pid:%d)\n", pid, getpid());
        exit(0); // terminate the parent process successfully
    }

    umask(0); // un-mask inherited file modes
    
    pid_t sid = setsid(); // set new session
    
    // close standard inputs, daemon process does not involve user interaction
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    FILE *fp = fopen("test.txt", "a");
    int i = 0;
    while(i < 10) {
        sleep(1);
        fprintf(fp, "TEST%d\n", i);
        i++;
    }
    fclose(fp);
    
    return(0);
}

void executePhpScript(char* script) {
        char * paramsList[] = { 
            "/usr/bin/php", 
            "-c", 
            script, 
            NULL 
        };
        execv("/bin/bash", paramsList); 
}