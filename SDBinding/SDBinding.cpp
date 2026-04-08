#include <cstdio>

class Base {
public:
    // 일반 함수: 정적 바인딩 대상
    void StaticShow() {
        printf("Base의 정적 함수 호출\n");
    }

    // 가상 함수: 동적 바인딩 대상
    virtual void DynamicShow() {
        printf("Base의 동적 함수 호출\n");
    }

    virtual ~Base() {}
};

class Derived : public Base {
public:
    // 함수 재정의 (Overriding)
    void StaticShow() {
        printf("Derived의 정적 함수 호출\n");
    }

    void DynamicShow() override {
        printf("Derived의 동적 함수 호출\n");
    }
};

int main() {
    Derived child;
    Base* ptr = &child; // 부모 타입 포인터로 자식 객체를 가리킴

    printf("=== Static Binding (정적 바인딩) ===\n");
    // 포인터의 타입(Base)을 보고 컴파일 시점에 결정됨
    ptr->StaticShow(); 

    printf("\n=== Dynamic Binding (동적 바인딩) ===\n");
    // 실제 가리키는 객체(Derived)를 보고 실행 시점에 결정됨
    ptr->DynamicShow();

    return 0;
}