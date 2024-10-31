#include <stdio.h>

#define num 5 //상품의 최대 개수

typedef struct stuffInfo{
    int stuffSerialNum;   //시리얼번호
    char stuffName[101];    //상품명
    int stuffStoreNum;      //입고수량
    int stuffSellPrice;     //판매가격
    int stuffSoldNum;       //판매량
} STUFFINFO;

int stuffNumbers = 0;

void ipgo(struct stuffInfo *stuff);
void panmae(struct stuffInfo *stuff);
void eachInfo(struct stuffInfo *stuff);
void allInfo(struct stuffInfo* stuff);

int main(){
    int stuffSerialId[num]={};
    int getNumber;
    int check=0;
    int select = 6, i=0;
    
    
    
    FILE* fp;
    fp = fopen("save.txt","w+");
    if(fp == NULL){ //fp 가 NULL 일경우 에러 출력후 종료
        printf("error...");
        return 0;
    }
    
    
    
    struct stuffInfo stuff[num];
    printf("[쇼핑몰 관리 프로그램]\n");
    printf("> 원하는메뉴를선택하세요.((1. 입고, 2. 판매, 3. 개별현황. 4. 전체현황, 5. 종료)\n");
    printf(">");
    while(select<0||select>5){
        scanf("%d", &select);
        if(select<0||select>5){
            printf("\n잘못된 값입니다.\n");
        }
    }
    
    
    while(select != 5){
    
        if(select == 1){      //입고
            if(stuffNumbers >= 5){
                printf("\n상품 갯수가 이미 5개 입니다.\n");
            }
            printf("\n상품 ID : ");
            scanf("%d", &getNumber);
            if(stuffNumbers >= 5){ //만약 상품이 5개 일경우
                for(int i=0; i<num; i++){
                	if (getNumber == stuff[i].stuffSerialNum){
                		ipgo(&stuff[i]);
                		    break;
					}
				}
				
            }
            else if(stuffNumbers <5){
                for(int i=0; i<num; i++){
                	if (getNumber == stuff[i].stuffSerialNum){
                		check = 1;
                		ipgo(&stuff[i]);
                		    break;
					}
				}
				if(check == 0){
				    stuffSerialId[stuffNumbers] = getNumber;
				    stuff[stuffNumbers].stuffSerialNum = getNumber;
                	ipgo(&stuff[stuffNumbers]);
                	stuffNumbers+=1;
				}
			}
			check = 0;
        }//입고
        else if(select == 2){ //판매
            printf("\n상품 ID : ");
            scanf("%d", &getNumber);
            for(int i = 0; i < num; i++){  //있는 ID 인지 판별
                if(getNumber == stuff[i].stuffSerialNum){
                    check = 1;
                        break;
                }
            }
            if(check == 0){
                printf("\n없는 상품 ID 입니다");
            }
            else if (check == 1){
                panmae(&stuff[i]);
            }
            check = 0;
        }//판매
        else if(select == 3){ //개별현황
            printf("\n상품 ID : ");
            scanf("%d", &getNumber);
            for(int i = 0; i < num; i++){  //있는 ID 인지 판별
                if(getNumber == stuff[i].stuffSerialNum){
                    check = 1;
                        break;
                }
            }
            if(check == 0){
                printf("\n없는 상품 ID 입니다");
            }
            else if (check == 1){
                eachInfo(&stuff[i]);
            }
            check = 0;
        }
        else if(select == 4){ //전체현황
            allInfo(stuff);
        }
        
        for(int i=0; i<stuffNumbers; i++){
           fprintf(fp, "%d %s %d %d %d\n", stuff[i].stuffSerialNum, stuff[i].stuffName , stuff[i].stuffStoreNum, stuff[i].stuffSellPrice, stuff[i].stuffSoldNum);
        }
        
        
        
        
        //printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("> 원하는메뉴를선택하세요.((1. 입고, 2. 판매, 3. 개별현황. 4. 전체현황, 5. 종료)\n");
        printf("> ");
        scanf("%d", &select);
        
        if(select<0||select>5){
            printf("\n잘못된 값입니다.\n");
        }
    }
    fclose(fp);
    return 0;
}

void ipgo(struct stuffInfo *stuff){ //입고
    printf("\n상품명 : ");
    scanf("%s",&stuff->stuffName);
    printf("\n입고량 : ");
    scanf("%d",&stuff->stuffStoreNum);
    printf("\n판매가격 : ");
    scanf("%d",&stuff->stuffSellPrice);
    //fprintf(fp, "%d %s %d %d %d\n", stuff[i]->stuffSerialNum, stuff[i]->stuffName , stuff[i]->stuffStoreNum, stuff[i]->stuffSellPrice, stuff[i]->stuffSoldNum);
}

void panmae(struct stuffInfo *stuff){ //판매
    printf("\n판매량 : ");
    scanf("%d", &stuff->stuffSoldNum);
}

void eachInfo(struct stuffInfo *stuff){ //개별 정보
    printf("\n상품명 : %s",stuff->stuffName);
    printf("\n재고 : %d", stuff->stuffStoreNum - stuff->stuffSoldNum);
    printf("\n판매 가격 : %d\n" , stuff->stuffSellPrice);
}

void allInfo(struct stuffInfo* stuff){ //전체현황
    int max = 0, min = 1001010;
    float ipSum = 0;
    float pmSum = 0;
    int maxId, minId;
    
    for(int i=0; i<num; i++){
        ipSum += stuff[i].stuffStoreNum; //총 입고 개수 저장
        pmSum += stuff[i].stuffSoldNum; // 총 판매 개수 저장
        if(stuff[i].stuffSoldNum>max){ //최소 최대 판매 구하기
            maxId = stuff[i].stuffSerialNum;
            max = stuff[i].stuffSoldNum;
        }
        if(stuff[i].stuffSoldNum<min){
            minId = stuff[i].stuffSerialNum;
            min = stuff[i].stuffSoldNum;
        }
    }
    printf("\n재고 수량 : ");
    for(int i=0; i<num; i++ ){
        printf("%d ", stuff[i].stuffStoreNum - stuff[i].stuffSoldNum);
    }
    
    float pmSumPer = pmSum/ipSum * 100.0; 
    
    printf("\n총 판매량 : %.0f (판매율 %.2f%%)\n",pmSum ,pmSumPer);
    for(int i=0; i<num; i++){
        if(max == stuff[i].stuffSoldNum){
            printf("가장 많이 판매된 상품 : ID %d, 상품명 : %s 판매량 %d\n",i+1 ,stuff[i].stuffName ,max );
        }
    }
    for(int i=0; i<num; i++){
        if(min == stuff[i].stuffSoldNum){
            printf("가장 적게 판매된 상품 : ID %d, 상품명 : %s 판매량 %d\n",i+1 ,stuff[i].stuffName ,min );
        }
    }
    for(int i=0; i<num; i++){
        if((stuff[i].stuffStoreNum - stuff[i].stuffSoldNum) <=2){
            printf("상품 ID %d : 재고부족(%d)\n", stuff[i].stuffSerialNum , stuff[i].stuffStoreNum - stuff[i].stuffSoldNum);
        }
    }
}