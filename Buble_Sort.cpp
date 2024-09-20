#include "My_features.h"

struct Inf_Lines* Filling_Arr_Structs (Text* Onegin);

struct Inf_Lines* Bubble_Sort (My_Compare My_Compare_Str , Text* Onegin , int type_compare) // ptr
{
    my_assert (My_Compare_Str == NULL);
    my_assert (Onegin == NULL);

    struct Inf_Lines* arr_structs = Filling_Arr_Structs (Onegin);


    for (size_t i = 0 ; i < Onegin->num_lines ; i++) {
        for (size_t j = 0 ; j < Onegin->num_lines-1 ; j++) {
            if ((*My_Compare_Str) (arr_structs[j] , arr_structs[j+1]) == type_compare) {

                struct Inf_Lines tmp = arr_structs[j];
                arr_structs[j] = arr_structs[j+1];
                arr_structs[j+1] = tmp;
            }
        }
    }

    return arr_structs;
}
