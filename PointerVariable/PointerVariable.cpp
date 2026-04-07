#include <cstdio>

int main() {
    printf("=== C++ 다양한 자료형 포인터 변수 예제 ===\n\n");

    // int형 포인터
    printf("[int형 포인터]\n");
    int intValue = 42;
    int* intPtr = &intValue;
    printf("int 변수: %d\n", intValue);
    printf("int 포인터: %p\n", (void*)intPtr);
    printf("포인터가 가리키는 값: %d\n\n", *intPtr);

    // float형 포인터
    printf("[float형 포인터]\n");
    float floatValue = 3.14f;
    float* floatPtr = &floatValue;
    printf("float 변수: %.2f\n", floatValue);
    printf("float 포인터: %p\n", (void*)floatPtr);
    printf("포인터가 가리키는 값: %.2f\n\n", *floatPtr);

    // double형 포인터
    printf("[double형 포인터]\n");
    double doubleValue = 2.71828;
    double* doublePtr = &doubleValue;
    printf("double 변수: %.5f\n", doubleValue);
    printf("double 포인터: %p\n", (void*)doublePtr);
    printf("포인터가 가리키는 값: %.5f\n\n", *doublePtr);

    // char형 포인터
    printf("[char형 포인터]\n");
    char charValue = 'A';
    char* charPtr = &charValue;
    printf("char 변수: %c\n", charValue);
    printf("char 포인터: %p\n", (void*)charPtr);
    printf("포인터가 가리키는 값: %c\n\n", *charPtr);

    // short형 포인터
    printf("[short형 포인터]\n");
    short shortValue = 100;
    short* shortPtr = &shortValue;
    printf("short 변수: %d\n", shortValue);
    printf("short 포인터: %p\n", (void*)shortPtr);
    printf("포인터가 가리키는 값: %d\n\n", *shortPtr);

    // long형 포인터
    printf("[long형 포인터]\n");
    long longValue = 1000000L;
    long* longPtr = &longValue;
    printf("long 변수: %ld\n", longValue);
    printf("long 포인터: %p\n", (void*)longPtr);
    printf("포인터가 가리키는 값: %ld\n\n", *longPtr);

    // bool형 포인터
    printf("[bool형 포인터]\n");
    bool boolValue = true;
    bool* boolPtr = &boolValue;
    printf("bool 변수: %s\n", boolValue ? "true" : "false");
    printf("bool 포인터: %p\n", (void*)boolPtr);
    printf("포인터가 가리키는 값: %s\n\n", *boolPtr ? "true" : "false");

    // 포인터 주소 비교
    printf("[포인터 주소 비교]\n");
    printf("intPtr 주소: %p\n", (void*)intPtr);
    printf("floatPtr 주소: %p\n", (void*)floatPtr);
    printf("doublePtr 주소: %p\n\n", (void*)doublePtr);

    // 포인터를 통한 값 변경
    printf("[포인터를 통한 값 변경]\n");
    *intPtr = 100;
    *floatPtr = 2.71f;
    *charPtr = 'B';
    printf("변경된 int: %d\n", *intPtr);
    printf("변경된 float: %.2f\n", *floatPtr);
    printf("변경된 char: %c\n\n", *charPtr);

    // 자료형 크기와 포인터
    printf("[자료형 크기]\n");
    printf("sizeof(int*): %zu bytes\n", sizeof(int*));
    printf("sizeof(float*): %zu bytes\n", sizeof(float*));
    printf("sizeof(double*): %zu bytes\n", sizeof(double*));
    printf("sizeof(char*): %zu bytes\n", sizeof(char*));
    printf("sizeof(bool*): %zu bytes\n\n", sizeof(bool*));

    // 여러 포인터 배열
    printf("[여러 포인터 저장]\n");
    int arr[] = {10, 20, 30};
    int* ptrArray[3];
    for (int i = 0; i < 3; i++) {
        ptrArray[i] = &arr[i];
        printf("ptrArray[%d]이 가리키는 값: %d\n", i, *ptrArray[i]);
    }

    return 0;
}