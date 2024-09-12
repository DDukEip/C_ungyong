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
    float ipSum = 0;
    float pmSum = 0;
    int max = 0, min = 1001010;
    int maxId, minId;
    
    scanf("%d", &num);
    
    for(int i=0; i<num; i++ ){ //입고 받기
        scanf("%d", &ip[i]);
        ipSum += ip[i]; //총 입고 개수 저장
    }
    
    for(int i=0; i<num; i++ ){ // 판매 받기
        scanf("%d", &pm[i]);
        pmSum += pm[i]; // 총 판매 개수 저장
        if(pm[i]>max){ //최소 최대 판매 구하기
            maxId = i+1;
            max = pm[i];
        }
        if(pm[i]<min){
            minId = i+1;
            min = pm[i];
        }
    }
    
    /*scanf("%d", &id); //1주차 id 입력
    
    printf("%d\n", ip[id-1]-pm[id-1]);
    */
    
    printf("재고 수량 : ");
    for(int i=0; i<num; i++ ){
        printf("%d ", ip[i]-pm[i]);
    }
    
    float pmSumPer = pmSum/ipSum * 100.0; 
    
    printf("\n총 판매량 : %.0f (판매율 %.2f%%)\n",pmSum ,pmSumPer);
    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n",maxId ,max );
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n",minId ,min );
    
    for(int i=0; i<num; i++){
        if(ip[i]-pm[i]<=2){
            printf("상품 ID %d : 재고부족(%d)\n", i+1, ip[i]-pm[i]);
        }
    }
    
    return 0;
}
