#include <stdio.h>
int main(int argc, char *argv[]) {
    //This is not a official processor, this is a test 1600 with some modifications.
    //Check if nothing is specified
    if (argc == 1) {
        printf("Syntax: ./lwivm");
    }
    //Define variables
    unsigned char program[256];
    unsigned char RAM[256];
    unsigned char registers[16];
    char flag = 0;
    //Open program
    FILE *ptr;
    ptr = fopen(argv[1],"rb");
    //Read it
    fread(program,sizeof(program), 1, ptr);
    //Begin execution
    for (int i = 0; i < 255; i++) {
        char byte = program[i];
        char param = program[i + 1];
        int instruction = (int)(byte & 0b11100000) / 32; //the magic number
        int bit = (int)(byte & 0b00010000) / 16; //the magic number
        int extra = (int)(byte & 0b00001111); //no magic number
        int param1 = (int)(param & 0b11110000) / 16; //the magic number
        int param2 = (int)(param & 0b00001111); //no magic number
        printf("%u",instruction); //debug
        if (instruction == 0) {
            //ldr
            registers[extra] = param;
            if (bit) {
                registers[extra] = RAM[param];
            }
        }
        if (instruction == 1) {
            //str
            RAM[param] = registers[extra];
        }
        if (instruction == 2) {
            //add
            registers[extra] = ((int)registers[param1] + (int)registers[param2]) % 256;
        }
        if (instruction == 3) {
            //sub
            registers[extra] = ((int)registers[param1] + (int)registers[param2]) % 256;
        }
        if (instruction == 4) {
            //and
            registers[extra] = (int)registers[param1] & (int)registers[param2];
        }
        if (instruction == 5) {
            //not
            registers[extra] = ~(int)registers[param1];
        }
        if (instruction == 6) {
            //cmp
            flag = 0;
            if (registers[param1] == registers[param2]) {
                flag = 1;
            }
        }
        if (instruction == 7) {
            //jeq
            if (flag != 0){
                i = param;
                registers[15] = i;
            }
        }
        i++; //double increment
        registers[15] = registers[15] + 2; //program counter (R15)
    }
    return 0;
}
