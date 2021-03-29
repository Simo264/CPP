#include <iostream>
using namespace std;

struct Queue
{   
    int* vector = nullptr;
    int size = 0;
    int front = -1;
    int rear = -1;
};

void Init(Queue& q, int size)
{
    if(q.vector != nullptr)
        delete[] q.vector;
    
    q.vector = new int[size];
    q.size = size;
    q.front = -1;
    q.rear = -1;
}

void Enqueue(Queue& q, int val)
{
    if((q.rear + 1) % q.size == q.front)
        cout << "Queue full!\n";

    else if(q.front == -1 && q.rear == -1)
    {
        q.front = 0;
        q.rear = 0;
        q.vector[0] = val;
        cout << "Insert in first posizion [0]\n";
    }
    else
    {
        q.rear = (q.rear + 1) % q.size;
        q.vector[q.rear] = val;
        cout << "Insert in posizion " << q.rear << endl; 
    }

}

int Dequeue(Queue& q)
{
    if(q.front == - 1 && q.rear == -1)
    {
        cout << "Queue is empty!\n";
        return 0;
    }
    else
    {
        int val = q.vector[q.front];
        q.vector[q.front] = 0;
        
        if(q.front == q.rear)
        {   
            cout << "Dequeue last element! Front = -1;\n";
            q.front = -1;
            q.rear = -1;
        }
        else
        {
            cout << "Deueue element at posizion " << q.front << endl;
            q.front = (q.front + 1) % q.size;
        }
            
        
        return val;
    }
}

void Display(Queue& q)
{
    cout << endl;
    for(int i = q.front, j = 0; i != q.rear;)
    {
        i = (q.front + j++) % q.size;
        cout << q.vector[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue queue;
    Init(queue, 5);

    Enqueue(queue, 5);
    Enqueue(queue, 7);      
    Enqueue(queue, 10);
    Enqueue(queue, 21);
    Enqueue(queue, 99);

    Display(queue);
    
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    Enqueue(queue, 1);

    Display(queue);


    return 0;
}
