#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *create_node(int data)
{
    Node *node = (struct Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
}
Node *delete_node(Node *head)
{
    int data = 0;
    Node *temp_node = head;
    head = temp_node->next;
    free(temp_node);
    return head;
}
int main()
{
    Node *first_node = create_node(1);
    Node *second_node = create_node(2);
    Node *third_node = create_node(3);

    first_node->next = second_node;
    second_node->next = third_node;
    first_node = delete_node(first_node);
    print_list(first_node);

    return 0;
}