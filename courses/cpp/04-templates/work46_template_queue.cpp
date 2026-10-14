#include <iostream>
using namespace std;

template <typename T> class MyQueue; // 前置声明
template <typename T> ostream &operator<<(ostream &, const MyQueue<T> &);

template <typename T>
class QueueItem
{
public:
    QueueItem(const T &t) : item(t), next(0) {}
private:
    T item;
    QueueItem *next;
    friend class MyQueue<T>;
    friend ostream &operator<<<T>(ostream &os, const MyQueue<T> &q);
};

template <typename T>
class MyQueue
{
public:
    MyQueue() : head(0), tail(0) {}
    MyQueue(const MyQueue &Q) : head(0), tail(0) { CopyElements(Q); }
    ~MyQueue() { Destroy(); }
    MyQueue &operator=(const MyQueue &);

    T &Front() { return head->item; }
    const T &Front() const { return head->item; }
    void Push(const T &);
    void Pop();
    bool Empty() const { return head == 0; }
    void Display() const;

private:
    QueueItem<T> *head;
    QueueItem<T> *tail;
    void Destroy();
    void CopyElements(const MyQueue &);
    friend ostream &operator<<<T>(ostream &os, const MyQueue<T> &q);
};

// 成员函数实现

template <typename T>
void MyQueue<T>::Push(const T &val)
{
    QueueItem<T> *p = new QueueItem<T>(val);
    if (Empty())
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}

template <typename T>
void MyQueue<T>::Pop()
{
    if (!Empty())
    {
        QueueItem<T> *p = head;
        head = head->next;
        delete p;
        if (head == 0)
            tail = 0;
    }
}

template <typename T>
void MyQueue<T>::Display() const
{
    for (QueueItem<T> *p = head; p; p = p->next)
        cout << p->item << " ";
}

template <typename T>
void MyQueue<T>::Destroy()
{
    while (!Empty())
        Pop();
}

template <typename T>
void MyQueue<T>::CopyElements(const MyQueue &Q)
{
    for (QueueItem<T> *p = Q.head; p; p = p->next)
        Push(p->item);
}

template <typename T>
MyQueue<T> &MyQueue<T>::operator=(const MyQueue &Q)
{
    if (this != &Q)
    {
        Destroy();
        CopyElements(Q);
    }
    return *this;
}

template <typename T>
ostream &operator<<(ostream &os, const MyQueue<T> &q)
{
    os << "< ";
    for (QueueItem<T> *p = q.head; p; p = p->next)
        os << p->item << " ";
    os << ">";
    return os;
}

int main()
{
    MyQueue<int> qi;
    qi.Push(1);
    qi.Push(2);
    qi.Push(3);
    qi.Push(4);
    qi.Push(5);
    qi.Pop();
    qi.Display();
    cout << "\n";
    cout << qi;
    cout << endl;

    MyQueue<int> qi2(qi);
    qi2.Display();
    cout << endl;

    MyQueue<int> qi3;
    qi3 = qi;
    cout << qi3;

    return 0;
}