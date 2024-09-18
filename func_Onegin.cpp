#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <sys/stat.h>

#include "header.h"

typedef int (*My_Compare) (const char* str1 , const char* str2);

struct Text {
size_t size , num_lines ;
char** index;
};

// void звменить чтобы проверить статус операции


int Size_Onegin (FILE* fp , struct Text* Onegin);
int Num_Lines_File (FILE* fp , struct Text* Onegin);
int My_Compare_Str_Alphabetically (const char* str1 , const char* str2);
int My_Compare_Str_Rhyme (const char* str1 , const char* str2);
char* Converting_Text_to_Arr (Text* Onegin , FILE* fp);
char* Fill_Index_Arr (char* text_Onegin ,Text Onegin);
char** Filling_Arr_Index (char* text_Onegin , Text* Onegin);
int Buble_Sort (const char* filename_read , const char* filename_write , My_Compare My_compare_Str);
_Bool Check_Characters (char sym);
int Process_Onegin (void);


//void Clean_Arr_Onegin (char* text_Onegin)
//{
int Process_Onegin (void)
{
    if (Buble_Sort ("Clean_Onegin.txt" , "sort_rhyme_Onegin.txt" , &My_Compare_Str_Rhyme) == 0 &&
        Buble_Sort ("Clean_Onegin.txt" , "sort_alpha_Onegin.txt" , &My_Compare_Str_Alphabetically) == 0)

        return 0;

    else

        return 1;
}


int Buble_Sort (const char* filename_read , const char* filename_write , My_Compare My_Compare_Str )
{
    my_assert (filename_read == 0);
    my_assert (filename_write == 0);

    struct Text Onegin = {};

    FILE* fp = fopen (filename_read , "r");

    //my_assert (fp == NULL);

    if (fp == NULL) {

        printf ("Error: Oткрыть файл %s не удалось" , filename_read);
        perror (" ");

        return errno;
    }


    Size_Onegin (fp , &Onegin);
    Num_Lines_File (fp , &Onegin);


    char* text_Onegin = Converting_Text_to_Arr (&Onegin , fp);
    Filling_Arr_Index (text_Onegin , &Onegin);

// optimization
    for (size_t i = 0 ; i < Onegin.num_lines ; i++) {
        for (size_t j = 0 ; j < Onegin.num_lines-1 ; j++) {
            if ((*My_Compare_Str) (Onegin.index[j] , Onegin.index[j+1]) == 1) {

                char* tp = Onegin.index[j];
                Onegin.index[j] = Onegin.index[j+1];
                Onegin.index[j+1] = tp;
            }
        }
    }


    FILE* fh = fopen (filename_write , "w"); // if (fh == NULL)

      if (fh == NULL) {

        printf ("Error: Oткрыть файл %s не удалось" , filename_write);
        perror (" ");

        return errno;
    }

    for (size_t i = 0 ; i < Onegin.num_lines ; i++) {

        //printf ("%s\n" , index[i]);
        fputs (Onegin.index[i] ,fh );
        fputc ('\n' , fh);
    }

    free (text_Onegin);
    fclose (fh);

    return 0;
}


int My_Compare_Str_Alphabetically (const char* str1 , const char* str2)  // const assert
{

    my_assert (str1 == 0);
    my_assert (str2 == 0);

    while (*str1 != '\0' || *str2 != '\0') {

        while (Check_Characters (*str1))

            str1++;

        while (Check_Characters (*str2))

            str2++;

        if (*str1 == '\0' && *str2 == '\0')

            return 0;

        if (*str1 == '\0')

            return -1;

        if (*str2 == '\0')

            return 1;

        if (toupper (*str1) != toupper (*str2) /*&& isalpha (*str1)*/   ) {

            return (toupper (*str1) > toupper (*str2)) ? 1 : -1;
        }

        str1++;
        str2++;
    }

    return 0;
}

/*
 * функция возащает ...
 */
int My_Compare_Str_Rhyme (const char* str1, const char* str2)
{
    my_assert (str1 == 0);
    my_assert (str2 == 0);

    size_t len_str1 = strlen (str1);
    size_t len_str2 = strlen (str2);


    while (len_str1 > 0 && len_str2 > 0) {

        while (len_str1 > 0 && Check_Characters (str1[len_str1 - 1]) ) {

            len_str1--;
        }

        // len_str1 -= foo ();

        while (len_str2 > 0 && Check_Characters (str2[len_str2 - 1])) {

            len_str2--;
        }

        if (len_str1 == 0 && len_str2 == 0) {

            return 0;
        }

        if (len_str1 == 0) {

            return -1;
        }

        if (len_str2 == 0) {

            return 1;
        }

        if (toupper (str1[len_str1 - 1]) != toupper (str2[len_str2 - 1])) {

            return (toupper (str1[len_str1 - 1]) > toupper (str2[len_str2 - 1])) ? 1 : -1;
        }

        len_str1--;
        len_str2--;
    }

    return 0;
}


int Size_Onegin (FILE* fp , struct Text* Onegin) // assert
{
    my_assert (fp == 0);
    my_assert (Onegin == 0);

    struct stat buf = {};
    int indicator = fstat (fileno (fp) , &buf);// прповерить возвращаемое условие

     if (indicator == -1) {

        printf ("Error: Не удалось получить информацию из файла");
        perror (" ");

        return errno;
    }

    Onegin->size = buf.st_size; // +1

    return 0 ;
}


int Num_Lines_File (FILE* fp , struct Text* Onegin)
{
    size_t num_lines = 0;
    int ch = 0;

    while ((ch = getc (fp)) != EOF) {

        if (ch == '\n')

            num_lines++;
    }

    rewind (fp);

    Onegin->num_lines = num_lines;

    return 0;
}


char* Converting_Text_to_Arr (Text* Onegin , FILE* fp)
{
    my_assert (Onegin == NULL);
    my_assert (fp == NULL);

    char* text_Onegin = (char*) calloc (Onegin->size + 1 , sizeof (char));

    my_assert (text_Onegin == NULL);

    Onegin->size = fread (text_Onegin , sizeof (char) , Onegin->size , fp);
    text_Onegin[Onegin->size] = '\0';

    fclose (fp);

    return text_Onegin;

}


char** Filling_Arr_Index (char* text_Onegin , Text* Onegin)
{
    my_assert (Onegin == NULL);
    my_assert (text_Onegin == NULL);

    Onegin->index = (char**) calloc (Onegin->num_lines , sizeof (char*));

    my_assert (Onegin->index == NULL);

    size_t line_count = 0;

    Onegin->index[line_count] = text_Onegin;
    line_count++;

    for (size_t i = 0 ; i < Onegin->size ; i++) {

        if (text_Onegin[i] == '\n') {

            text_Onegin[i] = '\0';

            if (line_count < Onegin->num_lines /*&& isalpha (text_Onegin[i+1])*/) {

                Onegin->index [line_count] = &text_Onegin[i+1];
                line_count++;


            }
        }
    }

    return Onegin->index;
}


_Bool Check_Characters (char sym)
{
    return (isspace (sym) || ispunct (sym) || isdigit (sym));
}







































