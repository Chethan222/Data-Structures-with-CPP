#include <iostream>

// Creating structure Stack
struct Stack
{
    int head = -1;
    int max_size = 0;
    int *stack = NULL;
    Stack(int max_size)
    {
        this->max_size = max_size;
        this->stack = (int *)malloc(sizeof(int) * max_size);
    }
};

// Function to add node
void push(Stack *stack, int data)
{
    if (stack->head == stack->max_size - 1)
    {
        std::cout << "Stack overflow!" << std::endl;
        return;
    }
    stack->head += 1;
    stack->stack[stack->head] = data;
}

void print(Stack *stack)
{
    std::cout << "Elements in the stack are :" << std::endl;
    for (int i = stack->head; i >= 0; i--)
    {
        std::cout << stack->stack[i] << std::endl;
    }
}

int pop(Stack *stack)
{
    int data = -1;
    // Checking the queue is empty or not
    if (stack->head == -1)
    {
        std::cout << "Stack underflow!" << std::endl;
        return data;
    }

    data = stack->stack[stack->head];
    stack->head -= 1;

    return data;
}

int is_empty(Stack *stack)
{
    return stack->head == -1;
}

int stack_top(Stack *stack)
{
    if (is_empty(stack))
    {
        return -1;
    }
    return stack->stack[stack->head];
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