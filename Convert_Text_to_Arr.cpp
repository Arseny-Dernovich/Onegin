#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <sys/stat.h>

#include "My_features.h"

char* Converting_Text_to_Arr (Text* Onegin , FILE* fp)
{
    my_assert (Onegin == NULL);
    my_assert (fp == NULL);

    char* text_Onegin = (char*) calloc (Onegin->size + 1 , sizeof (char));

    my_assert (text_Onegin == NULL);

    Onegin->text_Onegin = text_Onegin;

    Onegin->size = fread (text_Onegin , sizeof (char) , Onegin->size , fp);
    text_Onegin[Onegin->size] = '\0';

    return text_Onegin;

}
