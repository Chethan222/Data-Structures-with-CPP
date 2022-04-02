#include <iostream>

// Node for a stack
struct Node
{
    int data;
    Node *next = NULL;
};
struct Stack
{
    Node *head = NULL;
    int max_size = 0;
    int cur_size = 0;

    Stack(int size)
    {
        this->max_size = size;
    }
};
int is_full(Stack *stack)
{
    return stack->cur_size == stack->max_size;
}
int is_empty(Stack *stack)
{
    return stack->head == NULL;
}

int stack_top(Stack *stack)
{
    if (is_empty(stack))
    {
        return -1;
    }
    return stack->head->data;
}

void print(Stack *stack)
{
    if (is_empty(stack))
    {
        std::cout << "Stack underflow!" << std::endl;
        return;
    }

    Node *head = stack->head;
    std::cout << "Elements are :" << std::endl;
    while (head != NULL)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
// Function to add node

void push(Stack *stack, int data)
{
    if (is_full(stack))
    {
        std::cout << "Stack overflow!" << std::endl;
        return;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->cur_size += 1;
}

int pop(Stack *stack)
{
    int data = -1;
    // Checking the queue is empty or not
    if (is_empty(stack))
    {
        return data;
    }

    Node *temp = (Node *)malloc(sizeof(Node));

    temp = stack->head;
    data = temp->data;
    stack->head = stack->head->next;
    free(temp);

    return data;
}

int main()
{
    Stack stack(2);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    print(&stack);
    std::cout << "Popped element is " << pop(&stack) << std::endl;
    std::cout << "Popped element is " << pop(&stack) << std::endl;
    std::cout << "Popped element is " << pop(&stack) << std::endl;
    return 0;
}