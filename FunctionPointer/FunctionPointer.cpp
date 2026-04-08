#include <cstdio>

// 연산에 사용할 함수들 정의
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

// 함수 포인터를 매개변수로 받는 고차 함수 (Callback 구조)
void calculate(int (*operation)(int, int), int x, int y) {
    int result = operation(x, y);
    printf("연산 결과: %d\n", result);
}

int main() {
    // 1. 함수 포인터 변수 선언 및 초기화
    // 반환타입 (*변수명)(매개변수타입)
    int (*funcPtr)(int, int) = nullptr;

    printf("=== C++20 함수 포인터 실습 ===\n\n");

    // 2. 덧셈 함수 연결 및 호출
    funcPtr = add;
    printf("[직접 호출] 10 + 5 = %d\n", funcPtr(10, 5));

    // 3. 곱셈 함수 연결 및 호출
    funcPtr = multiply;
    printf("[직접 호출] 10 * 5 = %d\n", funcPtr(10, 5));

    printf("\n--- 콜백 함수 스타일 호출 ---\n");

    // 4. 함수 포인터를 인자로 전달
    calculate(add, 20, 10);
    calculate(subtract, 20, 10);
    calculate(multiply, 20, 10);

    // 5. C++20의 auto를 활용한 함수 포인터 (함수 주소를 직접 대입)
    auto autoFunc = add;
    printf("\n[auto 키워드 활용] 5 + 5 = %d\n", autoFunc(5, 5));

    return 0;
}