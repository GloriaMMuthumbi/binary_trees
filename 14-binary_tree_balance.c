#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_height - measures the height of the binary tree
 * @tree: pointer to the root of the binary tree
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t left_side = 0, right_side = 0;

        if (tree == NULL)
                return (0);

        left_side = (tree->left) ?
                1 + binary_tree_height(tree->left) : 1;
        right_side = (tree->right) ?
                1 + binary_tree_height(tree->right) : 1;
        return (left_side > right_side ? left_side : right_side);
}

/**
 * binary_tree_balance - measures the balance factor for
 * a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: the measure for balance, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) -
				binary_tree_height(tree->right));
	}
	return (0);
}
