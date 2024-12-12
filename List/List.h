#pragma once
#include <exception>
#include <stdexcept>

template <typename T>
class List
{
private:
    struct Node
    {
        Node(T value) noexcept
        {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
        T value;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    size_t length; 

public:
    List() noexcept
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~List()
    {
        while (head != nullptr)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

  
    size_t size() const noexcept
    {
        return length;
    }

  
    void pushFront(T value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;

        length++; 
    }

 
    void pushBack(T value)
    {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        if (tail != nullptr)
            tail->next = newNode;
        else
            head = newNode;
        tail = newNode;

        length++;
    }
};
