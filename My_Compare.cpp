#include "My_features.h"

_Bool Check_Characters (char sym);


int My_Compare_Str_Alphabetically (struct Inf_Lines struct1 , struct Inf_Lines struct2)  // const assert
{
    my_assert (struct1.str == NULL);
    my_assert (struct2.str == NULL);

    while (*struct1.str != '\0' || *struct2.str != '\0') {

        while (Check_Characters (*struct1.str))

            struct1.str++;

        while (Check_Characters (*struct2.str))

            struct2.str++;

        if (*struct1.str == '\0' && *struct2.str == '\0')

            return str1_equals_str2;

        if (*struct1.str == '\0')

            return str2_longer_str1; // enum

        if (*struct2.str == '\0')

            return str1_longer_str2; // enum

        if (toupper (*struct1.str) != toupper (*struct2.str)) {

            return (toupper (*struct1.str) > toupper (*struct2.str)) ? str1_longer_str2 : str2_longer_str1;
        }

        struct1.str++;
        struct2.str++;
    }

    return complete_value;
}
//----------------------------------------------------------------------------------------------------------------------
int My_Compare_Str_Rhyme (struct Inf_Lines struct1, struct Inf_Lines struct2)
{
    my_assert (struct1.str == NULL);
    my_assert (struct2.str == NULL);

    while (struct1.len > 0 && struct2.len > 0) {

        while (struct1.len > 0 && Check_Characters (struct1.str[struct1.len - 1]) ) {

            struct1.len--;
        }

        while (struct2.len > 0 && Check_Characters (struct2.str[struct2.len - 1])) {

            struct2.len--;
        }

        if (struct1.len == 0 && struct2.len == 0) {

            return str1_equals_str2;
        }

        if (struct1.len == 0) {

            return str2_longer_str1;
        }

        if (struct2.len == 0) {

            return str1_longer_str2;
        }

        if (toupper (struct1.str[struct1.len - 1]) != toupper (struct2.str[struct2.len - 1])) {

            return (toupper (struct1.str[struct1.len - 1]) > toupper (struct2.str[struct2.len - 1])) ? str1_longer_str2 : str2_longer_str1;
        }

        struct1.len--;
        struct2.len--;
    }

    return complete_value;
}
//-------------------------------------------------------------------------------
_Bool Check_Characters (char sym)
{
    return (isspace (sym) || ispunct (sym) || isdigit (sym));
}
