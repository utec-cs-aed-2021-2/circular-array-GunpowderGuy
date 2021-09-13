#include <iostream>

#include <cmath>

using namespace std;

template <class T> class CircularArray {
  T *array;
  int capacity;
  int back = 0;
  int front = 0;

  int next(int);
  int prev(int);

public:
  CircularArray();
  CircularArray(int _capacity);
  virtual ~CircularArray();
  string to_string(string sep = " ");

  void push_front(T data) {
    this->front = (this->front + this->size() - 1) % this->size();
    this[front] = data;
  }

  void push_back(T data) {
    this[back] = data;
    // dividir y modulo de zero son no definidos
    this->back = this->size() ? ((this->back + 1) % this->size()) + front
                              : (this->back + 1) + front;
  }

  void insert(T data, int pos);

  T pop_front() {
    this->front = (this->front + 1) % this->size();
    return T();
  }

  T pop_back() {
    this->back = (this->back + this->size() - 1) % this->size();
    return T();
  }

  bool is_full() { return abs(this->back - this->front) == 1; }

  bool is_empty() {
    // return this->back == this->front;
    return true;
  }

  int size() { return abs(front - back); } // tambien conocido como n

  void clear(); // buscar que hace

  T &operator[](int i) {
    const auto n = this->size();
    const auto index = front + i;

    return array[index % n];
  }

  void sort() {}
  bool is_sorted() { return false; }
  void reverse() {}
};

template <class T> CircularArray<T>::CircularArray() { CircularArray(0); }

template <class T> CircularArray<T>::CircularArray(int _capacity) {
  this->array = new T[_capacity];
  this->capacity = _capacity;
  this->front = this->capacity / 3;
  this->back = this->capacity / 2;
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
  for (int i = 0; i < size(); i++) {
    result += std::to_string((*this)[i]) + sep;
  }
  return result;
}
