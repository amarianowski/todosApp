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

void load_todos()
{
    FILE *file = fopen("todos.txt", "r");

    if (file == NULL)
        return;

    while (fgets(todos[todos_count], 256, file) != NULL)
    {
        todos[todos_count][strcspn(todos[todos_count], "\n")] = '\0';
        todos_count++;
    }

    fclose(file);
}

void save_todos()
{

    FILE *file = fopen("todos.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < todos_count; i++)
    {
        fprintf(file, "%s\n", todos[i]);
    }
    fclose(file);
}

void list_todos()
{
    int i;
    for (i = 0; i < todos_count; i++)
    {
        printf("[%d] %s \n", i + 1, todos[i]);
    }
}

void add_todo(char *new_todo)
{
    // add to array and increment count:
    strcpy(todos[todos_count], new_todo);
    todos_count++;

    save_todos();
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

    save_todos();
}

void route_operation(int operation)
{
    switch (operation)
    {
    case 1:
        list_todos();
        break;
    case 2:
        char response[256];

        printf("Enter your todo: ");
        fgets(response, 256, stdin);
        // to stop adding \n after user hits return.
        response[strcspn(response, "\n")] = '\0';

        add_todo(response);
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