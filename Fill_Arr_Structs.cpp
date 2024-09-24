#include "My_features.h"



struct Inf_Lines* Filling_Arr_Structs (Text* Onegin , Arr_Structs* arr)
{
    my_assert (Onegin == NULL);
    my_assert (arr == NULL);

    FILE* fp = Open_File ("Clean_Onegin.txt");

    Calculate_Size_File (fp , Onegin);
    Calculate_Num_Lines_File (fp , Onegin);
    Converting_Text_to_Arr (Onegin , fp);

    fclose (fp);

    arr->arr_structs = (struct Inf_Lines*) calloc (Onegin->num_lines , sizeof (struct Inf_Lines));

    my_assert (arr->arr_structs == NULL);

    int line_count = 0;

    char* line_start = Onegin->text_Onegin;

    for (size_t i = 0 ; i < Onegin->size ; i++) {

        if (Onegin->text_Onegin[i] == '\n') {

            Onegin->text_Onegin[i] = '\0';

            if (line_count < Onegin->num_lines) {

                arr->arr_structs[line_count].str = line_start;
                arr->arr_structs[line_count].len = strlen (line_start);

                line_count++;

                line_start = &Onegin->text_Onegin[i+1];
            }
        }
    }

    return arr->arr_structs;
}
