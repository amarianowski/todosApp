#include "todos.h"

int main(void)
{
    load_todos();
    while (is_running)
    {
        int selection = get_operation_from_user();
        route_operation(selection);
    }
    return 0;
}