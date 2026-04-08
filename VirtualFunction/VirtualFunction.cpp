#include <cstdio>

// 기초 클래스 (Base Class)
class Animal {
public:
    // 가상 함수 선언: 파생 클래스에서 재정의할 것을 기대함
    virtual void MakeSound() {
        printf("동물이 알 수 없는 소리를 냅니다.\n");
    }

    // 가상 소멸자: 상속 관계에서 메모리 누수를 방지하기 위해 필수
    virtual ~Animal() {}
};

// 파생 클래스 (Derived Class) - Dog
class Dog : public Animal {
public:
    // C++11부터 지원되는 override 키워드를 사용하여 재정의 (C++20에서도 표준)
    void MakeSound() override {
        printf("강아지: 멍멍!\n");
    }
};

// 파생 클래스 (Derived Class) - Cat
class Cat : public Animal {
public:
    void MakeSound() override {
        printf("고양이: 야옹~\n");
    }
};

int main() {
    printf("=== C++20 가상 함수 및 다형성 예제 ===\n\n");

    // 1. 부모 클래스 포인터로 자식 객체를 가리킴 (다형성)
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    // 2. 가상 함수 호출
    // 가상 함수이므로 포인터 타입(Animal*)이 아닌 실제 객체 타입의 함수가 호출됨
    printf("myDog->MakeSound(): ");
    myDog->MakeSound();

    printf("myCat->MakeSound(): ");
    myCat->MakeSound();

    printf("\n--- 배열을 이용한 일괄 처리 ---\n");

    // 3. 부모 클래스 포인터 배열로 관리
    Animal* zoo[2] = { myDog, myCat };

    for (int i = 0; i < 2; ++i) {
        printf("%d번 동물 소리: ", i + 1);
        zoo[i]->MakeSound();
    }

    // 4. 메모리 해제
    delete myDog;
    delete myCat;

    return 0;
}