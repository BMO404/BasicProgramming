#include <cstdio>
#define MAX_PLAYER 8 // 매크로

struct Player
{
    int id;
    float hp;
    char grader;
    bool alive;
    
    void print() const
    {
        printf("id     : %d\n", id);
        printf("hp     : %.1f\n", hp);
        printf("id     : %c\n", grader);
        printf("id     : %s\n", alive);
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
