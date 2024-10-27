/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int getLine(char* line){ // 입력받기 함수
    int ch, i = 0;
    while((ch=getchar()) != '\n') line[i++] = ch;
    line[i] = '\0';
    return i;
}


int main()
{
    int num1, num2;
    char input[100];

    FILE* fp_src; //파일 포인터 선언
    FILE* fp_dest;
    
    fp_src = fopen("output.txt","r"); //쓰기모드로 output.txt 열기 
    //w 쓰기모드 , r 읽기모드 
    if(fp_src == NULL){ //fp 가 NULL 일경우 에러 출력후 종료
        printf("src error...");
        return 0;
    }
    
    fp_dest = fopen("output3.txt","w");
    if(fp_dest == NULL){ 
        printf("dest error...");
        return 0;
    }
    
    while(!feof(fp_src)){ //파일의 끝이 아닌동안
        fscanf(fp_src, "%s %d %d\n", &input, &num1, &num2);
        fprintf(fp_dest, "%s %d %d\n", input, num1, num2);
        
    }
    
    
    
    fclose(fp_src);
    fclose(fp_dest);
    return 0;
}
