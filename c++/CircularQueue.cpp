#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <conio.h>
#include <queue>
typedef long long ll;
using namespace std;
int main()
{
    getch();
}
class MyCircularQueue
{
    vector<int> q;
    int front;
    int rear;

public:
    MyCircularQueue(int k)
    {
        q.resize(k);
        front = -1;
        rear = -1;
    }

    bool enQueue(int value)
    {

        if (!isFull())
        {
            if (front == -1 && rear == -1)
            {
                front = rear = 0;
                q[rear] = value;
                return true;
            }
            rear = (rear + 1) % q.size();
            q[rear] = value;
            return true;
        }
        return false;
    }

    bool deQueue()
    {

        if (!isEmpty())
        {
            if (front == rear)
            {
                front = -1;
                rear = -1;
                return true;
            }
            front = (front + 1) % q.size();
            return true;
        }
        return false;
    }

    int Front()
    {
        if (front == -1)
            return -1;
        return q[front];
    }

    int Rear()
    {
        if (rear == -1)
            return -1;
        return q[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (rear == front - 1 || (rear == q.size() - 1 && front == 0))
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */