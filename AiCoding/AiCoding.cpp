#include <cstdio>
#include "MyHeader.h"

int GlobalA = 50;

int main()
{
    //변수의 스코프(Scope): 영역, 생명주기
    int A = 100; // 지역 변수
    printf("%d\n", A);
    printf("%d\n",GlobalA);
    
    {
        int C = 20;// 지역 변수
        printf("%d\n",C);
    }
    
}