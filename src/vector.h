template <class T>
class Vector
{
private:
    int *_arr;
    int _capacity, _size;

    void revise_capacity(int new_capacity)
    {
        int *_new_arr = new int[new_capacity];
        for (int i = 0; i < _size; i++)
            _new_arr[i] = _arr[i];
        delete[] _arr;
        _arr = _new_arr;
        _capacity = new_capacity;
    }

public:
    Vector(int capacity) : _capacity(capacity), _size(0)
    {
        _arr = new int[capacity];
    }

    ~Vector()
    {
        delete[] _arr;
    }

    int length()
    {
        return _size;
    }

    int elementAt(int i)
    {
        return _arr[i];
    }

    void replace(int i, int x)
    {
        _arr[i] = x;
    }

    void append(int x)
    {
        if (_size == _capacity)
            revise_capacity(2 * _capacity);
        _arr[_size] = x;
        _size++;
    }

    int pop()
    {
        _size--;
        if (_size == _capacity / 4)
            revise_capacity(_capacity / 2);
        return _arr[_size];
    }

    void insert(int i, int x)
    {
        for (int j = _size; j > i; j--)
        {
            _arr[j] = _arr[j - 1];
        }
        _arr[i] = x;
        _size++;
    }

    void remove(int i)
    {
        _size--;
        for (int j = i; j < _size; j++)
        {
            _arr[j] = _arr[j + 1];
        }
    }
};