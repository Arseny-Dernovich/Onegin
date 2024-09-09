#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <sys/stat.h>

struct stat buf;

const int num_str = 8;
const int num_symb = 100;


int my_strcmpy (char* str1, char* str2) {

    while (*str1 != '\0' || *str2 != '\0') {

        while (isspace (*str1) || ispunct (*str1) || isdigit (*str1))

            str1++;

        while (isspace (*str2) || ispunct (*str2) || isdigit (*str2))

            str2++;

        if (*str1 == '\0' && *str2 == '\0')

            return 0;

        if (*str1 == '\0')

            return -1;

        if (*str2 == '\0')

            return 1;

        if (toupper (*str1) != toupper (*str2)) {

            return (toupper (*str1) > toupper (*str2)) ? 1 : -1;
        }

        str1++;
        str2++;
    }

    return 0;
}

void buble_sort (char text[][num_symb])
{
   FILE* fp =fopen ("Onegin.txt" , "r");

   int size = 0;

   fstat (fileno (fp) , &buf);

   size = buf.st_size;

   printf ("%d" , size);

   char* arr = (char*) calloc (size , sizeof (char));

   int* index = {};

   for (int i = 0 ; i < num_str ; i++) {

       printf ("%s" , text[i]);
       printf ("\n");
   }

    printf ("\n\n");

    for (int i = 0 ; i < num_str ; i++) {

            index[i] = i;
    }

    for (int i = 0 ; i < num_str ; i++) {
        for (int j = 0 ; j < num_str-1 ; j++) {

            if (my_strcmpy (text[index[j]] , text[index[j+1]]) == 1) {

                int tp = index[j];
                index[j] = index[j+1];
                index[j+1] = tp;
            }
        }
    }

    for (int i = 0 ; i < num_str ; i++) {

        printf ("%s" , text[index[i]]);
        printf ("\n");
    }


}


int main (void)
{
    buble_sort(text);

    return 0;
}
