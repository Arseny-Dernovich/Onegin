#ifndef DRA_HEADER
#define DRA_HEADER

#include <stdio.h>
#include <assert.h>

#ifndef NDEBUG

    #define my_assert(condition)                                                                    \
        if (condition == true) {                                                                    \
            printf ("Assertaion Error : "#condition" , file  %s , line %d" , __FILE__ , __LINE__);  \
            abort ();                                                                               \
        }                                                                                           \
        else;
#else

    #define my_assert(condition)

#endif

const int NTests = 20;
const double EPS = 1e-12;                                              // погрешность для сравнения чисел с плавающей запятой

const char* const yellow          = "\033[3;33;40m";
const char* const red             = "\033[3;31;40m";
const char* const blue_dark       = "\033[3;34;40m";
const char* const blue            = "\033[3;36;40m";
const char* const blue_dark_flash = "\033[5;34;40m";
const char* const green           = "\033[3;32;40m";
const char* const end             = "\033[0m";

// __PRETTY_FUNCTION__ __func__

enum n_roots {
 line_roots = 1 ,
 no_roots = 2 ,
 infinit_roots = 3,
 two_roots_pos_discr = 13,
 two_roots_neg_discr = 14 ,
 one_root_zero_discr = 15
};


struct refer {
    double x1_refer , x2_refer;
};

struct roots {
    double x1 , x2;
};


struct coeffs {
    double a , b , c;
};


struct test {
    int num_test;
    coeffs coeff;
    refer  roots_ref;
};

#endif /* DRA_HEADER */

