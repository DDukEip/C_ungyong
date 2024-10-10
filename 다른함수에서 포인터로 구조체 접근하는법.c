#include <stdio.h>

#define num 5 //상품의 최대 개수

struct stuffInfo{
//    int stuffSerialNum; //시리얼번호
    char stuffName[101];//상품명
    int stuffStoreNum;  //입고수량
    int stuffPrice;     //판매가격
};

int stuffNumbers = 0;

void ipgo();
void panmae();
void eachInfo();
void allInfo();

int main(){
    
    int getNumber;
    int select = 6;
    printf("[쇼핑몰 관리 프로그램]\n");
    printf("> 원하는메뉴를선택하세요.((1. 입고, 2. 판매, 3. 개별현황. 4. 전체현황, 5. 종료)\n");
    printf(">");
    struct stuffInfo first;
        scanf("%d", &first.stuffPrice);
    
    ipgo(&first);
    
    return 0;
}

void ipgo(struct stuffInfo *stuff){
    printf("%d", stuff->stuffPrice);
}