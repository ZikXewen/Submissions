#include <iostream>
#include "rescuelib.h"

using namespace std;

int R,C;

int main()
{
    get_size(R,C);

    int d1 = drop_robot(1,1); 
    answer(1,1);
    return 0;
}
