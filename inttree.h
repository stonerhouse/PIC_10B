/*
    PIC 10B Homework 7, inttree.h
    Author: Will Stonehouse
    Date: 05/05/20
*/

#ifndef INTTREE_H
#define INTTREE_H

class TreeNode
{
public:
    void insert_node(TreeNode* new_node);
    void print_nodes() const;
    int count_dup(int value, int counter) const;
    int smallest_node() const;
private:
    int data;
    TreeNode* left;
    TreeNode* right;
friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
    BinarySearchTree();
    void insert(int data);
    void erase(int data);
    int count(int data) const;
    void print() const;
    int smallest() const;
private:
    TreeNode* root;
};

#endif
