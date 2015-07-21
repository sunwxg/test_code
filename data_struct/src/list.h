#ifndef __LIST_H
#define __LIST_H 1

#include <string.h>
#include <stdlib.h>

struct listElement {
	void * data;
	struct listElement * pre;
	struct listElement * next;
};

struct list_ {
	int size;
	struct listElement * head;
	struct listElement * tail;
};

typedef struct list_ LIST;

void list_init(LIST * l);

/* list_add_next
 * sucess: return 0
 * fail:   return -1
 */
int list_add_next(LIST * l, void *data);

/* list_rm_next
 * success: return *data of element
 * fail:    return NULL
 */
void * list_rm_next(LIST *l);


/* list_rm_element
 * success: return *data of element
 * fail:    return NULL
 */
void * list_rm_element(LIST *l, struct listElement *element);

#define list_head(list) (list)->head
#define list_tail(list) (list)->tail
#define list_size(list) (list)->size
#define list_isEmpty(list) !((list)->size)
#define list_data(list) (list)->head->data
#define list_next(list) (list)->head->next

#endif /* __LIST_H */
