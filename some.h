#ifndef DRA_HEADER
#define DRA_HEADER
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <sys/stat.h>


#ifndef NDEBUG


    #define my_assert(condition)                                                                    \
        if ((condition) == true) {                                                                  \
            printf ("Assertaion Error : "#condition" , file  %s , line %d" , __FILE__ , __LINE__);  \
            abort ();                                                                               \
        }                                                                                           \

#else

    #define my_assert(condition)

#endif


typedef int (*My_Compare) (struct Inf_Lines struct1 , struct Inf_Lines struct2);

struct Text {
size_t size , num_lines ;
char * text_Onegin;
};

struct Inf_Lines {
    const char* str;
    size_t len;
};



enum indicators {
complete_value = 0 ,
incomplete_value = 1 ,
str1_longer_str2 = 1 ,
str2_longer_str1 = -1 ,
str1_equals_str2 = 3802
};


enum Sort_Type {
    SORT_ALPHABETICALLY = 1,
    SORT_BY_RHYME = 2 ,
    INCRE = 1 ,
    DECRE = -1
};






#endif
