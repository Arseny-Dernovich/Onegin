#include "My_features.h"

void Swap (void* point1 , void* point2 , int el_size);

void Print_Array_Structs (struct Inf_Lines* arr_structs, size_t num_lines) {
    my_assert(arr_structs == NULL);

    for (size_t i = 0; i < num_lines; i++) {
        printf("Строка %zu: %s\n", i + 1, arr_structs[i].str);
    }
}
void* Bubble_Sort (void* arr , Text* Onegin , int el_size, int type_compare , My_Compare My_compare)
{
    my_assert (My_compare == NULL);
    my_assert (arr == NULL);
    my_assert (Onegin == NULL);

    //printf("Массив до сортировки внутри Bubble_Sort:\n");

    //Print_Array_Structs ((struct Inf_Lines*) arr , Onegin->num_lines);

    for (size_t i = 0; i < Onegin->num_lines; i++) {
        for (size_t j = 0; j < Onegin->num_lines - 1; j++) {

            void* element1 = (char*) arr + j * el_size;
            void* element2 = (char*) arr + (j + 1) * el_size;

            //printf("Сравнение строк: '%s' и '%s'\n", line1->str, line2->str);

            if (My_compare (element1, element2) == type_compare) {

                //printf("Меняем местами строки: '%s' и '%s'\n", line1->str, line2->str);
                Swap (element1, element2, el_size);
            }
        }
    }


    //printf("Массив после сортировки:\n");
    /*for (size_t i = 0 ; i < Onegin->num_lines ; i++) {

        struct Inf_Lines* element = (struct Inf_Lines*)((char*)arr + i * el_size);
        printf ("Строка %zu: %s\n", i + 1, element->str);
    }*/

    return arr;
}

void Swap (void* point1 , void* point2 , int el_size)
{
    my_assert (point1 == NULL);
    my_assert (point2 == NULL);

    char* pt1 = (char*) point1;
    char* pt2 = (char*) point2;

    for (int i = 0 ; i < el_size ; i++) {

        char tmp = pt1[i];
        pt1[i] = pt2[i];
        pt2[i] = tmp;
    }
}
