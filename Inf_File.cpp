#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <sys/stat.h>

#include "some.h"

FILE* Open_File (const char* filename_read)
{
     FILE* fp = fopen (filename_read , "r");

    if (fp == NULL) {

        printf ("Error: Oткрыть файл %s не удалось" , filename_read);
        perror ("EDA");
    }

    return fp;
}
//---------------------------------------------------------------------


//---------------------------------------------------------------------
int Calculate_Size_File (FILE* fp , struct Text* Onegin)
{
    my_assert (Onegin == 0);


    struct stat buf = {};
    int indicator = fstat (fileno (fp) , &buf);// прповерить возвращаемое условие

     if (indicator == -1) {

        printf ("Error: Не удалось получить информацию из файла");
        perror (" ");

        return errno;
    }

    Onegin->size = buf.st_size; // +1

    return 0;
}


int Calculate_Num_Lines_File (FILE* fp , struct Text* Onegin)
{
    my_assert (Onegin == 0);

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
