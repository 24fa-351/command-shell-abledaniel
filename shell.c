#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE 1000

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char cwd[MAX_LINE]; 

    while (1) {
        printf("myshell> ");

        if (fgets(line, MAX_LINE, stdin) == NULL) {
            break; 
        }

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "exit") == 0 || strcmp(line, "quit") == 0) {
            break;
        }

        if (strcmp(line, "pwd") == 0) {
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            } else {
                perror("pwd");
            }
            continue;
        }

        if (strncmp(line, "cd ", 3) == 0) {
            char *path = line + 3; // Get the path argument
            if (chdir(path) != 0) {
                perror("cd");
            }
            continue;
        }

        printf("Command not implemented: %s\n", line);
    }

    return 0;
}
