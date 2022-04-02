#include <iostream>

// Queue Structure
struct Queue
{
    int size;
    int *queue;
    int front = -1;
    int rear = -1;

    // Function to initialize queue
    Queue(int size)
    {
        this->size = size;
        this->queue = (int *)malloc(size * sizeof(int));
    }
};
int is_full(Queue *queue)
{
    return queue->size - 1 == queue->rear;
}
int is_empty(Queue *queue)
{
    return queue->front == queue->rear;
}
void enque(Queue *queue, int value)
{
    if (is_full(queue))
    {
        std::cout << "Queue is full!" << std::endl;
        return;
    }
    queue->rear++;
    queue->queue[queue->rear] = value;
}

void display_queue(Queue *queue)
{
    if (is_empty(queue))
    {
        std::cout << "Queue is empty!" << std::endl;
    }
    for (int i = 0; i <= queue->rear; i++)
    {
        std::cout << queue->queue[i] << " ";
    }
}
int dequeue(Queue *queue)
{
    if (is_empty(queue))
    {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }
    queue->front++;
    return queue->queue[queue->front];
}

int main()
{
    // Creating queue
    Queue queue(2);
    enque(&queue, 1);
    enque(&queue, 2);
    std::cout << dequeue(&queue) << std::endl;
    std::cout << dequeue(&queue) << std::endl;
    std::cout << dequeue(&queue) << std::endl;
    return 0;
}