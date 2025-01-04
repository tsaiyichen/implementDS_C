cmake_minimum_required(VERSION 3.30)
project(implementDS_C)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ch1 CH1/CH1_main.cpp
        CH5/BinaryTree.cpp
        CH5/BinaryTree.hpp)
add_executable(Ch2 CH2/Matrix.cpp)
add_library(Stack_array CH3/Stack_Array.cpp)
add_library(Stack_LL CH3/Stack_LL.cpp CH3/Stack_LL.hpp)
add_executable(Stack CH3/Stack_testing.cpp)
target_include_directories(Stack PUBLIC CH3)
target_link_libraries(Stack PUBLIC Stack_LL Stack_array)
add_library(Queue_Array CH3/Queue_array.cpp CH3/Queue_array.hpp
        CH3/Queue_LL.cpp
        CH3/Queue_LL.hpp)
add_library(Queue_LL CH3/Queue_LL.cpp CH3/Queue_LL.hpp)
add_library(QandS CH3/QueueANDStack.cpp CH3/QueueANDStack.hpp)
add_executable(CH3Main CH3/CH3Main.cpp)
target_include_directories(CH3Main PUBLIC CH3)
target_link_libraries(CH3Main PUBLIC QandS)
add_library(BinaryTree CH5/BinaryTree.cpp CH5/BinaryTree.hpp)
add_library(BinarySearchTree CH5/BinarySearchTree.cpp CH5/BinarySearchTree.hpp)
add_executable(BSTMain CH5/BSTMain.cpp)
target_include_directories(BSTMain PUBLIC CH5)
target_link_libraries(BSTMain PUBLIC BinaryTree BinarySearchTree)
add_library(Heap CH5/Heap.cpp CH5/Heap.hpp)
add_executable(heapMain CH5/heapMain.cpp)
target_include_directories(heapMain PUBLIC CH5)
target_link_libraries(heapMain PUBLIC Heap)
