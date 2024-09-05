/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num,id;
    int ip[101]={};
    int pm[101]={};
    
    scanf("%d", &num);
    
    for(int i=0; i<num; i++ ){
        scanf("%d", &ip[i]);
    }
    for(int i=0; i<num; i++ ){
        scanf("%d", &pm[i]);
    }
    scanf("%d", &id);
    printf("%d\n", ip[id-1]-pm[id-1]);
    for(int i=0; i<num; i++ ){
        printf("%d ", ip[i]-pm[i]);
    }

    return 0;
}
