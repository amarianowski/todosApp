#include <assert.h>
#include "todos.h"
#include <stdio.h>

void test_add_todo()
{
    add_todo("go shopping");

    assert(todos_count == 1);
}

int main()
{
    test_add_todo();
    printf("all tests passed! \n");
}