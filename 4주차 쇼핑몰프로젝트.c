/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define num 5

void ipgo(int* ip ,int *pm);
void panmae(int* ip ,int *pm);
void stuffInfo(int* ip ,int *pm, char (*names)[101]);
void getName(char (*names)[101]);
    //int id=0;
    
    

int main()
{
    int ip[num]={0};
    int pm[num]={0};
    //char names[num][101]={};
    char names[num][101];   
    
    int select = 6;
    printf("[���θ� ���� ���α׷�]\n");
    printf("> ���ϴ¸޴��������ϼ���.(1.�԰�,2.�Ǹ�,3.��ǰ��Ȳ.4.��ǰ���Է�,5.����)\n");
    printf(">");
    while(select<0||select>5){
        scanf("%d", &select);
        if(select<0||select>5){
            printf("\n�߸��� ���Դϴ�.\n");
        }
    }
    
    
    while(select != 5){
    
    if(select == 1){
        ipgo(ip,pm);
    }
    else if(select == 2){
        panmae(ip,pm);
    }
    else if(select == 3){
        stuffInfo(ip,pm,names);
    }
    else if(select == 4){
        getName(names);
    }
    
    //printf("\n[���θ� ���� ���α׷�]\n");
    printf("> ���ϴ¸޴��������ϼ���.(1.�԰�,2.�Ǹ�,3.��ǰ��Ȳ.4.��ǰ���Է�,5.����)\n");
    printf("> ");
    scanf("%d", &select);
    
    if(select<0||select>5){
        printf("\n�߸��� ���Դϴ�.\n");
    }
    
    }
    return 0;
}

void ipgo(int* ip ,int *pm){ //�԰�
    int select_Ipgo = 0;
    int aa,bb;
    int getIp;
    printf("\n> �԰���� �Է� : ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ����\n");
    scanf("%d", &select_Ipgo);
    if(select_Ipgo == 1){//1�� ���ý�
        printf("\n> ��ü ��ǰ %d ���� �԰������ �Է����ּ���\n", num);
        for(int i=0; i<num; i++ ){ //�԰� �ޱ�
            scanf("%d", &getIp);
            *(ip+i) = getIp;
        }
    }
    else if(select_Ipgo == 2){ //2�� ���ý�
        printf("\n��ǰID :");
        scanf("%d", &aa);
        printf("\n�԰���� :");
        scanf("%d", &bb);
        *(ip+aa-1) = bb;
    }
} //�԰�

void panmae(int* ip ,int *pm){ //�Ǹ�
    int select_Panmae = 0;
    int aa=0,bb=0;
    int getPm;
    printf("\n> �Ǹż��� �Է� : ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ����\n");
    scanf("%d", &select_Panmae);
    if(select_Panmae == 1){
        printf("\n> ��ü ��ǰ %d ���� �Ǹż����� �Է����ּ���\n", num);
        for(int i=0; i<num; i++ ){ // �Ǹ� �ޱ�
            scanf("%d", &getPm);
            *(pm+i) = getPm;
        /*    if((ip[i]-pm[i])<0){
                printf("\n�ش� ��ǰ�� ������ �Ǹ� �� �� �����ϴ�.");
                
            }
            else{
                pm[aa-1]=bb;
            }*/
        }
    }
    else if(select_Panmae == 2){
        printf("\n��ǰID :");
        scanf("%d", &aa);
        printf("\n�Ǹż��� :");
        scanf("%d", &bb);
        if((*(ip+aa-1)-(*(pm+aa-1)+bb))<0){
            printf("\n�ش� ��ǰ�� ������ �Ǹ� �� �� �����ϴ�.");
        }
        else{
            *(pm+aa-1)=bb;
        }
    }
} //�Ǹ�

void stuffInfo(int* ip ,int *pm, char (*names)[101]){//��ǰ��Ȳ
    int max = 0, min = 1001010;
    float ipSum = 0;
    float pmSum = 0;
    int maxId, minId;
    
    for(int i=0; i<num; i++){
        ipSum += ip[i]; //�� �԰� ���� ����
        pmSum += pm[i]; // �� �Ǹ� ���� ����
        if(*(ip+i)>max){ //�ּ� �ִ� �Ǹ� ���ϱ�
            maxId = i+1;
            max = *(ip+i);
        }
        if(*(pm+i)<min){
            minId = i+1;
            min = *(pm+i);
        }
    }
    printf("\n��� ���� : ");
    for(int i=0; i<num; i++ ){
        printf("%d ", *(ip+i)-*(pm+i));
    }
    
    float pmSumPer = pmSum/ipSum * 100.0; 
    
    printf("\n�� �Ǹŷ� : %.0f (�Ǹ��� %.2f%%)\n",pmSum ,pmSumPer);
    for(int i=0; i<num; i++){
        if(max == *(ip+i)){
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ�� : %s �Ǹŷ� %d\n",i+1 ,(char*)names[i] ,max );
        }
    }
    for(int i=0; i<num; i++){
        if(min == *(pm+i)){
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ�� : %s �Ǹŷ� %d\n",i+1 ,(char*)names[i] ,min );
        }
    }
    for(int i=0; i<num; i++){
        if(*(ip+i)-*(pm+i)<=2){
            printf("��ǰ ID %d : ������(%d)\n", i+1, *(ip+i)-*(pm+i));
        }
    }
}

void getName(char (*names)[101]){
    for(int i=0; i<num; i++){
        printf("\nID %d ��ǰ�� : ", i+1);
        scanf("%s", (char*)names[i] );
    }
}
