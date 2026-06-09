#include "rational.h"
#include <stdlib.h>

static long gcd(long a, long b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b != 0) {
        long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

static rational_error_t normalize(rational_t *r) {
    if (!r) return RATIONAL_ERROR_NULL;
    if (r->den == 0) return RATIONAL_ERROR_DIV_ZERO;
    
    if (r->den < 0) {
        r->num = -r->num;
        r->den = -r->den;
    }
    
    long g = gcd(r->num, r->den);
    r->num /= g;
    r->den /= g;
    return RATIONAL_OK;
}

rational_error_t rational_create(long num, long den, rational_t *result) {
    if (!result) return RATIONAL_ERROR_NULL;
    if (den == 0) return RATIONAL_ERROR_DIV_ZERO;
    
    result->num = num;
    result->den = den;
    return normalize(result);
}

rational_error_t rational_add(const rational_t *a, const rational_t *b, rational_t *result) {
    if (!a || !b || !result) return RATIONAL_ERROR_NULL;
    
    rational_t tmp;
    tmp.num = a->num * b->den + b->num * a->den;
    tmp.den = a->den * b->den;
    
    normalize(&tmp);
    *result = tmp;
    return RATIONAL_OK;
}

rational_error_t rational_sub(const rational_t *a, const rational_t *b, rational_t *result) {
    if (!a || !b || !result) return RATIONAL_ERROR_NULL;
    
    rational_t tmp;
    tmp.num = a->num * b->den - b->num * a->den;
    tmp.den = a->den * b->den;
    
    normalize(&tmp);
    *result = tmp;
    return RATIONAL_OK;
}

rational_error_t rational_mul(const rational_t *a, const rational_t *b, rational_t *result) {
    if (!a || !b || !result) return RATIONAL_ERROR_NULL;
    
    rational_t tmp;
    tmp.num = a->num * b->num;
    tmp.den = a->den * b->den;
    
    normalize(&tmp);
    *result = tmp;
    return RATIONAL_OK;
}

rational_error_t rational_div(const rational_t *a, const rational_t *b, rational_t *result) {
    if (!a || !b || !result) return RATIONAL_ERROR_NULL;
    if (b->num == 0) return RATIONAL_ERROR_DIV_ZERO;
    
    rational_t tmp;
    tmp.num = a->num * b->den;
    tmp.den = a->den * b->num;
    
    normalize(&tmp);
    *result = tmp;
    return RATIONAL_OK;
}

int rational_cmp(const rational_t *a, const rational_t *b) {
    if (!a || !b) return 0;
    
    long lhs = a->num * b->den;
    long rhs = b->num * a->den;
    
    if (lhs > rhs) return 1;
    if (lhs < rhs) return -1;
    return 0;
}

double rational_to_double(const rational_t *r) {
    if (!r) return 0.0;
    return (double)r->num / (double)r->den;
}
