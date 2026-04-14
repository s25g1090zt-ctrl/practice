#include<stdio.h>

struct Product{
    char name[50];
    int price;
};

double total_price(struct Product list[], int number){
    double sum=0;
    for(int i=0; i<number; i++){
        sum += list[i].price;
    }
    return sum;
};

double average_price(struct Product list[], int number){
    if(number==0){
        return 0;
    }
    return total_price(list, number)/number;
}

int find_max_price(struct Product list[], int number){
    int max=list[0].price;

    for(int i=0; i<number; i++){
        if(list[i].price>max){
            max = list[i].price;
        }
    }
    return max;
}

void show_best_price(struct Product list[], int number){
    int best=0;
    for(int i=0; i<number; i++){
        if(list[i].price > list[best].price){
            best = i;
        }
    }
    printf("一番高い商品%sはです．\n",list[best].name);
}

int main(){
    int number=0;
    printf("商品の数はいくつですか？(最大100）\n");
    scanf("%d", &number);

    struct  Product list[100];//最大100
    
    for(int i=0; i<number; i++){
        printf("%dつ目の商品名：", i+1);
        scanf("%s", list[i].name);
        printf("価格：");
        scanf("%d", &list[i].price);
    }

    printf("合計金額：%.1fです．\n", total_price(list, number));
    printf("平均価格は%.1fです．\n", average_price(list, number));
    printf("一番高いのは，%dです．\n",find_max_price(list, number));
    show_best_price(list, number);
}