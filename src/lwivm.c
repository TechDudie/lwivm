#include <stdio.h>
int main(int argc, char *argv[]) {
    //This is not a official processor, this is a test 1600 with some modifications.
    unsigned char program[256];
    FILE *ptr;
    ptr = fopen(argv[1],"rb");
    fread(program,sizeof(program), 1, ptr);
    for (int i = 0; i < 255; i++) {
        //TODO
        i++;
    }
    return 0;
}