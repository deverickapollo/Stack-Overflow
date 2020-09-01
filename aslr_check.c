#include <stdio.h>
unsigned long find_start(void)
{
    __asm__("movl %esp, %eax");
}

int main()
{
    printf("0x%x\n", find_start()); 
    unsigned long result =0;
    for(int i=0; i<1000; i++){
        if(i==0){
            result = find_start();
        }
        result = result ^ find_start();
    }   
    printf("%x\n", result); 
    return (0);
}