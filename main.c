#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_running = true;
char todos[100][256];
int todos_count = 0;

int get_operation_from_user()
{
    int operation;

    printf("Please select one of the following operations: \n");
    printf("1. List todos\n");
    printf("2. Add todo\n");
    printf("3. Remove todo\n");
    printf("4. Exit\n");
    printf("Operation: ");
    scanf("%d", &operation);
    // this will avoid fgets picking up \n from previous command before it can read input
    getchar();

    return operation;
};

void list_todos()
{
    int i;
    for (i = 0; i < todos_count; i++)
    {
        printf("[%d] %s \n", i + 1, todos[i]);
    }
}

void add_todo()
{
    char response[256];

    printf("Enter your todo: ");
    fgets(response, 256, stdin);
    // to stop adding \n after user hits return.
    response[strcspn(response, "\n")] = '\0';

    // add to array and increment count:
    strcpy(todos[todos_count], response);
    todos_count++;
}

void remove_todo()
{
    int removed_todo;
    printf("please select index of the todo you would like to remove: \n");
    list_todos();

    printf("Index: ");
    scanf("%d", &removed_todo);
    getchar();

    if (removed_todo < 1 || removed_todo > todos_count)
    {
        printf("wrong index \n");
        return;
    }

    int i;
    for (i = removed_todo - 1; i < todos_count - 1; i++)
    {
        strcpy(todos[i], todos[i + 1]);
    }
    todos_count--;
}

void route_operation(int operation)
{
    switch (operation)
    {
    case 1:
        list_todos();
        break;
    case 2:
        add_todo();
        break;
    case 3:
        remove_todo();
        break;
    case 4:
        printf("closing program... \n");
        is_running = false;
        break;
    }
}

int main(void)
{
    while (is_running)
    {
        int selection = get_operation_from_user();
        route_operation(selection);
    }
    return 0;
}
