#include <stdio.h>

float absoluto(float n) {
    return (n < 0) ? -1 * n : n;
}

float exp(int b, int e) {
    float res = 1;

    for(int i = 0; absoluto(e) > i; i++) {
        res = base * res;
    }

    if(e == 0)
        return 1;

    else if(e > 0)
        return res;
    else
        return 1/res;

}

float expRecursive( int b, int e) {
    if(e == 0) return 1;
    else if(e > 0) return b*expRecursive(b, e-1);
    else return expRecursive(b, e+1)/b;
}

main() {
    printf("%f", expRecursive(2,-2));
}
