#include "My_features.h"

int Process_Onegin (Text* Onegin , int* sort_type);
void print_usage();


int main (int argc, char* argv[])
{
    my_assert (argv == NULL);

    struct Text Onegin = {};

    if (argc != 3) {

        printf("Ошибка:\n");
        print_usage();

        return incomplete_value;
    }

    int sort_type[2] = {atoi (argv[1]) , atoi (argv[2])};

    if (sort_type[0] != SORT_ALPHABETICALLY && sort_type[0] != SORT_BY_RHYME) {

        printf("Ошибка: некорректный выбор типа сортировки.\n");
        print_usage();

        return incomplete_value;
    }

    Process_Onegin (&Onegin, sort_type);

    return complete_value;
}





