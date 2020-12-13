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


#endif //PAYMENT_ARRAY_H
