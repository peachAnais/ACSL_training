#include <iostream>
#include <cstdio>
using namespace std;

// 3 12345678912345 a 334.23 14049.30493

int main() {
    // Complete the code.
    
    int a = 0;
    long b = 0;
    char c;
    float d = 0;
    double e = 0;
    
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);

    float x = 0;
    sscanf("334.23", "%.2f", &x);

    printf("%d\n", a);
    printf("%ld\n", b);
    printf("%c\n", c);
    printf("%.3f\n", d);
    printf("%.9lf\n", e);
    
    return 0;
}
