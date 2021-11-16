#include <stdio.h>

#include "add.h"
#include "create.h"
#include "del.h"
#include "heap.h"
#include "print.h"

void Test_1(void)
{
    struct heap *h = create_heap();

    add(h, 5);
    add(h, 10);
    add(h, 11);
    add(h, 0);
    add(h, -7);
    add(h, -17);
    add(h, 12);
    add(h, 10);
    add(h, 9);
    add(h, 7);

    print_heap(h);
    delete_heap(h);
}

int main(void)
{
    Test_1();
    return 0;
}
