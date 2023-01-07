// Code example from arrays short
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // instantiation syntax
    bool truthtable[3] = {false, true, true};

    // individual element syntax
    bool truthtable2[3];
    truthtable[0] = false;
    truthtable[1] = true;
    truthtable[2] = true;


    // Array size can be omitted with this syntax
    bool truthtable3[] = {false, true, true};
}