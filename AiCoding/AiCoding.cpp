#include <cstdio>

int main() {
    printf("=== C++ 이중 반복문과 do-while문 예제 ===\n\n");

    // 이중 for문: 구구단 표
    printf("[이중 for문: 2단과 3단 구구단]\n");
    for (int dan = 2; dan <= 3; dan++) {
        printf("<%d단>\n", dan);
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", dan, i, dan * i);
        }
        printf("\n");
    }

    // 이중 for문 + 조건문: 9x9 구구단 (5 이상만)
    printf("[이중 for문 + 조건문: 결과가 5 이상인 것만]\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 9; j++) {
            int result = i * j;
            if (result >= 5) {
                printf("%d*%d=%d  ", i, j, result);
            }
        }
        printf("\n");
    }
    printf("\n");

    // 이중 for문: 직사각형 패턴
    printf("[이중 for문: 직사각형 패턴]\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) {
            printf("# ");
        }
        printf("\n");
    }
    printf("\n");

    // 이중 for문: 삼각형 패턴
    printf("[이중 for문: 삼각형 패턴]\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    // do-while문: 카운트 다운
    printf("[do-while문: 카운트 다운]\n");
    int countdown = 5;
    do {
        printf("%d\n", countdown);
        countdown--;
    } while (countdown > 0);
    printf("\n");

    // do-while문 + 조건문: 합계 계산
    printf("[do-while문 + 조건문: 1부터 50까지 중 3의 배수만 합계]\n");
    int count = 1;
    int total = 0;
    do {
        if (count % 3 == 0) {
            total += count;
            printf("%d ", count);
        }
        count++;
    } while (count <= 50);
    printf("\n합계: %d\n\n", total);

    // do-while문: 사용자 입력 시뮬레이션
    printf("[do-while문: 숫자 출력]\n");
    int num = 1;
    do {
        printf("숫자: %d\n", num);
        num++;
    } while (num <= 3);

    return 0;
}