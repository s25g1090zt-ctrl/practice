#include <stdio.h>

double average(double size, double temeratures[]){
    double sum = 0;
    for(int i=0; i < size; i++){
        sum += temeratures[i];
    }
    return sum / size;
}


int main(){
    double temperatures[5];

    for(int i=0; i++; i<5){
        printf("温度を入力してください．");
        scanf("%d", &temperatures[i]);
    }


}