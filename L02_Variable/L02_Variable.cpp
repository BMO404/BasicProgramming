
#include <cstdio>

int main(int argc, char* argv[])
{
    printf("==Variable==\n");
    
    int A; // 선언만 하면 쓰레기 값만 들어가 커파일 오류가 발생함
    A = 1024;
    
    printf("%d\n", A);
    
    // 선언 + 정의(definition)
    int B = 100;
    printf("%d\n", B);
    
    // 상수 리터럴(literal)
    const int Val = 5; // 선언 하면 컴파일 에러
    int const val2 = 10;
    
    char C = 'A';
    
    char szString[] = "Hello"; // "Hello" 문자열 리터럴
    printf("szString = %s\n", szString);
    
    bool Boolean = true; // true: 1, false:0
    
    return 0;
}
