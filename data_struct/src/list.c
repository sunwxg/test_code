#include "list.h"

void list_init(LIST * l)
{
	l->size = 0;
	l->head = NULL;
	l->tail = NULL;
}

int list_add_next(LIST * l, void *data)
{
	struct listElement *element;

	element = (struct listElement *)calloc(1, sizeof(struct listElement));

	if (element == NULL)
		return -1;
	
	element->data = data;

	element->next = list_head(l);
	element->pre = NULL;

	if (list_size(l) != 0)
		element->next->pre = element;

	list_head(l) = element;
	if (list_size(l) == 0)
		list_tail(l) = element;

	list_size(l)++;

	return 0;
}

void * list_rm_next(LIST * l)
{
	struct listElement *old_element;
	void *data;

	if (list_size(l) == 0)
		return NULL;

	old_element = list_head(l);
	data = list_data(l);

	list_head(l) = old_element->next;

	if (list_size(l) > 1)
		list_head(l)->pre = NULL;

	if (list_size(l) == 1)
		list_tail(l) = NULL;

	list_size(l)--;

	free(old_element);

	return data;
}

void * list_rm_element(LIST *l, struct listElement *element)
{
	void *data = element->data;
	struct listElement *pre_element = element->pre;

	if (element == list_head(l)) {
		list_rm_next(l);
		return data;
	}

	pre_element->next = element->next;
	if (element->next != NULL) {
		struct listElement *next_element = element->next;
		next_element->pre = pre_element;
	}

	free(element);

	list_size(l)--;

	return data;
}
