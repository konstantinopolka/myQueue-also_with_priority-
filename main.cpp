#include <iostream>
#include "Header.h"
using  namespace std;

int main()
{
    my_priopity_queue<int> list;

    list.push(1);
    list.push(333);
    list.push(23);

    list.show_list();
}

