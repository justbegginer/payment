cmake_minimum_required(VERSION 3.17)
project(payment)

set(CMAKE_CXX_STANDARD 14)

add_executable(payment main.cpp Array.h Payment.cpp Payment.h)