/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define num 5

void ipgo();
void panmae();
void stuffInfo();

    int id=0;
    int ip[101]={0};
    int pm[101]={0};
    float ipSum = 0;
    float pmSum = 0;
    int max = 0, min = 1001010;
    int maxId, minId;

int main()
{
    int select = 5;
    printf("[쇼핑몰 관리 프로그램]\n");
    printf("> 원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
    printf(">");
    while(select<0||select>4){
        scanf("%d", &select);
        if(select<0||select>4){
            printf("\n잘못된 값입니다.\n");
        }
    }
    
    
    while(select != 4){
    
    if(select == 1){
        ipgo();
    }
    else if(select == 2){
        panmae();
    }
    else if(select == 3){
        stuffInfo();
    }
    
    //printf("\n[쇼핑몰 관리 프로그램]\n");
    printf("> 원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
    printf("> ");
    scanf("%d", &select);
    
    if(select<0||select>4){
        printf("\n잘못된 값입니다.\n");
    }
    
    }
    return 0;
}

void ipgo(){ //입고
    int select_Ipgo = 0;
    int aa,bb;
    printf("\n> 입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
    scanf("%d", &select_Ipgo);
    if(select_Ipgo == 1){//1번 선택시
        printf("\n> 전체 상품 %d 개의 입고수량을 입력해주세요\n", num);
        for(int i=0; i<num; i++ ){ //입고 받기
            scanf("%d", &ip[i]);
        }
    }
    else if(select_Ipgo == 2){ //2번 선택시
        printf("\n상품ID :");
        scanf("%d", &aa);
        printf("\n입고수량 :");
        scanf("%d", &bb);
        ip[aa-1]=bb;
    }
}

void panmae(){ //판매
    int select_Panmae = 0;
    int aa=0,bb=0;
    printf("\n> 판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n");
    scanf("%d", &select_Panmae);
    if(select_Panmae == 1){
        printf("\n> 전체 상품 %d 개의 판매수량을 입력해주세요\n", num);
        for(int i=0; i<num; i++ ){ // 판매 받기
            scanf("%d", &pm[i]);
        /*    if((ip[i]-pm[i])<0){
                printf("\n해당 상품이 부족해 판매 할 수 없습니다.");
                
            }
            else{
                pm[aa-1]=bb;
            }*/
        }
    }
    else if(select_Panmae == 2){
        printf("\n상품ID :");
        scanf("%d", &aa);
        printf("\n판매수량 :");
        scanf("%d", &bb);
        if((ip[aa-1]-(pm[aa-1]+bb))<0){
            printf("\n해당 상품이 부족해 판매 할 수 없습니다.");
        }
        else{
            pm[aa-1]=bb;
        }
    }
}

void stuffInfo(){//상품현황
    for(int i=0; i<num; i++){
        ipSum += ip[i]; //총 입고 개수 저장
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
    printf("\n재고 수량 : ");
    for(int i=0; i<num; i++ ){
        printf("%d ", ip[i]-pm[i]);
    }
    
    float pmSumPer = pmSum/ipSum * 100.0; 
    
    printf("\n총 판매량 : %.0f (판매율 %.2f%%)\n",pmSum ,pmSumPer);
    for(int i=0; i<num; i++){
        if(max == pm[i]){
            printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n",i+1 ,max );
        }
    }
    for(int i=0; i<num; i++){
        if(min == pm[i]){
            printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n",i+1 ,min );
        }
    }
    for(int i=0; i<num; i++){
        if(ip[i]-pm[i]<=2){
            printf("상품 ID %d : 재고부족(%d)\n", i+1, ip[i]-pm[i]);
        }
    }
}
