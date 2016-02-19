#include "stdio.h"
#include "stdlib.h"

// Linked List

typedef struct ListNode {
  int data;
  struct ListNode *next;
} ListNode;

void list_node_init(ListNode *node, int data)
{
  node->data = data;
  node->next = 0;
}

typedef struct List {
  ListNode *head;
  // ...
} List;

void list_init(List *list)
{
  list->head = 0;
}

void list_add(List *list, ListNode *new_node)
{
  if (list == 0)
  {
    return;
  }
  else if (list->head == 0)
  {
    list->head = new_node;
    return;
  }
  
  ListNode *next_node = list->head;
  while (next_node)
  {
    if (!next_node->next)
    {
      next_node->next = new_node;
      return;
    }
    
    next_node = next_node->next;
  }
}

void list_remove(List *list, ListNode *to_remove)
{
  if (list == 0)
  {
    return;
  }
  
  ListNode *next_node = list->head, *prev_node = 0;
  while (next_node)
  {
    if (next_node == to_remove)
    {
      if (prev_node)
      {
	prev_node->next = next_node->next;
      }
      else
      {
	list->head = next_node->next;
      }

      return;
    }

    prev_node = next_node;
    next_node = next_node->next;
  }
}

void list_clear(List *list)
{
  while (list->head)
  {
    ListNode *next_node = list->head;
    list_remove(list, next_node);
    free(next_node);
  }
}

void list_print(List *list)
{
  if (list == 0)
  {
    return;
  }
  
  ListNode* next_node = list->head;
  while (next_node)
  {
    printf("%d ", next_node->data);
    next_node = next_node->next;
  }

  printf("\n");
}

void list_reverse(List *list)
{
  if (list == 0)
  {
    return;
  }
  
  ListNode *prev_node = 0,
    *current_node = list->head,
    *next_node = 0;
  while (current_node)
  {
    next_node = current_node->next;
    current_node->next = prev_node;
    prev_node = current_node;

    if (next_node == 0)
    {
      break;
    }
    
    current_node = next_node;
  }

  list->head = current_node;
}

int main(int argc, char *argv[])
{
  // Build list.
  List *list = (List *) malloc(sizeof(List));
  list_init(list);
  
  int i = 0;
  for (i = 0; i < 10; ++i)
  {
    ListNode *next_node = (ListNode *) malloc(sizeof(ListNode));
    list_node_init(next_node, i);
    
    list_add(list, next_node);
  }

  list_print(list);
  
  // Reverse List.
  list_reverse(list);

  list_print(list);
  
  // Delete list.
  list_clear(list);
  
  list_print(list);

  free(list);
  
  return 0;
}
