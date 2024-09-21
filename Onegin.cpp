#include "My_features.h"



void print_usage ()
{
    printf("%sИспользование программы:\n" , blue);
    printf("./program_name <тип сортировки> <тип сравнения>\n");
    printf("Где <тип сортировки> может быть:                <тип сравнения> может быть:\n");
    printf("1 - Алфавитная сортировка                       1 - сравнение по возрастанию\n");
    printf("2 - Сортировка по рифме                         -1 - сравнение по убыванию\n");
    printf ("%s" , end);
}
//---------------------------------------------------------------------------------------------


int Process_Onegin(Text* Onegin, int* sort_type) {
    my_assert (Onegin == NULL);
    my_assert (sort_type == NULL);

    struct Inf_Lines* sort_arr_structs = NULL;
    struct Arr_Structs arr = {};

    Filling_Arr_Structs (Onegin, &arr);

    if (sort_type[0] == SORT_ALPHABETICALLY) {

        if (sort_type[1] == INCRE) {// qsort

            qsort (arr.arr_structs , Onegin->num_lines , sizeof (Inf_Lines) , My_Compare_Str_Alphabetically);
            sort_arr_structs = arr.arr_structs;//(struct Inf_Lines*) Bubble_Sort (arr.arr_structs , Onegin , sizeof(arr.arr_structs[0]) , INCRE , My_Compare_Str_Alphabetically);
            Write_Sort_Files ("Sort_Alpha_Incr_Onegin.txt" , sort_arr_structs , Onegin);

        } else if (sort_type[1] == DECRE) {

            sort_arr_structs = (struct Inf_Lines*) Bubble_Sort (arr.arr_structs , Onegin , sizeof(Inf_Lines) , DECRE , My_Compare_Str_Alphabetically);
            Write_Sort_Files ("Sort_Alpha_Decre_Onegin.txt" , sort_arr_structs , Onegin);

        } else {

            printf ("Ошибка: некорректный выбор типа сравнения.\n");
            print_usage ();
        }
    }

    else if (sort_type[0] == SORT_BY_RHYME) {

        if (sort_type[1] == INCRE) { //qsort

            qsort (arr.arr_structs , Onegin->num_lines , sizeof (Inf_Lines) , My_Compare_Str_Rhyme);
            sort_arr_structs = arr.arr_structs;   //(struct Inf_Lines*) Bubble_Sort (arr.arr_structs , Onegin , sizeof(Inf_Lines) , INCRE , My_Compare_Str_Rhyme);
            Write_Sort_Files ("Sort_Rhyme_Incre_Onegin.txt" , sort_arr_structs, Onegin);

        } else if (sort_type[1] == DECRE) {

            sort_arr_structs = (struct Inf_Lines*) Bubble_Sort (arr.arr_structs , Onegin, sizeof(Inf_Lines) , DECRE , My_Compare_Str_Rhyme);
            Write_Sort_Files ("Sort_Rhyme_Decre_Onegin.txt" , sort_arr_structs , Onegin);

        } else {

            printf ("Ошибка: некорректный выбор типа сравнения.\n");
            print_usage ();
        }

    } else {

        printf ("Ошибка: некорректный выбор типа сортировки.\n");
        print_usage ();

        return incomplete_value;
    }

    return complete_value;
}


