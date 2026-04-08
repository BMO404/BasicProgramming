#include <cstdio>
#include <memory>
#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(a) if (a) { delete[] a; a = nullptr; }
#define SAFE_DELETE_AND_PRINT(KK) \
    {SAFE_DELETE(KK)} \
    {printf("메모리 해제 완료");}

int main() {
    printf("=== C++ 20 Dynamic Memory Allocation Sample ===\n\n");

    // 1. 단일 객체의 동적 메모리 할당
    printf("1. 단일 정수 동적 할당:\n");
    int* pInt = new int(42);
    printf("   할당된 값: %d\n", *pInt);
    SAFE_DELETE_AND_PRINT(pInt);
    printf("   메모리 해제 완료\n\n");

    // 2. 배열의 동적 메모리 할당
    printf("2. 정수 배열 동적 할당 (크기: 5):\n");
    int* pArray = new int[5]{10, 20, 30, 40, 50};
    printf("   배열 요소: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", pArray[i]);
    }
    printf("\n");
    delete[] pArray;
    pArray = nullptr;
    printf("   메모리 해제 완료\n\n");

    // 3. unique_ptr을 사용한 안전한 메모리 관리 (C++ 스타일)
    printf("3. unique_ptr을 사용한 동적 할당:\n");
    {
        std::unique_ptr<int> smartPtr(new int(99));
        printf("   smart pointer 값: %d\n", *smartPtr);
        printf("   범위를 벗어나면 자동으로 메모리 해제됨\n");
    }
    printf("   자동 해제 완료\n\n");

    // 4. 구조체의 동적 메모리 할당
    printf("4. 구조체 동적 할당:\n");
    struct Person {
        int age;
        const char* name;
    };
    
    Person* pPerson = new Person{25, "Alice"};
    printf("   이름: %s, 나이: %d\n", pPerson->name, pPerson->age);
    delete pPerson;
    pPerson = nullptr;
    printf("   메모리 해제 완료\n\n");

    printf("=== 프로그램 종료 ===\n");
    return 0;
}