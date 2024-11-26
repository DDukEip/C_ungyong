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
    char input[100];
//    int ch, i = 0;
    FILE* fp; //파일 포인터 선언
    fp = fopen("output.txt","w"); //쓰기모드로 output.txt 열기
    if(fp == NULL){ //fp 가 NULL 일경우 에러 출력후 종료
        printf("error...");
        return 0;
    }
    
    for(int i = 0; i < 5; i++){
        getLine(input);//getLine 함수 호출
        fputs(input, fp); // (배열, 어떤파일 파일포인터)
        fputs("\n", fp);
    }
    
//    fputs("hello ooo", fp);
    
    
    fclose(fp);
    
    return 0;
}
