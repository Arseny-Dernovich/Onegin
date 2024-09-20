#include "some.h"

struct Inf_Lines* Bubble_Sort (My_Compare My_Compare_Str , Text* Onegin , int type_compare);
int My_Compare_Str_Alphabetically (struct Inf_Lines struct1 , struct Inf_Lines struct2);
int My_Compare_Str_Rhyme (struct Inf_Lines struct1, struct Inf_Lines struct2);
int Write_Sort_Files (const char* filename_write , struct Inf_Lines* arr_structs , Text* Onegin);

void print_usage()
{
    printf("Использование программы:\n");
    printf("./program_name <тип сортировки> <тип сравнения>\n");
    printf("Где <типсортировки> может быть:                <тип сравнения> может быть:\n");
    printf("1 - Алфавитная сортировка                       1 - сравнение по возрастанию\n");
    printf("2 - Сортировка по рифме                         2 - сравнение по убыванию\n");
}


int Process_Onegin (Text* Onegin , int* sort_type)
{
    struct Inf_Lines* sort_arr_structs = NULL;

    my_assert (Onegin == NULL);

    if (sort_type[0] == SORT_ALPHABETICALLY) {

        if (sort_type[1] == INCRE) {

            sort_arr_structs = Bubble_Sort (&My_Compare_Str_Alphabetically , Onegin ,INCRE);
            Write_Sort_Files ("Sort_Alpha_Incr_Onegin.txt" , sort_arr_structs , Onegin);
        }

        else if (sort_type[1] == DECRE) {

            sort_arr_structs = Bubble_Sort (&My_Compare_Str_Alphabetically , Onegin , DECRE);
            Write_Sort_Files ("Sort_Alpha_Decre_Onegin.txt" , sort_arr_structs , Onegin);
        }

        else

            print_usage ();

    }

    else if (sort_type[0] == SORT_BY_RHYME) {

        if (sort_type[1] == INCRE) {

            sort_arr_structs = Bubble_Sort (&My_Compare_Str_Rhyme , Onegin , INCRE);
            Write_Sort_Files ("Sort_Rhyme_Incre_Onegin.txt" , sort_arr_structs , Onegin);
        }

        else if (sort_type[1] == DECRE) {

            sort_arr_structs = Bubble_Sort (&My_Compare_Str_Rhyme , Onegin , DECRE);
            Write_Sort_Files ("Sort_Rhyme_Decre_Onegin.txt" , sort_arr_structs , Onegin);
        }

        else

            print_usage ();
    }

    else {

        printf("Ошибка: некорректный выбор типа сортировки.\n\n");
        print_usage();

        return incomplete_value;
    }

    return complete_value;
}



