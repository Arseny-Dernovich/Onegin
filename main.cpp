#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <sys/stat.h>

#include "some.h"

int Process_Onegin (Text* Onegin , int* sort_type);
void print_usage();


int main (int argc, char* argv[])
{
    struct Text Onegin = {};

    if (argc != 3) {

        printf("Ошибка: необходимо указать тип сортировки.\n");
        print_usage();

        return 1;
    }

    int sort_type[2] = {atoi (argv[1]) , atoi (argv[2])};

    if (sort_type[0] != SORT_ALPHABETICALLY && sort_type[0] != SORT_BY_RHYME) {

        printf("Ошибка: некорректный выбор типа сортировки.\n");
        print_usage();

        return 1;
    }

    Process_Onegin (&Onegin, sort_type);

    return 0;
}





