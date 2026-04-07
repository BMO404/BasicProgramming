#include <cstdio>

int main() {
    // 기본 자료형 선언
    int score = 85;
    double temperature = 36.5;
    char grade = 'B';
    bool isPassed = true;

    std::printf("=== C++ 기본 자료형 + 조건문 예제 ===\n\n");

    // 정수형 조건문
    std::printf("점수: %d\n", score);
    if (score >= 80) {
        std::printf("결과: 합격\n\n");
    } else {
        std::printf("결과: 불합격\n\n");
    }

    // 부동소수점형 조건문
    std::printf("체온: %.1f°C\n", temperature);
    if (temperature >= 37.0) {
        std::printf("상태: 발열\n\n");
    } else {
        std::printf("상태: 정상\n\n");
    }

    // 문자형 조건문
    std::printf("학점: %c\n", grade);
    if (grade == 'A') {
        std::printf("평가: 최우수\n\n");
    } else if (grade == 'B') {
        std::printf("평가: 우수\n\n");
    } else {
        std::printf("평가: 보통\n\n");
    }

    // 불린형 조건문
    std::printf("통과 여부: %s\n", isPassed ? "Yes" : "No");
    if (isPassed) {
        std::printf("다음 단계로 진행\n");
    } else {
        std::printf("재시도 필요\n");
    }

    return 0;
}