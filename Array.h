//
// Created by user.v2.0 on 13.12.2020.
//
#pragma once
#ifndef PAYMENT_ARRAY_H
#define PAYMENT_ARRAY_H

#include <ostream>

template<typename T>
class Array {
private:
    int length;
    T *array;

    void make_bigger();

public:
    Array();

    Array(T *array, int length);

    ~Array();

    void push_back(T &new_element);

    int get_length();

    T &operator[](int index);
   // friend std::ostream &operator<<(std::ostream &os, const Array<T> &array);
};

template<typename T>
Array<T>::Array() {
    array = nullptr;
    length = 0;
}

template<typename T>
Array<T>::Array(T *array, int length) {
    this->array = array;
    this->length = length;
}

template<typename T>
Array<T>::~Array() {
    delete[] array;
}

template<typename T>
void Array<T>::push_back(T &new_element) {
    make_bigger();
    *(array+length-1) = new_element;
}

template<typename T>
int Array<T>::get_length() {
    return length;
}

template<typename T>
T &Array<T>::operator[](int index) {
    if (index < 0 || index >= length)
        throw std::out_of_range("index in Array out of range\n");
    return *(array + index);
}

template<typename T>
void Array<T>::make_bigger() {
    T *new_array = new T[length + 1];
    for (int i = 0; i < length; ++i) {
        *(new_array + i) = *(array + i);
    }
    length++;
    array = new_array;
}


//template<typename T>
//std::ostream &operator<<(std::ostream &os, const Array<T> &array) {
//    os << "length: " << array.length << " array: " << array.array;
//    return os;
//}

#endif //PAYMENT_ARRAY_H
