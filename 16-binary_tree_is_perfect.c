#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary is perfect
 * @tree: pointer to the root of the binary tree
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, level_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	level_nodes = 1 << height;

	return (binary_tree_is_perfect_recursive(
				tree, height, 0, level_nodes = 1));
}

/**
 * binary_tree_is_perfect_recursive - helpter function to recursively
 * check if binary tree is perfect
 * @tree: pointer to the root of the binary tree
 * @height: height of the tree
 * @level: current level of the tree
 * @max_level: maximum level of the tree
 * 
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree,
                                      size_t height, size_t level,
				      size_t max_level)
{
	if (tree == NULL)
		return (level == max_level);

	if (tree->left == NULL && tree->right == NULL)
		return (level == max_level);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_perfect_recursive(
				tree->left, height, level + 1, max_level) &&
			binary_tree_is_perfect_recursive(
				tree->right, height, level + 1, max_level));
}

/**
 * binary_tree_height - helper function to find the height of tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the binary tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ?
				left_height : right_height) + 1);
}
