#include <stdio.h>

int main() {
    int a;
    float b, c;
    double d;
    char ch;

    a = 10;
    b = 2.5;
    c = 12.36;
    d = 1234.664;
    ch = 'A';

    printf("%d is stored in location %x\n", a, &a);
    printf("%f is stored in location %x\n", b, &b);
    printf("%f is stored in location %x\n", c, &c);
    printf("%ld is stored in location %x\n", d, &d);
    printf("%c is stored in location %x\n", ch, &ch);
    return 0;
}