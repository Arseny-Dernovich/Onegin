#include "some.h"

//struct Inf_Lines* Buble_Sort (const char* filename_read , const char* filename_write , My_Compare My_Compare_Str);

int Write_Sort_Files (const char* filename_write , struct Inf_Lines* arr_structs , Text* Onegin)
{
    my_assert (arr_structs == NULL);
    my_assert (filename_write == NULL);

    FILE* fh = fopen (filename_write , "w"); // if (fh == NULL)

    if (fh == NULL) {

    printf ("Error: Oткрыть файл %s не удалось" , filename_write);
    perror (" ");

    return errno;

    }

    for (size_t i = 0 ; i < Onegin->num_lines ; i++) {

        //printf ("%s\n" , index[i]);
        fputs (arr_structs[i].str ,fh );
        fputc ('\n' , fh);
    }

    fclose(fh);

    return complete_value;
}
