#include <iostream>
#include <cstdio>

// std:: 사용을 지양하기 위해 필요한 경우 개별적으로 선언하거나
// 네임스페이스를 전역에 풉니다.
using namespace std;

// 산술 연산을 수행할 함수들 정의
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// 함수 포인터를 매개변수로 받는 함수
void executeOperation(int (*operation)(int, int), int x, int y) {
    int result = operation(x, y);
    printf("연산 결과: %d\n", result);
}

int main() {
    // 1. 기본적인 함수 포인터 선언 및 할당
    int (*ptr)(int, int) = add;

    printf("--- 함수 포인터 기본 사용 ---\n");
    printf("add 함수 호출: %d\n", ptr(10, 20));

    // 2. 함수 포인터 변경
    ptr = multiply;
    printf("multiply 함수 호출: %d\n", ptr(10, 20));

    printf("\n--- 매개변수로 함수 포인터 전달 ---\n");
    // 3. 콜백 형태로 함수 전달
    executeOperation(add, 100, 200);
    executeOperation(multiply, 10, 5);

    // C++20의 auto를 이용한 함수 포인터 타입 추론
    auto auto_ptr = add;
    printf("\n--- auto 키워드 활용 (C++20) ---\n");
    printf("auto_ptr 결과: %d\n", auto_ptr(5, 5));

    return 0;
}