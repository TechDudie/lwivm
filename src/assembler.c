#include <stdio.h>
int main(int argc, char *argv[]) {
    unsigned char program[65536];
    FILE *ptr;
    ptr = fopen(argv[1],"r");
    fread(program,sizeof(program), 1, ptr);
    char line[16][65536];
    char *str;
    int counter;
    str = strtok(program,"\n");
    while (str != NULL) {
        snprintf(line[counter], 16, "%s", str);
        str = strtok(NULL, "\n");
        counter++;
    }
    return 0;
}
