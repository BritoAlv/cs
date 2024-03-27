#include <iostream>
namespace Seminario
{
using std::cout;
template <typename T> class DLL
{
  public:
    unsigned long long len;
    DLL()
    {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    DLL<T> operator+(const DLL<T> &other)
    {
        DLL<T> new_dll;
        Node *current = head;
        while (current != nullptr)
        {
            new_dll.pb(current->val);
            current = current->next;
        }
        current = other.head;
        while (current != nullptr)
        {
            new_dll.pb(current->val);
            current = current->next;
        }
        return new_dll;
    }
    const void watchDebug()
    {
        cout << "START" << '\n';
        Node *current = head;
        while (current != nullptr)
        {
            current->watch();
            current = current->next;
        }
        cout << "END" << '\n';
    }
    void pb(const T &val)
    {
        Node *A = new Node(); // goes to heap. but should I use smart_ptr<>.
        A->val = val;
        A->next = nullptr;
        if (head == nullptr)
        {
            A->prev = nullptr;
            head = A;
            tail = A;
        }
        else
        {
            Node *current = tail;
            current->next = A;
            A->prev = current;
            tail = A;
        }
        len++;
    }
    // this assumes T's can be compared.
    void rm(const T &val)
    {
        Node *current = head;
        while (current != nullptr && current->val != val)
        {
            current = current->next;
        }
        if (current != nullptr)
        {
            Node *before = current->prev;
            Node *next = current->next;
            if (before == nullptr)
            {
                head = next;
                if (next != nullptr)
                {
                    next->prev = nullptr;
                }
                else
                {
                    // linked list with only one element
                    // and have to delete precisely it.
                    tail = nullptr;
                }
            }
            else
            {
                before->next = next;
                if (next != nullptr)
                {
                    next->prev = before;
                }
                else
                {
                    tail = before;
                }
            }
            len--;
        }
    }
    friend std::ostream &operator<<(std::ostream &os, DLL<T> &dll)
    {
        Node *current = dll.head;
        while (current != nullptr)
        {
            os << current->val << ' ';
            current = current->next;
        }
        os << '\n';
        return os;
    }

  private:
    class Node
    {
      public:
        Node(){

        };
        void watchDebug()
        {
            cout << "Val is: " << ' ' << val << '\n';
            cout << "Prev is: " << ' ';
            if (prev == nullptr)
            {
                cout << "NULL";
            }
            else
            {
                cout << prev->val;
            }
            cout << '\n';
            cout << "Next is: " << ' ';
            if (next == nullptr)
            {
                cout << "NULL";
            }
            else
            {
                cout << next->val;
            }
            cout << '\n';
        }
        T val;
        Node *next;
        Node *prev;
    };

  private:
    Node *head;
    Node *tail;
};
} // namespace Seminario