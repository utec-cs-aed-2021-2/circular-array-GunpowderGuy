#include <iostream>

#include <cmath>

using namespace std;

template <class T> class CircularArray {
  T *array;
  int capacity;
  int back = 0;
  int front = 0;
  int elementos() { return front - back; }; // tambien conocido como n

  int next(int);
  int prev(int);

public:
  CircularArray();
  CircularArray(int _capacity);
  virtual ~CircularArray();
  string to_string(string sep = " ");

  void push_front(T data) {
    this->front = (this->front + this->elementos() - 1) % this->elementos();
    this[front] = data;
  }

  void push_back(T data) {
    this->back = (this->back + 1) % this->elementos();
    this[front] = data;
  }

  void insert(T data, int pos);

  T pop_front() {

    this->front = (this->front + 1) % this->elementos();

    return T();
    
  }

  T pop_back() {
    this->back = (this->back + this->elementos() - 1) % this->elementos();
    return T();
  }

  bool is_full() { return abs(this->back - this->front) == 1; }

  bool is_empty() { return this->back == this->front; }

  int size() { return this->elementos(); }

  void clear(); // buscar que hace

  T &operator[](int i) {
    const auto n = this->elementos();
    const auto index = front + i;

    return array[index % n];
  }

  void sort();
  bool is_sorted();
  void reverse();
};

template <class T> CircularArray<T>::CircularArray() { CircularArray(0); }

template <class T> CircularArray<T>::CircularArray(int _capacity) {
  this->array = new T[_capacity];
  this->capacity = _capacity;
  this->front = this->back = -1;
}

template <class T> CircularArray<T>::~CircularArray() { delete[] array; }

template <class T> int CircularArray<T>::prev(int index) {
  return (index == 0) ? capacity - 1 : index - 1;
}

template <class T> int CircularArray<T>::next(int index) {
  return (index + 1) % capacity;
}

template <class T> string CircularArray<T>::to_string(string sep) {
  string result = "";
  for (int i = 0; i < size(); i++)
    result += std::to_string((*this)[i]) + sep;
  return result;
}
