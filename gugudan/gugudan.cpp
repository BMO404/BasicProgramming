#include <cstdio>

int main() {
    // 구구단 출력 (2단부터 9단까지)
    for (int i = 2; i <= 9; ++i) {
        printf("=== %d단 ===\n", i);
        for (int j = 1; j <= 9; ++j) {
            printf("%d × %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }
    
    return 0;
}