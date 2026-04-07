#include <cstdio>

int main()
{
    printf("=== C++ 반복문 예제 ===\n\n");

    // for문 예제: 1부터 5까지 출력
    printf("[for문: 1부터 5까지]\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // for문 + 조건문: 짝수만 출력
    printf("[for문 + 조건문: 1부터 10까지 중 짝수만]\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    // while문 예제: 5부터 1까지 역순 출력
    printf("[while문: 5부터 1까지 역순]\n");
    int count = 5;
    while (count >= 1) {
        printf("%d ", count);
        count--;
    }
    printf("\n\n");

    // while문 + 조건문: 합계 계산
    printf("[while문 + 조건문: 1부터 100까지 합계]\n");
    int sum = 0;
    int num = 1;
    while (num <= 100) {
        sum += num;
        num++;
    }
    printf("합계: %d\n\n", sum);

    // for문 + 조건문: 구구단 2단
    printf("[for문 + 조건문: 2단 (짝수 결과만)]\n");
    for (int i = 1; i <= 9; i++) {
        int result = 2 * i;
        if (result % 2 == 0) {
            printf("2 x %d = %d\n", i, result);
        }
    }
    printf("\n");

    // for문: 중첩 반복문 (별 패턴)
    printf("[중첩 for문: 별 패턴]\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}