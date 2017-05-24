#include<stdio.h>
#include <conio.h>

char data[9]={'1','2','3','4','5','6','7','8','9'};
int j,k,i=1,p=1;


void error(){
    printf("\nWrong Input\n");
}
int winner()
{
    if((data[0]==data[1] && data[1]==data[2]) ||  (data[3]==data[4] && data[4]==data[5]) || (data[6]==data[7] && data[7]==data[8]) ||
       (data[0]==data[3] && data[3]==data[6]) ||  (data[1]==data[4] && data[4]==data[7]) || (data[2]==data[5] && data[5]==data[8]) ||
       (data[0]==data[4] && data[4]==data[8]) ||  (data[2]==data[4] && data[4]==data[6])){
        return 1;
    }
}

void chart(){
    printf("\t\t\tTIC TAC TOE\n\n");
    printf("\t\t        |       |        \n");
    printf("\t\t    %c   |   %c   |   %c    \n",data[0], data[1], data[2]);
    printf("\t\t -------+-------+-------\n");
    printf("\t\t        |       |        \n");
    printf("\t\t    %c   |   %c   |   %c    \n",data[3], data[4], data[5]);
    printf("\t\t -------+-------+-------\n");
    printf("\t\t        |       |        \n");
    printf("\t\t    %c   |   %c   |   %c    \n",data[6], data[7], data[8]);
}

void player1(){
    chart();
    printf("\n\nEnter your position Player %d: ",p);

    while(1){
        scanf("%d",&j);
        if(data[j-1]=='Y' || data[j-1]=='C'){
            error();
            chart();
            printf("\n\nEnter your position Player %d: ",p);
        }
        else{
            data[j-1]='Y';
            p=2;
            return 0;
        }
    }
}



void player2(){
    while(1){
        k=random_number(1,10);
        if(data[k-1]=='Y' || data[k-1]=='C'){
            continue;
        }
        else{
            data[k-1]='C';
            p=1;
            system("cls");
            return 0;
        }
    }
}

int random_number(int min_num, int max_num)
        {
            int result=0,low_num=0,hi_num=0;
            if(min_num<max_num)
            {
                low_num=min_num;
                hi_num=max_num+1; // this is done to include max_num in output.
            }else{
                low_num=max_num+1;// this is done to include max_num in output.
                hi_num=min_num;
            }
            srand(time(NULL));
            result = (rand()%(hi_num-low_num))+low_num;
            return result;
        }


int main()
{
    int w1=0,w2=0;
    while(1){
            w1=0,w2=0;
        if(p==1)
            player1();
            w1=winner();
            if(w1==1){
                system("cls");
                chart();
                printf("\nCongratulations, You have Won The Game !\n");
                break;
            }
        else{
            player2();
            w2=winner();
            if(w2==1){
                system("cls");
                chart();
                printf("\nComputer Won !!!\n");
                break;
            }
        }
    }
    return 0;
}
