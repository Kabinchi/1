#ifndef LAB9_H
#define LAB9_H

#include "student.h"
#include <vector>
#include <stdexcept>

class lab9 {
private:
    struct Node {
        Student data;
        Node* left;
        Node* right;

        Node(const Student& student) : data(student), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const Student& student);
    Node* remove(Node* node, const Student& student);
    Node* find(Node* node, const Student& student);
    Node* findMin(Node* node);
    void clear(Node* node);
    void toArray(Node* node, std::vector<Student>& result) const;

public:
    lab9();
    ~lab9();

    void insert(const Student& student);
    void remove(const Student& student);
    bool contains(const Student& student);
    std::vector<Student> getAllStudents() const;
    void clear();
};

#endif
