//
// Created by apple on 2/24/21.
//
#include <iostream>
#ifndef VECTORITERATOR_VECTOR_H
#define VECTORITERATOR_VECTOR_H

class Vector {
public:
    Vector();
    Vector(int elements, int value = 0);
    Vector(const Vector& other);
    Vector(const std::initializer_list<int>& list);

    ~Vector();
    int* Begin() const;
    int* End() const;
    void pushBack(int val);
    void pop();
    int getIndex(int element);
    void clear();
    int& operator[](int index);
    void remove(int index);
    void insert(int i, int val);
    bool empty() const;
    int getSize() const;
    int getCapacity() const;
    void print();
    Vector& operator =(const Vector& other);
    class Iterator : std::iterator<std::bidirectional_iterator_tag, int> {
    public:
        Iterator() : object_(nullptr) {
        }

        explicit Iterator(int* value) : object_(value) {
        }

        int* operator->() {
          return object_;
        }

        Iterator& operator--(int) {
          object_--;
          return *this;
        }

        Iterator& operator++(int) {
          object_++;
          return *this;
        }

        Iterator& operator++() {
          ++object_;
          return *this;
        }



        Iterator& operator--() {
          --object_;
          return *this;
        }

        int& operator*() {
          return *object_;
        }

        int operator*() const {
          return *object_;
        }

        bool operator==(const Iterator& rhs) const {
          return object_ == rhs.object_;
        }

        bool operator!=(const Iterator& rhs) const {
          return object_ != rhs.object_;
        }

        Iterator& operator+=(const Iterator& rhs) {
          *object_ += *rhs.object_;
          return *this;
        }
        Iterator& operator-=(const Iterator& rhs) {
          *object_ -= *rhs.object_;
          return *this;
        }


        friend Iterator operator+(Iterator lhs, const Iterator& rhs) {
          lhs += rhs;
          return lhs;
        }

        friend Iterator operator+(Iterator lhs, const int rhs) {
          lhs.object_ += rhs;
          return lhs;
        }

        friend Iterator operator-(Iterator lhs, const int rhs) {
          lhs.object_ -= rhs;
          return lhs;
        }

        friend Iterator operator-(Iterator lhs, const Iterator& rhs) {
          lhs -= rhs;
          return lhs;
        }

        friend bool operator<(const Iterator& lhs, const Iterator& rhs) {
          return *lhs.object_ < *rhs.object_;
        }

        friend bool operator>(const Iterator& lhs, const Iterator& rhs) {
          return *lhs.object_ > *rhs.object_;
        }

        friend bool operator<=(const Iterator& lhs, const Iterator& rhs) {
          return *lhs.object_ <= *rhs.object_;
        }
        friend bool operator>=(const Iterator& lhs, const Iterator& rhs) {
          return *lhs.object_ >= *rhs.object_;
        }


    private:
        int *object_;
    };

    Iterator begin();
    Iterator end();



private:
    int* arr;
    int capacity;
    int size;
};



#endif //VECTORITERATOR_VECTOR_H
