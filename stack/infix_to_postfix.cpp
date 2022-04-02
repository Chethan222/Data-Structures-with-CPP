#include <iostream>
#include <cstring>

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
int is_operator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
    {
        return 1;
    }
    return 0;
}
int precedence(char symbol)
{
    if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

char *infix_to_postfix(char *infix_exp)
{
    int n = strlen(infix_exp);
    char *postfix_exp = (char *)malloc((n + 1) * sizeof(char));

    int i = 0; // For iterating over each character of infix exp
    int j = 0; // For iterating variable postfix addition

    Stack stack(n);

    while (infix_exp[i] != '\0')
    {
        // If current character is not a operator
        if (!is_operator(infix_exp[i]))
        {
            postfix_exp[j] = infix_exp[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix_exp[i]) > precedence(stack_top(&stack)))
            {
                push(&stack, infix_exp[i]);
                i++;
            }
            else
            {
                // Append to postfix exp
                postfix_exp[j] = pop(&stack);
                j++;
            }
        }
    }
    // Appending remaining symbols from the stack
    while (!is_empty(&stack))
    {
        postfix_exp[j] = (char)pop(&stack);
        j++;
    }
    postfix_exp[j] = '\0';

    return postfix_exp;
}

int main()
{
    std::string str = "x-y/z-r*d";
    std::cout << infix_to_postfix(&str[0]);
    return 0;
}