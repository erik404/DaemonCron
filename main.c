#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
  
    char * paramsList[] = { "/usr/bin/php", "-c", "/usr/bin/php /home/erikjan/PHPProjects/test/test.php", NULL };
    execv("/bin/bash", paramsList); 
    
    // if we get here it misfired
    perror("PHP execution");
}