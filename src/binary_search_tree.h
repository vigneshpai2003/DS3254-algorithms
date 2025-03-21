#pragma once

class BinarySearchTree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node *parent;
    };
    Node *root;

    Node *get_min(Node *start)
    {
        Node *current = start;
        while (current)
        {
            current = current->left;
        }
        return current;
    }

public:
    BinarySearchTree() : root(nullptr) {};

    bool search(int data)
    {
        Node *current = root;

        while (current != nullptr)
        {
            if (data == current->data)
                return true;
            else if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        return false;
    }

    void insert(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr;

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (true)
        {
            if (data < current->data)
                if (current->left == nullptr)
                {
                    current->left = newNode;
                    newNode->parent = current;
                    return;
                }
                else
                    current = current->left;
            else if (current->right == nullptr)
            {
                current->right = newNode;
                newNode->parent = current;
                return;
            }
            else
                current = current->right;
        }
    }

    void transplant(Node *u, Node *v)
    {
        if (u == root)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;

        if (v != nullptr)
            v->parent = u->parent;
    }

    void remove(int data)
    {
        Node *current = root;

        while (current && data != current->data)
        {
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (!current)
            return;

        if (!(current->left))
            transplant(current, current->right);
        else if (!(current->right))
            transplant(current, current->left);
        else
        {
            Node *replacement = get_min(current->right);

            if (replacement->parent != current) {
                transplant(replacement, replacement->right);
                replacement->right = current->right;
                replacement->right->parent = replacement;
            }
            transplant(current, replacement);
            replacement->left = current->left;
            replacement->left->parent = replacement;
        }
    }
};