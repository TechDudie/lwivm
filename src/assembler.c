#include <stdio.h>
int main(int argc, char *argv[]) {
    unsigned char program[2147483648];
    FILE *ptr;
    ptr = fopen(argv[1],"r");
    fread(program,sizeof(program), 1, ptr);
    return 0;
}