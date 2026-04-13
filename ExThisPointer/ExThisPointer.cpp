#include <cstdio>

namespace A
{
    int Test;
}

namespace B
{
    int Test;
}

int MyAddFuncOver(int parame1)
{
    printf("MyAddFuncOver\n");
}


int MyAddFuncOver(int parame1, int parame2)
{
    printf("MyAddFuncOver\n");
}

int MyAddFuncOver(int parame1, int parame2, char parame3)
{
    printf("MyAddFuncOver\n");
}


class Character {
private:
    int level;

public:
    // 1. 매개변수와 멤버 변수 이름이 같을 때 구분하는 용도
    Character(int level) {
        this->level = level; 
    }

    // 2. this를 반환하여 메서드 체이닝 구현
    Character* addLevel(int level) {
        this->level += level;
        return this;
    }

    void showStatus() {
        // this는 현재 객체의 주소를 나타냄
        printf("[Status] Address: %p | Level: %d\n", this, level);
    }
};

int main() {
    
    
    A::Test = 400;
    B::Test = 300;
    
    MyAddFuncOver(A::Test);
    MyAddFuncOver(A::Test,B::Test);
    MyAddFuncOver(A::Test,B::Test, char 'A');
   /*
    // 객체 생성
    Character myHero(10);

    printf("--- 초기 상태 ---\n");
    myHero.showStatus();

    printf("\n--- 레벨 업 후 (this 활용) ---\n");
    // 메서드 체이닝 예시
    myHero.addLevel(5)->addLevel(2);
    myHero.showStatus();
*/
    return 0;
}