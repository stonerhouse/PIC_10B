/*
    PIC 10B Homework 7, inttree.cpp
    Author: Will Stonehouse
    Date: 05/05/20
*/

#include "inttree.h"
#include <iostream>
#include <stddef.h>

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

/**
Print nodes in order from right to left
*/
void BinarySearchTree::print() const
{
    if (root != NULL)
        root->print_nodes();
        std::cout << "\n";
}

/**
Insert an integer element in the tree
 @param data the integer element you wish to insert
*/
void BinarySearchTree::insert(int data)
{
    TreeNode* new_node = new TreeNode;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (root == NULL) root = new_node;
    else root->insert_node(new_node);
}
/**
 The helper fucntion to insert()
 @param new_node the node you wish to insert
 */
void TreeNode::insert_node(TreeNode* new_node)
{
    if (new_node->data < data)
    {
       if (left == NULL) left = new_node;
       else left->insert_node(new_node);
    }
    else if (data <= new_node->data)
    {
       if (right == NULL) right = new_node;
       else right->insert_node(new_node);
    }
}
/**
Counts the amount of elements a value has in the tree
@param data the value we're trying to count
@return the count
*/
int BinarySearchTree::count(int data) const // Modify to find multiple
{
    int counter = 0;
    return root->count_dup(data, counter);
}

/**
 Helper function for count()
 @param value the value we're trying to count
 @param counter count the amount of duplicates
 @return the count
 */
int TreeNode::count_dup(int value, int counter) const{
        
    if (value < data)
    {
        if (left == NULL) {return counter;} // Base condition
        else {return left->count_dup(value, counter);} // Call recursively
    }
    else if (data < value)
    {
        if (right == NULL) {return counter;} // Base condition
        else {return right->count_dup(value, counter);} // Call recursively
    }
    else // If data is equal to value
    {
        ++counter;
        if (right == NULL) {return counter;} // Base condition
        else {return right->count_dup(value, counter);} // Call recursively
    }
}

/**
 Erases a node from the tree
 @param data The element you wish to erase
 */
void BinarySearchTree::erase(int data)
{
    // Find node to be removed
    TreeNode* to_be_removed = root;
    TreeNode* parent = NULL;
    bool found = false;
    while (!found && to_be_removed != NULL) // While it is not found
    {
        if (to_be_removed->data < data)
        {
        parent = to_be_removed;
        to_be_removed = to_be_removed->right;
        }
        else if (data < to_be_removed->data)
        {
        parent = to_be_removed;
        to_be_removed = to_be_removed->left;
        }
        else found = true;
    }
    
    if (!found) return;
    
    // to_be_removed contains data
    // If one of the children is empty, use the other
    if (to_be_removed->left == NULL || to_be_removed->right == NULL)
    {
        TreeNode* new_child;
        if (to_be_removed->left == NULL)
            new_child = to_be_removed->right;
        else
            new_child = to_be_removed->left;
        
        if (parent == NULL) // Found in root
            root = new_child;
        else if (parent->left == to_be_removed)
              parent->left = new_child;
        else
              parent->right = new_child;
           return;
    }
        
    // Neither subtree is empty
    // Find smallest element of the right subtree
        
    TreeNode* smallest_parent = to_be_removed;
    TreeNode* smallest = to_be_removed->right;
    while (smallest->left != NULL)
    {
        smallest_parent = smallest;
        smallest = smallest->left;
    }
        
    // smallest contains smallest child in right subtree
    // Move contents, unlink child
    
    to_be_removed->data = smallest->data;
    
    if (smallest_parent == to_be_removed)
        smallest_parent->right = smallest->right;
        
    else
        smallest_parent->left = smallest->right;
}

/**
Helper function for print()
 */
void TreeNode::print_nodes() const // This prints nodes from the right to the left
{
    if (right != NULL) // Start printing from the right
        right->print_nodes();
    std::cout << data << " ";
    if (left != NULL) // Once all the right most are printed, go towards the left
        left->print_nodes();
}

/**
Finds the smallest element in the tree
@return the smallest element
 */
int BinarySearchTree::smallest() const
{
    if (root != NULL) {return root->smallest_node();}
    else {return NULL;} // Return NULL if the tree is empty
}

/**
Helper function for smallest()
@return the smallest element
*/
int TreeNode::smallest_node() const // Helper funtion for smallest()
{
    if (left == NULL) // When we reach a leaf,
        return data; // return the data
    else
        return left->smallest_node(); // Call recursively down the left branch
}
