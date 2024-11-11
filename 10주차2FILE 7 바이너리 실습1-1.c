/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define SIZE 100

int main()
{
    char input[SIZE];
    FILE* fp = NULL;
    
    if((fp = fopen("output.bin", "wb")) == NULL){
                                //w"b"<< 바이너리 b
        printf("error...");
        return 0;
    }
    gets(input);
    //fputs(input, fp);
    fwrite(input, strlen(input), 1, fp); //어디서, 크기, 몇번, 어디로
    
    fclose(fp);
    

    return 0;
}
