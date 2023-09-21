#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist;
  mylist = list_alloc();
  list_print(mylist);
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_print(mylist);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_add_to_front : FAILED\n");
  }

  list_print(mylist);
  list_remove_at_index(mylist, 3);
  list_print(mylist);

  if(strcmp("100->90->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }

  list_remove_at_index(mylist, 20);
  list_print(mylist);
  list_remove_at_index(mylist, 1);
  list_print(mylist);
  list_remove_at_index(mylist, 6);
  list_print(mylist);

  if(strcmp("90->80->60->50->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }
  

  // printf("The list length is %d\n", list_length(mylist));

  // list_add_to_back(mylist, 39);
  // list_print(mylist);
  // list_add_to_back(mylist, 18);
  // list_add_to_back(mylist, 42);
  // list_add_to_back(mylist, 190);
  // list_print(mylist);
  // list_free(mylist);
  // list_print(mylist);

  // list_add_to_front(mylist, 81);
  // list_add_to_back(mylist, 4);
  // list_add_to_front(mylist, 308);
  // list_add_to_back(mylist, 70);
  // list_add_to_front(mylist, 290);
  // list_print(mylist);
  // printf("The list length is %d\n", list_length(mylist));
  
  // list_add_at_index(mylist, 21, 1);
  // list_add_at_index(mylist, 65, 0);
  // list_add_at_index(mylist, 10, 8);
  // list_print(mylist);
  // list_add_at_index(mylist, 10, 7);
  // list_print(mylist);

  // list_remove_from_back(mylist);
  // list_print(mylist);
  // list_remove_from_front(mylist);
  // list_print(mylist);
  // list_remove_at_index(mylist, 3);
  // list_print(mylist);

  // printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
  printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
  printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));
  printf("Index of %d?: %d\n", 70, list_get_index_of(mylist, 70));
  printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
  printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  printf("Index of %d?: %d\n", 90, list_get_index_of(mylist, 90));
  // printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  
  // list_free(mylist);
  // list_add_at_index(mylist, -1, -1);
  // list_print(mylist);
  // list_add_at_index(mylist, -1, -1);
  // list_print(mylist);
  // list_add_at_index(mylist, 10, 0);
  // list_print(mylist);
  // list_add_at_index(mylist, 20, 1);
  // list_print(mylist);
  // list_free(mylist);
  // printf("The list length is %d\n", list_length(mylist));
  // list_print(mylist);

  // list_remove_from_back(mylist);
  // list_remove_from_front(mylist);
  // list_remove_at_index(mylist, -3);
  // list_remove_at_index(mylist, 0);
  // list_remove_at_index(mylist, 2);
  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 60);
  // list_add_at_index(mylist, 50, 1);
  // list_add_at_index(mylist, 0, 6);
  // list_add_at_index(mylist, 70, 0);
  // list_add_at_index(mylist, 80, 12);
  // list_print(mylist);

  // list_free(mylist);
  // list_free(mylist);
  // list_add_to_back(mylist, 100);
  // list_print(mylist);
  // list_remove_from_front(mylist);
  // list_print(mylist);
  // list_add_to_back(mylist, 13);  
  // list_print(mylist);
  // list_remove_from_back(mylist);
  // list_print(mylist);

  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);
  // list_remove_at_index(mylist, -2);
  // list_print(mylist);
  // list_remove_at_index(mylist, 7);
  // list_print(mylist);
  // list_remove_at_index(mylist, 4);
  // list_print(mylist);

  // list_free(mylist);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // list_remove_at_index(mylist, 1);
  // list_print(mylist);
  // list_add_to_front(mylist, 80);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);

  // printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  // list_add_to_back(mylist, 50);
  // list_add_to_back(mylist, 60);
  // list_add_to_back(mylist, 70);
  // list_add_to_back(mylist, 80);
  // list_add_to_back(mylist, 90);
  // list_print(mylist);
  // printf("Is %d in the list?: %d\n", 30, list_is_in(mylist, 30));
  // printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  // printf("Is %d in the list?: %d\n", 80, list_is_in(mylist, 80));
  // list_add_to_back(mylist, 70);
  // list_print(mylist);
  // printf("Is %d in the list?: %d\n", 70, list_is_in(mylist, 70));
  
  // printf("The list length is %d\n", list_length(mylist));
  // printf("Value at %d in the list?: %d\n", -4, list_get_elem_at(mylist, -4));
  // printf("Value at %d in the list?: %d\n", 10, list_get_elem_at(mylist, 10));
  // printf("Value at %d in the list?: %d\n", 6, list_get_elem_at(mylist, 6));
  // printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  // printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  // list_free(mylist);
  // list_print(mylist);
  // printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  // list_remove_at_index(mylist, 0);
  // printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  // printf("Index of %d?: %d\n", 21, list_get_index_of(mylist, 21));
  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 50);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  // printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  // printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  // printf("Index of %d?: %d\n", 30, list_get_index_of(mylist, 30));
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  // printf("Index of %d?: %d\n", 60, list_get_index_of(mylist, 60));
  // list_add_to_front(mylist, 10);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  // list_add_to_back(mylist, 40);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 40, list_get_index_of(mylist, 40));
  list_t *my_list = list_alloc();
    
    // Test an empty list
    printf("Testing an empty list:\n");
    list_print(my_list); // Should print: (empty)
    char *listStr = listToString(my_list);
    if (strcmp("NULL", listStr) == 0) {
        printf("listToString: PASSED\n");
    } else {
        printf("listToString: FAILED\n");
    }
    free(listStr);
    printf("List length: %d\n", list_length(my_list)); // Should print: List length: 0

    // Test adding elements to the list
    printf("\nTesting adding elements:\n");
    list_add_to_back(my_list, 10);
    list_add_to_back(my_list, 20);
    list_add_to_front(my_list, 5);
    list_add_at_index(my_list, 15, 2);
    
    list_print(my_list); // Should print: 5 15 10 20
    listStr = listToString(my_list);
    if (strcmp("5->15->10->20->NULL", listStr) == 0) {
        printf("listToString: PASSED\n");
    } else {
        printf("listToString: FAILED\n");
    }
    free(listStr);
    printf("List length: %d\n", list_length(my_list)); // Should print: List length: 4

    // Test removing elements from the list
    printf("\nTesting removing elements:\n");
    printf("Removing from back: %d\n", list_remove_from_back(my_list)); // Should print: Removing from back: 20
    printf("Removing from front: %d\n", list_remove_from_front(my_list)); // Should print: Removing from front: 5
    list_print(my_list); // Should print: 15 10

    list_remove_at_index(my_list, 5); // Removing at an invalid index
    list_remove_at_index(my_list, -1); // Removing at an invalid index
    list_remove_at_index(my_list, 2);
    list_print(my_list); // Should print: 15

    // Test list_is_in function
    printf("\nTesting list_is_in function:\n");
    printf("Is 15 in the list?: %d\n", list_is_in(my_list, 15)); // Should print: Is 15 in the list?: 1
    printf("Is 10 in the list?: %d\n", list_is_in(my_list, 10)); // Should print: Is 10 in the list?: 1
    printf("Is 5 in the list?: %d\n", list_is_in(my_list, 5)); // Should print: Is 5 in the list?: 0

    // Test list_get_elem_at and list_get_index_of functions
    printf("\nTesting list_get_elem_at and list_get_index_of functions:\n");
    printf("Element at index 2: %d\n", list_get_elem_at(my_list, 2)); // Should print: Element at index 2: 10
    printf("Element at index 3: %d\n", list_get_elem_at(my_list, 3)); // Should print: Element at index 3: -1 (invalid)
    printf("Index of element 10: %d\n", list_get_index_of(my_list, 10)); // Should print: Index of element 10: 2
    printf("Index of element 5: %d\n", list_get_index_of(my_list, 5)); // Should print: Index of element 5: -1 (not in list)

    // Clean up
    list_free(my_list);
  return 0;
}