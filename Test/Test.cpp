#include <cstdio>
#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }

int main(int argc, char* argv[])
{
    char x = 'A';
    int i;
    
    i = (int)x;
    
    printf("%d\n", i);
    
    return 0;
}
