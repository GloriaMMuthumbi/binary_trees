#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if give node is a root
 * @node: pointer to the node to be checked
 *
 * Return: 1 if the node is a root, otherwise 0 or if node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
