#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two
 * given nodes, NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *first_ancestor, *second_ancestor;

	for (first_ancestor = first; first_ancestor;
			first_ancestor = first_ancestor->parent)
		for (second_ancestor = second; second_ancestor;
				second_ancestor = second_ancestor->parent)
			if (first_ancestor == second_ancestor)
				return ((binary_tree_t *)first_ancestor);

	return (NULL);
}

