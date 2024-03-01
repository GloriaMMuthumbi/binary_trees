#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary is perfect
 * @tree: pointer to the root of the binary tree
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_perfect_recursive(
				tree, depth(get_leaf(tree)), 0));
}

/**
 * binary_tree_is_perfect_recursive - checks if binary
 * tree is perfect recursively
 * check if binary tree is perfect
 * @tree: pointer to the root of the binary tree
 * @leaf_level: level of the a leaf in the binary tree
 * @level: current level of the tree
 * 
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_level, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_level ? 1 : 0);

	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (binary_tree_is_perfect_recursive(tree->left,
				leaf_level, level + 1) &&
			binary_tree_is_perfect_recursive(
				tree->right, leaf_level, level + 1));
}

/**
 * depth - returns the depth of a node in the tree
 * @tree: pointer to the node to be measured
 *
 * Return: depth of the node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * is_leaf - checks if a node is a leaf
 * @node: pointer to the node
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * get_leaf - returns leaf of binary tree
 * @tree: pointer to the root node
 *
 * Return: pointer to the first encountered leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) :
			get_leaf(tree->right));
}
