#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *create_node(int data)
{
    Node *node;
    node = (Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void preorder_traversal(Node *root_node)
{
    if (root_node != NULL)
    {
        std::cout << root_node->data << " ";
        preorder_traversal(root_node->left);
        preorder_traversal(root_node->right);
    }
}
void postorder_traversal(Node *root_node)
{
    if (root_node != NULL)
    {
        postorder_traversal(root_node->left);
        postorder_traversal(root_node->right);
        std::cout << root_node->data << " ";
    }
}
void inorder_traversal(Node *root_node)
{
    if (root_node != NULL)
    {
        inorder_traversal(root_node->left);
        std::cout << root_node->data << " ";
        inorder_traversal(root_node->right);
    }
}
int is_bst(Node *root_node)
{
    static Node *pre = NULL;
    if (root_node != NULL)
    {
        // For left sub-tree
        if (!is_bst(root_node->left))
        {
            return 0;
        }

        // For data left<root<right
        if (pre != NULL && root_node->data <= pre->data)
        {
            return 0;
        }

        pre = root_node;

        // For right sub-tree
        return is_bst(root_node->right);
    }
    return 1;
}

int main()
{
    Node *root_node = create_node(5);
    Node *p1 = create_node(3);
    Node *p2 = create_node(6);
    Node *p3 = create_node(1);
    Node *p4 = create_node(4);

    root_node->left = p1;
    root_node->right = p2;
    p1->left = p3;
    p1->right = p4;

    /*       5
            / \
           3   6
          / \
         1   4     */
    std::cout << is_bst(root_node) << std::endl;
    inorder_traversal(root_node);

    return 0;
}
