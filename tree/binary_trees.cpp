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

int main()
{
    Node *root_node = create_node(4);
    Node *p1 = create_node(1);
    Node *p2 = create_node(6);
    Node *p3 = create_node(5);
    Node *p4 = create_node(2);

    root_node->left = p1;
    root_node->right = p2;
    p1->left = p3;
    p1->right = p4;

    /*        4
             / \
            1   6
           / \
          5   2     */
    std::cout << "Pre order traversal : " << std::endl;
    preorder_traversal(root_node);
    std::cout << "\nPost order traversal : " << std::endl;
    postorder_traversal(root_node);
    std::cout << "\nIn order traversal : " << std::endl;
    inorder_traversal(root_node);

    return 0;
}
