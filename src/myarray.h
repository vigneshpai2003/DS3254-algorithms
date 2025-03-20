class MyArray
{
private:
    int *_arr;
    int _capacity, _size;

public:
    MyArray(int capacity) : _capacity(capacity), _size(0)
    {
        _arr = new int[capacity];
    }

    ~MyArray() {
        delete[] _arr;
    }

    int length() {
        return _size;
    }

    int elementAt(int i) {
        return _arr[i];
    }

    void replace(int i, int x) {
        _arr[i] = x;
    }

    void append(int x){
        _arr[_size] = x;
        _size++;
    }

    int pop() {
        _size--;
        return _arr[_size];
    }

    void insert(int i, int x) {
        for (int j = _size; j > i; j--) {
            _arr[j] = _arr[j - 1];
        }
        _arr[i] = x;
        _size++;
    }

    void remove(int i) {
        _size--;
        for (int j = i; j < _size; j++) {
            _arr[j] = _arr[j + 1];
        }
    }
};