// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Defines the type of the elements in the linked list. You may change this if
 * you want! */
typedef int elem;

/* Defines the node structure. Each node contains its element, and points to the
 * next node in the list. The last element in the list should have NULL as its
 * next pointer. */
struct node {
    elem value;
    struct node *next;
};
typedef struct node node_t;

/* Defines the list structure, which simply points to the first node in the
 * list. */
struct list {
    node_t *head;
};
typedef struct list list_t;

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc() {
    list_t *new_list = (list_t *)malloc(sizeof(list_t));
    if (new_list) {
        new_list->head = NULL;
    }
    return new_list;
}

void list_free(list_t *l) {
    if (!l) return; // Check for NULL list
    node_t *current = l->head;
    while (current) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    free(l);
}

/* Prints the list in some format. */
void list_print(list_t *l) {
    if (!l) return; // Check for NULL list
    node_t *current = l->head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

/* Returns a string representation of the list. */
char* listToString(list_t *l) {
    if (!l) return NULL; // Check for NULL list
    // Calculate the length of the string representation
    int total_length = 0;
    node_t *current = l->head;
    while (current) {
        // Each element is assumed to be a maximum of 11 characters (for INT_MIN)
        total_length += 11;
        current = current->next;
    }
    total_length++; // For the null-terminator

    char *str = (char *)malloc(total_length * sizeof(char));
    if (!str) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Build the string representation
    current = l->head;
    int offset = 0;
    while (current) {
        int written = snprintf(str + offset, total_length - offset, "%d ", current->value);
        if (written < 0 || written >= total_length - offset) {
            fprintf(stderr, "Error formatting string.\n");
            free(str);
            exit(EXIT_FAILURE);
        }
        offset += written;
        current = current->next;
    }

    return str;
}

/* Returns the length of the list. */
int list_length(list_t *l) {
    if (!l) return 0; // Check for NULL list
    int length = 0;
    node_t *current = l->head;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

/* Methods for adding to the list. */
void list_add_to_back(list_t *l, elem value) {
    if (!l) return; // Check for NULL list
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;

    if (!l->head) {
        l->head = new_node;
    } else {
        node_t *current = l->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void list_add_to_front(list_t *l, elem value) {
    if (!l) return; // Check for NULL list
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
    if (!l || index < 1) return; // Check for NULL list and invalid index
    if (index == 1) {
        list_add_to_front(l, value);
        return;
    }

    int current_index = 1;
    node_t *current = l->head;
    while (current && current_index < index - 1) {
        current = current->next;
        current_index++;
    }

    if (current) {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        if (!new_node) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        new_node->value = value;
        new_node->next = current->next;
        current->next = new_node;
    } else {
        fprintf(stderr, "Invalid index for insertion.\n");
    }
}

/* Methods for removing from the list. Returns the removed element. */
elem list_remove_from_back(list_t *l) {
    if (!l || !l->head) {
        fprintf(stderr, "List is empty.\n");
        exit(EXIT_FAILURE);
    }

    if (l->head->next == NULL) {
        elem value = l->head->value;
        free(l->head);
        l->head = NULL;
        return value;
    }

    node_t *current = l->head;
    while (current->next->next) {
        current = current->next;
    }

    elem value = current->next->value;
    free(current->next);
    current->next = NULL;
    return value;
}

elem list_remove_from_front(list_t *l) {
    if (!l || !l->head) {
        fprintf(stderr, "List is empty.\n");
        exit(EXIT_FAILURE);
    }

    elem value = l->head->value;
    node_t *temp = l->head;
    l->head = l->head->next;
    free(temp);
    return value;
}

elem list_remove_at_index(list_t *l, int index) {
    if (!l || !l->head || index < 1) {
        fprintf(stderr, "List is empty or index is invalid.\n");
        exit(EXIT_FAILURE);
    }

    if (index == 1) {
        return list_remove_from_front(l);
    }

    int current_index = 1;
    node_t *current = l->head;
    while (current->next && current_index < index - 1) {
        current = current->next;
        current_index++;
    }

    if (current->next) {
        node_t *temp = current->next;
        elem value = temp->value;
        current->next = temp->next;
        free(temp);
        return value;
    } else {
        fprintf(stderr, "Invalid index for removal.\n");
        exit(EXIT_FAILURE);
    }
}

/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value) {
    if (!l) return false; // Check for NULL list
    node_t *current = l->head;
    while (current) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/* Returns the element at the given index. Starting index is 1. Return -1 error */
elem list_get_elem_at(list_t *l, int index) {
    if (!l || index < 1) {
        fprintf(stderr, "List is empty or index is invalid.\n");
        exit(EXIT_FAILURE);
    }

    int current_index = 1;
    node_t *current = l->head;
    while (current && current_index < index) {
        current = current->next;
        current_index++;
    }

    if (current) {
        return current->value;
    } else {
        fprintf(stderr, "Invalid index for retrieval.\n");
        exit(EXIT_FAILURE);
    }
}

/* Returns the index at which the given element appears. return -1 if does not exist */
int list_get_index_of(list_t *l, elem value) {
    if (!l) return -1; // Check for NULL list
    int current_index = 1;
    node_t *current = l->head;
    while (current) {
        if (current->value == value) {
            return current_index;
        }
        current = current->next;
        current_index++;
    }
    return -1;
}












