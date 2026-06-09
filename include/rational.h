#ifndef RATIONAL_H
#define RATIONAL_H

typedef enum {
    RATIONAL_OK = 0,
    RATIONAL_ERROR_NULL,
    RATIONAL_ERROR_DIV_ZERO
} rational_error_t;

typedef struct {
    long num;
    long den;
} rational_t;

rational_error_t rational_create(long num, long den, rational_t *result);
rational_error_t rational_add(const rational_t *a, const rational_t *b, rational_t *result);
rational_error_t rational_sub(const rational_t *a, const rational_t *b, rational_t *result);
rational_error_t rational_mul(const rational_t *a, const rational_t *b, rational_t *result);
rational_error_t rational_div(const rational_t *a, const rational_t *b, rational_t *result);
int rational_cmp(const rational_t *a, const rational_t *b);
double rational_to_double(const rational_t *r);

#endif
