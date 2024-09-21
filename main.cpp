#include "My_features.h"





int main (int argc, char* argv[])
{
    my_assert (argv == NULL);

    struct Text Onegin = {};

    if (argc != 3) {

        printf("%sОшибка:\n" , red);
        print_usage();

        return incomplete_value;
    }

    int sort_type[2] = {atoi (argv[1]) , atoi (argv[2])};

    Process_Onegin (&Onegin, sort_type);

    return complete_value;
}





