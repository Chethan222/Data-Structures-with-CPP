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
void enqueue(Queue *queue, int value)
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

void print(int arr[])
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    // Creating queue
    Queue queue(7);

    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    // Starting node
    int i = 0;

    // Creating graph as Adjacency Matrix
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    visited[i] = 1;
    std::cout << i << " ";
    enqueue(&queue, i);

    while (!is_empty(&queue))
    {
        // getting current node
        int node = dequeue(&queue);

        for (int j = 0; j < 7; j++)
        {
            // Checking for the connection and enqueuing it for the traversal
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                std::cout << j << " ";

                // Marking as visited
                visited[j] = 1;

                // Adding to queue for exploration
                enqueue(&queue, j);
            }
        }
    }

    return 0;
}