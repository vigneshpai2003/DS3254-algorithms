#pragma once

#include <stdexcept>

template <class T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *_head, *_tail;
    int _size;

public:
    LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

    ~LinkedList()
    {
        Node *current = _head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    int size() const
    {
        return _size;
    }

    void append(const T &value)
    {
        Node *new_node = new Node{value, nullptr};
        if (_head == nullptr)
        {
            _head = new_node;
            _tail = new_node;
        }
        else
        {
            _tail->next = new_node;
            _tail = new_node;
        }
        _size++;
    }

    void prepend(const T &value)
    {
        Node *new_node = new Node{value, _head};
        if (_head == nullptr)
        {
            _head = new_node;
            _tail = new_node;
        }
        else
        {
            _head = new_node;
        }
        _size++;
    }

    T removeFirst()
    {
        if (!_head)
            throw std::runtime_error("Nothing to remove.");

        T value = _head->data;
        Node *_new_head = _head->next;
        delete _head;
        _head = _new_head;

        if (!_head)
            _tail = nullptr;

        _size--;

        _size--;
        return value;
    }

    T removeLast()
    {
        if (!_head)
            throw std::runtime_error("Nothing to remove.");

        T value = _tail->data;

        Node *current = _head;
        while (current && current->next != _tail)
            current = current->next;

        delete _tail;
        _tail = current;
        return value;
    }

    void remove(const T &value)
    {
        if (!_head)
            return;
        if (_head->data == value)
            removeFirst();
        else
        {
            Node *current = _head;
            while (current->next && current->next->data != value)
                current = current->next;

            if (current->next)
            {
                Node *toDelete = current->next;
                current->next = toDelete->next;
                if (toDelete == _tail)
                    _tail = current;
                delete toDelete;
                _size--;
            }
        }
    }
};