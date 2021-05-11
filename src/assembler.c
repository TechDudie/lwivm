#include <stdio.h>
int main(int argc, char *argv[]) {
    unsigned char program[65536];
    FILE *ptr;
    ptr = fopen(argv[1],"r");
    fread(program,sizeof(program), 1, ptr);
    char line[16][65536];
    char *ptr;
    int counter;
    ptr = strtok(program,"\n");
    while (ptr != NULL) {
        snprintf(line[counter], 16, "%s", ptr);
        ptr = strtok(NULL, "\n");
        counter++;
    }
    return 0;
}
