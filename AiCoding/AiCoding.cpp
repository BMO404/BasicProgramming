#include <cstdio>

int main() {
    printf("=== C++ 이중 반복문과 do-while문 응용 예제 ===\n\n");

    // 이중 for문: 역삼각형 패턴
    printf("[이중 for문: 역삼각형]\n");
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    // 이중 for문 + 조건문: 소수 찾기
    printf("[이중 for문 + 조건문: 1부터 20까지의 소수]\n");
    for (int i = 2; i <= 20; i++) {
        int isPrime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    // 이중 for문: 구구단 마름모 패턴
    printf("[이중 for문: 숫자 행렬]\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
    printf("\n");

    // 이중 for문 + 조건문: 대각선 패턴
    printf("[이중 for문 + 조건문: 대각선 패턴]\n");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (i == j) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");

    // do-while문: 범위 내 숫자 누적
    printf("[do-while문: 1부터 20까지 누적 합계]\n");
    int i = 1;
    int sum = 0;
    do {
        sum += i;
        printf("합계: %d\n", sum);
        i++;
    } while (i <= 5);
    printf("\n");

    // do-while문 + 조건문: 최대값 찾기
    printf("[do-while문 + 조건문: 최댓값 찾기]\n");
    int numbers[] = {15, 42, 7, 33, 20};
    int max = numbers[0];
    int index = 1;
    do {
        if (numbers[index] > max) {
            max = numbers[index];
            printf("새로운 최댓값: %d\n", max);
        }
        index++;
    } while (index < 5);
    printf("최종 최댓값: %d\n\n", max);

    // do-while문: 카운터 기반 반복
    printf("[do-while문: 이벤트 처리]\n");
    int event = 1;
    do {
        if (event % 2 == 0) {
            printf("이벤트 %d: 짝수 처리\n", event);
        } else {
            printf("이벤트 %d: 홀수 처리\n", event);
        }
        event++;
    } while (event <= 4);

    return 0;
}