#include <iostream>

// Node for a stack
struct Node
{
    int data;
    struct Node *next = NULL;
};
struct Stack
{
    struct Node *head = NULL;
    int max_size = 0;
    int cur_size = 0;

    Stack(int size)
    {
        this->max_size = size;
    }
};

// Function to add node
void push(Stack *stack, int data)
{
    if (stack->cur_size == stack->max_size)
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
    if (stack->head == NULL)
    {
        std::cout << "Stack underflow!" << std::endl;
        return data;
    }

    Node *temp = (Node *)malloc(sizeof(Node));

    temp = stack->head;
    data = temp->data;
    stack->head = stack->head->next;
    free(temp);

    return data;
}
int is_anti_char(char char1, char char2)
{
    if (char1 == '{' && char2 == '}')
    {
        return 1;
    }
    else if (char1 == '[' && char2 == ']')
    {
        return 1;
    }
    else if (char1 == '(' && char2 == ')')
    {
        return 1;
    }
    return 0;
}
int pattern_match(std::string str)
{
    int str_len = str.length();
    Stack stack(str_len);

    for (int i = 0; i < str_len; i++)
    {

        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            push(&stack, str[i]);
        }
        else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            if (!is_anti_char(pop(&stack), str[i]))
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    std::string str;
    std::cout << "Enter a string pattern :" << std::endl;
    std::cin >> str;
    std::cout << !!pattern_match(str);
    return 0;
}