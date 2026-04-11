#include <stdio.h>

double average(double size, double temperatures[]){
    double sum = 0;
    for(int i=0; i < size; i++){
        sum += temperatures[i];
    }
    return sum / size;
}

double highvalue(double size, double temperatures[]){
    double max = temperatures[0];
    for(int i = 0; i++; i < size){
        if(temperatures[i] < max){
            max = temperatures[i];
        }
    }
    return max;
}


int main(){
    double temperatures[5];

    for(int i=0; i++; i<5){
        printf("温度を入力してください．");
        scanf("%d", &temperatures[i]);
    }


}