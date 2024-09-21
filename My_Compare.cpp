#include "My_features.h"




int My_Compare_Str_Alphabetically (const void* point1, const void* point2)
{
    my_assert(point1 == NULL);
    my_assert(point2 == NULL);

    const struct Inf_Lines* line1 = (const struct Inf_Lines*) point1;
    const struct Inf_Lines* line2 = (const struct Inf_Lines*) point2;

    const char* s1 = line1->str;
    const char* s2 = line2->str;

    //printf("(%s)\n", s1);

    while (*s1 != '\0' || *s2 != '\0') {

        while (Check_Characters (*s1))

            s1++;

        while (Check_Characters (*s2))

            s2++;

        if (*s1 == '\0' && *s2 == '\0')

            return str1_equals_str2;

        if (*s1 == '\0')

            return str2_longer_str1;

        if (*s2 == '\0')

            return str1_longer_str2;

        if (toupper (*s1) != toupper (*s2))

            return (toupper (*s1) > toupper (*s2)) ? str1_longer_str2 : str2_longer_str1;

        s1++;
        s2++;
    }

    return complete_value;
}


//----------------------------------------------------------------------------------------------------------------------
int My_Compare_Str_Rhyme (const void* point1, const void* point2)
{
    my_assert(point1 == NULL);
    my_assert(point2 == NULL);

    const struct Inf_Lines* line1 = (const struct Inf_Lines*) point1;
    const struct Inf_Lines* line2 = (const struct Inf_Lines*) point2;

    const char* s1 = line1->str;
    const char* s2 = line2->str;


    size_t len1 = line1->len;
    size_t len2 = line2->len;

    while (len1 > 0 && len2 > 0) {

        while (len1 > 0 && Check_Characters (s1[len1 - 1]))

            len1--;

        while (len2 > 0 && Check_Characters (s2[len2 - 1]))

            len2--;

        if (len1 == 0 && len2 == 0)

            return str1_equals_str2;

        if (len1 == 0)

            return str2_longer_str1;

        if (len2 == 0)

            return str1_longer_str2;

        if (toupper (s1[len1 - 1]) != toupper (s2[len2 - 1]))

            return (toupper (s1[len1 - 1]) > toupper (s2[len2 - 1])) ? str1_longer_str2 : str2_longer_str1;

        len1--;
        len2--;
    }

    return complete_value;
}


//-------------------------------------------------------------------------------
_Bool Check_Characters (char sym)
{
    return (isspace (sym) || ispunct (sym) || isdigit (sym));
}
