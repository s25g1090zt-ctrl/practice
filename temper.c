#include <stdio.h>

double average(double size, double temperatures[]){
    double sum = 0;
    double avg = 0;
    for(int i=0; i < size; i++){
        sum += temperatures[i];
    }
    return avg = sum / size;
}

double highvalue(double size, double temperatures[]){
    double max = temperatures[0];
    for(int i = 0; i < size; i++){
        if(temperatures[i] > max){
            max = temperatures[i];
        }
    }
    return max;
}


int main(){
    double size = 0;
    double temperatures[size];

    for(int i=0; i<size; i++){
        printf("温度を入力してください．");
        scanf("%d", &temperatures[i]);
    }

    printf{"平均温度は，%fです．",average};
    printf{"最高温度は，%fです．", highvalue};


}