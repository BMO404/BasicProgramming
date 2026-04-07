#include <cstdio>

// 자료형 -> 함수이름(파라미터)
int PrintSum(int A)
{
    printf("Age: %d\n", A);
    return A;
}

int main(int argc, char* argv[])
{
    int Num = 0;
    printf("입력한 값: ");
    scanf_s("%d", &Num);
    
    PrintSum(Num);
    
    return 0;
}
