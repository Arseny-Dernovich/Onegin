
#include "My_features.h"

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
int Calculate_Size_File (FILE* fp , struct Text* Onegin)
{
    my_assert (Onegin == NULL);
    my_assert (fp == NULL);


    struct stat buf = {};
    int indicator = fstat (fileno (fp) , &buf);

     if (indicator == -1) {

        printf ("Error: Не удалось получить информацию из файла");
        perror (" ");

        return errno;
    }

    Onegin->size = buf.st_size; // +1

    return complete_value;
}
//----------------------------------------------------------------------
int Calculate_Num_Lines_File (FILE* fp , struct Text* Onegin)
{
    my_assert (Onegin == 0);
    my_assert (fp == NULL);

    int num_lines = 0;
    int ch = 0;

    while ((ch = getc (fp)) != EOF) {

        if (ch == '\n')

            num_lines++;
    }

    rewind (fp);

    Onegin->num_lines = num_lines;

    return complete_value;
}
