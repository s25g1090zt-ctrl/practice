#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 乱数の準備
    srand((unsigned int)time(NULL));
    int answer = rand() % 100 + 1;
    int guess = 0;
    int count = 0;

    printf("1から100までの数字を当ててみてね！\n");

    // ここにループと判定の処理を書いてみましょう

    while (guess != answer)
    {
        scanf("%d", &guess);
        count++;
    
        if(guess < answer){
            printf("もっと大きい数字だよ！\n");
        } else if(guess > answer){
            printf("もっと小さい数字だよ！\n");
        } else {
            printf("正解！おめでとう！\n");
            printf("あなたは%d回で当てました！\n", count);
            
            return 0;
        }
    }
}