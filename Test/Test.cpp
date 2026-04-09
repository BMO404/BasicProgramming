#include <cstdio>
#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }

int Myprint()
{
    printf("Myprint\n");
    return 1;
}


int main(int argc, char* argv[])
{
    
    int p = Myprint();
    printf("%d\n", p);
    
    char x = 'A';
    int i;
    
    i = (int)x;
    
    printf("%d\n", i);
    
    return 0;
}
