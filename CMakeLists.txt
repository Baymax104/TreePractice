cmake_minimum_required(VERSION 3.17)
project(Tree C)

set(CMAKE_C_STANDARD 11)

add_executable(Tree main.c Parent.c Parent.h
        ParentAndChild.c ParentAndChild.h
        ChildAndSibling.c ChildAndSibling.h
        BinaryLinkedList.c BinaryLinkedList.h
        NonRecursiveTraversal.c NonRecursiveTraversal.h
        SuffixTree.c SuffixTree.h
        BinarySearchTree.c BinarySearchTree.h
        ThreadBinaryTree.c ThreadBinaryTree.h
        AVLTree.c AVLTree.h
        RedBlackTree.c RedBlackTree.h
        SplayTree.c SplayTree.h
        )