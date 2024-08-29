/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main()
{
    int number[SIZE];
    int most;
    int temp;
    srand(time(NULL));
    
    for(int i=0; i<SIZE; i++){
        number[i] = (rand() % 10000) + 1;
    }
    
    for(int i = 0; i< SIZE; i++){
        most = i;
        for(int j=i+1; j < SIZE; j++){
            if(number[most]<number[j]) most = j;
        }
        temp = number[i];
        number[i] = number[most];
        number[most] = temp;
    
    }
    
    for(int i=0; i<SIZE; i++){
        printf("%5d\t", number[i]);
        if((i+1) % 10 == 0) printf("\n");
    }
    
    return 0;
}