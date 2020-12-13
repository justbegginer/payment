//
// Created by user.v2.0 on 13.12.2020.
//
#pragma once
#ifndef PAYMENT_ARRAY_H
#define PAYMENT_ARRAY_H

template<typename T>
class Array {
private:
    int length;
    T *array;
    void make_bigger();
public:
    Array();
    Array(T *array , int length);
    ~Array();
    void push_back(T new_element);
    int get_length();
    T& operator[](int index);
};
template<typename T>
Array<T>::Array() {
    array =new T[0];
    length = 0;
}

template<typename T>
Array<T>::Array(T *array, int length) {
    this->array = array;
    this->length = length;
}

template<typename T>
Array<T>::~Array() {
    delete [] array;
}

template<typename T>
void Array<T>::push_back(T new_element) {
    make_bigger();
    array[length - 1] = new_element;
}

template<typename T>
int Array<T>::get_length() {
    return length;
}

template<typename T>
T &Array<T>::operator[](int index) {
    return *(array+index);
}

template<typename T>
void Array<T>::make_bigger() {
    T *new_array = new T[1+length];
    for (int i = 0; i < length; ++i) {
        *(new_array + i) = *(array+i);
    }
    array = new_array;
    length++;
}

#endif //PAYMENT_ARRAY_H
