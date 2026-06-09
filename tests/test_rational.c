#include <stdio.h>
#include <assert.h>
#include "rational.h"

int main() {
    rational_t a, b, res;
    
    // Тест 1: создание 2/4 = 1/2
    rational_create(2, 4, &a);
    printf("2/4 = %ld/%ld\n", a.num, a.den);
    assert(a.num == 1 && a.den == 2);
    
    // Тест 2: сложение 1/2 + 1/3 = 5/6
    rational_create(1, 2, &a);
    rational_create(1, 3, &b);
    rational_add(&a, &b, &res);
    printf("1/2 + 1/3 = %ld/%ld\n", res.num, res.den);
    assert(res.num == 5 && res.den == 6);
    
    // Тест 3: умножение 2/3 * 3/4 = 1/2
    rational_create(2, 3, &a);
    rational_create(3, 4, &b);
    rational_mul(&a, &b, &res);
    printf("2/3 * 3/4 = %ld/%ld\n", res.num, res.den);
    assert(res.num == 1 && res.den == 2);
    
    // Тест 4: деление 1/2 / 2/3 = 3/4
    rational_create(1, 2, &a);
    rational_create(2, 3, &b);
    rational_div(&a, &b, &res);
    printf("1/2 / 2/3 = %ld/%ld\n", res.num, res.den);
    assert(res.num == 3 && res.den == 4);
    
    // Тест 5: сравнение
    rational_create(1, 2, &a);
    rational_create(2, 4, &b);
    printf("1/2 cmp 2/4 = %d\n", rational_cmp(&a, &b));
    assert(rational_cmp(&a, &b) == 0);
    
    // Тест 6: double
    rational_create(1, 3, &a);
    printf("1/3 = %f\n", rational_to_double(&a));
    
    printf("\nВСЕ ТЕСТЫ ПРОЙДЕНЫ!\n");
    return 0;
}
