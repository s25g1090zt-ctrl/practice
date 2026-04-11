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

void sort_descending(int size, double temperatures[], int tmp){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(temperatures[j] < temperatures[j+1]){
            tmp = temperatures[j];
            temperatures[j] = temperatures[j+1];
            temperatures[j+1] = tmp;
            }
        }
        
    }
}

int main(){
    int size = 0;
    double temperatures[100];//最大100日とする．
    int tmp;

    printf("何日分のデータにしますか？（最大100日まで）\n");
    scanf("%d", &size);

    for(int i=0; i<size; i++){
        printf("温度を入力してください．");
        printf("%dつ目:", i+1);
        scanf("%lf", &temperatures[i]);
    }

    printf("平均温度は，%.1fです．\n",average(size, temperatures));
    printf("最高温度は，%.1fです．\n", highvalue(size, temperatures));

    sort_descending(size, temperatures, tmp);
    printf("降順は，");
    for(int i = 0; i <  size; i++){
        printf("%.1f, ", temperatures[i]);
    }
    printf("です．");
}