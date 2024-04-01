cmake_minimum_required(VERSION 3.0.0)

project(DoublyLinkedList)

set(SOURCE_FILES
    main.cpp
    CNode.h
    CNode.cpp
    CLinkedList.h
    CLinkedList.cpp
)

add_executable(DoublyLinkedList ${SOURCE_FILES})
