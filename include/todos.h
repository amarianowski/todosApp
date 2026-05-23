
#ifndef TODOS_H
#define TODOS_H
#include <stdbool.h>

extern int todos_count;
extern bool is_running;

void add_todo(char *new_todo);
void list_todos();
void load_todos();
int get_operation_from_user();
void route_operation(int operation);

#endif