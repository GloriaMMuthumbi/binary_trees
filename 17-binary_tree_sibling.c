#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling, NULL if no siblings or node is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (parent->left == NULL || parent->right == NULL)
		return (NULL);

	if (node == parent->left)
		return (parent->right);
	else
		return (parent->left);
}
