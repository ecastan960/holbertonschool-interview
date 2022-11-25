#include "binary_trees.h"

/**
 * check_bst - Checks if a tree is a BST
 * @tree: ptr to root node
 * @min: minimum constraint
 * @max: maximum constraint
 *
 * Return: 1 if is a BST, 0 if not
 */

int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (check_bst(tree->left, min, tree->n - 1) &&
		check_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Calculate height of binary tree
 * @tree: pointer to root
 *
 * Return: size_t height of tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_count, left_count;

	if (tree == NULL)
		return (0);

	if (!tree->right && !tree->left)
		return (0);

	right_count = binary_tree_height(tree->right);
	left_count = binary_tree_height(tree->left);

	if (left_count > right_count)
		return (left_count + 1);
	else
		return (right_count + 1);
}

/**
 * binary_tree_is_avl - checks if binary tree is valid AVL tree
 *
 * @tree: pointer to root
 *
 * Return: 1 if valid AVL, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t h_left;
	size_t h_right;
	size_t diff;

	if (!tree)
		return (0);
	if (!check_bst(tree, INT_MIN, INT_MAX))
		return (0);

	h_left = tree->left ? binary_tree_height(tree->left) : 0;
	h_right = tree->right ? binary_tree_height(tree->right) : 0;

	if (h_left > h_right)
		diff = h_left - h_right;
	else
		diff = h_right - h_left;

	if (diff > 1)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
