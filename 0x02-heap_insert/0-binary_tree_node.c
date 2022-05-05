#include "binary_trees.h"

/**
 * binary_tree_node - Function that creates a binary tree node
 *
 * @parent: Parent node pointer
 * @value: Value for the new node
 *
 * Return: Pointer to the new node or null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
