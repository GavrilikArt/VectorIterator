//
// Created by apple on 11/22/20.
//
#include <iostream>
#include "Vector.h"
#include <iterator>

Vector::Vector()
{
  this->size = 0;
  this->capacity = 5;
  this->arr = new int[capacity];
}

int* Vector::End() const {
  return arr + size;
}

int* Vector::Begin() const {
  return arr;
}

Vector::Vector(const Vector& other)
        :size(other.size),
         capacity(other.capacity),
         arr(new int[capacity])
{
  for (int i = 0; i < other.getSize(); ++i) {
    arr[i] = other.arr[i];
  }
}

Vector::Vector(const std::initializer_list<int>& list)
        :size(0),
         capacity(list.size()*2),
         arr(new int[capacity])
{
  for(int i : list) {
    pushBack(i);
  }
}

Vector::Vector(int elements, int value)
        :size(elements),
         capacity(elements*2),
         arr(new int[capacity])
{
  for (int i = 0; i < size; ++i) {
    arr[i] = value;
  }
}

Vector::~Vector() {
  delete [] arr;
}

void Vector::pushBack(int val) {
  if (size < capacity) {
    arr[size] = val;
    ++size;
  }
  else {
    capacity *= 2;
    int* extendedArr = new int[capacity];
    for (int i = 0; i < size; ++i) {
      extendedArr[i] = arr[i];
    }
    extendedArr[size] = val;
    ++size;
    delete[] arr;
    arr = extendedArr;
  }
}

void Vector::pop() {
  if (size == 0) {
    throw std::exception();
  }
  --size;
}

void Vector::insert(int index, int val) {
  if (index < 0 || index >= size) {
    throw std::exception();
  }
  if (index != capacity) {
    for (int i = size - 1; i >= index; --i) {
      arr[i+1] = arr[i];
    }
    arr[index] = val;
    ++size;
  }
  else {
    capacity *= 2;
    int* extendedArr = new int[capacity];
    for (int i = 0; i < size; ++i) {
      extendedArr[i] = arr[i];
    }
    extendedArr[size] = val;
    ++size;
    delete[] arr;
    arr = extendedArr;
    insert(index, val);
  }
}

void Vector::remove(int index) {
  if (index < 0 || index >= size) {
    throw std::exception();
  }
  for (int i = index; i < size - 1; ++i) {
    arr[i] = arr[i + 1];
  }
  --size;
}

void Vector::clear() {
  size = 0;
}

int Vector::getIndex(int element) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == element) {
      return i;
    }
  }
  return -1;
}


int Vector::getSize() const {
  return size;
}

int Vector::getCapacity() const {
  return capacity;
}

bool Vector::empty() const {
  return size == 0;
}

void Vector::print() {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout<<std::endl;
}

Vector& Vector::operator=(const Vector& other) {
  if (other.size > size) {
    delete[] arr;
    capacity *= 2;
    arr = new int[capacity];
  }
  for (int i = 0; i < other.getSize(); ++i) {
    arr[i] = other.arr[i];
  }
  size = other.size;
  return  *this;
}

int& Vector::operator[](int index)
{
  if (index >= size) {
    std::cout << "Array index out of bound, exiting";
    exit(0);
  }
  return arr[index];
}



Vector::Iterator Vector::begin() {
  return Iterator(arr);
}

Vector::Iterator Vector::end() {
  return Iterator(arr + size);
}

