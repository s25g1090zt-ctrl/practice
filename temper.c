#include <stdio.h>

double average(double size, double temperatures[]){
    double sum = 0;
    for(int i=0; i < size; i++){
        sum += temperatures[i];
    }
    return sum / size;
}

double highvalue(int size, double temperatures[]){
    double max = temperatures[0];
    for(int i = 0; i < size; i++){
        if(temperatures[i] > max){
            max = temperatures[i];
        }
    }
    return max;
}

int main(){
    int size = 0;
    double temperatures[100];//最大100日とする．

    printf("何日分のデータにしますか？（最大100日まで）\n");
    scanf("%d", &size);

    for(int i=0; i<size; i++){
        printf("温度を入力してください．");
        scanf("%lf", &temperatures[i]);
    }

    printf("平均温度は，%.1fです．\n",average(size, temperatures));
    printf("最高温度は，%fです．\n", highvalue(size, temperatures));
}