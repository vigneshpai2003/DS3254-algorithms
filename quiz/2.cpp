#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#define uint unsigned int

template <class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
};

template <class T>
class BinaryTree
{
public:
    Node<T> *root;

    BinaryTree(T *preorder_nodes, T *inorder_nodes, int n)
    {
        root = build(preorder_nodes, inorder_nodes, n);
    }

    Node<T> *build(T *preorder_nodes, T *inorder_nodes, int n)
    {
        if (n == 0)
            return nullptr;

        Node<T> *node = new Node<T>;
        node->data = preorder_nodes[0];

        int i = 0;
        while (inorder_nodes[i] != preorder_nodes[0]) {
            i++;
            if (i == n)
                throw std::runtime_error("error");
        }

        node->left = build(preorder_nodes + 1, inorder_nodes, i);
        node->right = build(preorder_nodes + i + 1, inorder_nodes + i + 1, n - i - 1);

        return node;
    }

    // Left Right Root
    void postorder(Node<T> *node, std::vector<T>& out)
    {
        if (node == nullptr)
            return;

        postorder(node->left, out);
        postorder(node->right, out);

        out.push_back(node->data);
    }
};

int main(int argsn, char** args) {
    char* infile = args[1];
    char* outfile = args[2];

    std::ifstream file;

    file.open(infile);

    std::string line1, line2;
    getline(file, line1);
    getline(file, line2);

    file.close();

    std::stringstream line1ss(line1);
    std::stringstream line2ss(line2);

    int val;

    std::vector<int> preorder, inorder;

    while (line1ss >> val)
        preorder.push_back(val);

    while (line2ss >> val)
        inorder.push_back(val);

    int n = preorder.size();

    int * preorder_arr = new int[n];
    int * inorder_arr = new int[n];

    for (int i = 0; i < n; i++) {
        preorder_arr[i] = preorder[i];
        inorder_arr[i] = inorder[i];
    }

    try {
        BinaryTree<int> tree(preorder_arr, inorder_arr, n);
       
        std::vector<int> output_arr;
        
        tree.postorder(tree.root, output_arr);

        std::ofstream out;

        out.open(outfile);

        for (int i = 0; i < n; i++)
            out << output_arr[i] << " ";

        out.close();

        delete[] preorder_arr;
        delete[] inorder_arr;

    } catch (std::runtime_error err) {
        std::ofstream out;

        out.open(outfile);

        out << "None";
        out.close();
    }
    return 0;
}
