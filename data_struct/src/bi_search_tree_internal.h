#ifndef __BI_SEARCH_TREE_INTERNAL_H
#define __BI_SEARCH_TREE_INTERNAL_H 1

int search_node(BI_S_TREE *b, struct bitree_node ***parent_link,
		struct bitree_node *node, void *data);

struct bitree_node * min(BI_S_TREE *b, struct bitree_node *node,
		struct bitree_node **parent_node);

void free_node(BI_S_TREE *b, struct bitree_node *node);

struct bitree_node * 
successor_replace_node(BI_S_TREE *b, struct bitree_node *node);

#endif /* __BI_SEARCH_TREE_INTERNAL_H */
