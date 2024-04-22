#include "lab9.h"

using namespace std;

lab9::lab9() : root(nullptr) {}

lab9::~lab9() {
    clear();
}

lab9::Node* lab9::insert(Node* node, const Student& student) {
    if (node == nullptr) {
        return new Node(student);
    }

    // Учитываем порядок по фамилии, затем имени, затем группе
    if (student.lastName < node->data.lastName ||
        (student.lastName == node->data.lastName && student.firstName < node->data.firstName) ||
        (student.lastName == node->data.lastName && student.firstName == node->data.firstName && student.group < node->data.group)) {
        node->left = insert(node->left, student);
    }
    else if (student.lastName > node->data.lastName ||
        (student.lastName == node->data.lastName && student.firstName > node->data.firstName) ||
        (student.lastName == node->data.lastName && student.firstName == node->data.firstName && student.group > node->data.group)) {
        node->right = insert(node->right, student);
    }

    return node;
}

lab9::Node* lab9::remove(Node* node, const Student& student) {
    if (node == nullptr) {
        return nullptr;
    }

    // Ищем удаляемый узел
    if (student.lastName < node->data.lastName ||
        (student.lastName == node->data.lastName && student.firstName < node->data.firstName) ||
        (student.lastName == node->data.lastName && student.firstName == node->data.firstName && student.group < node->data.group)) {
        node->left = remove(node->left, student);
    }
    else if (student.lastName > node->data.lastName ||
        (student.lastName == node->data.lastName && student.firstName > node->data.firstName) ||
        (student.lastName == node->data.lastName && student.firstName == node->data.firstName && student.group > node->data.group)) {
        node->right = remove(node->right, student);
    }
    else {
        // Нашли удаляемый узел
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = remove(node->right, minRight->data);
        }
    }

    return node;
}

lab9::Node* lab9::find(Node* node, const Student& student) {
    if (node == nullptr) {
        return nullptr;
    }

    if (student.lastName < node->data.lastName ||
        (student.lastName == node->data.lastName && student.firstName < node->data.firstName) ||
        (student.lastName == node->data.lastName && student.firstName == node->data.firstName && student.group < node->data.group)) {
        return find(node->left, student);
    }
    else if (student.lastName > node->data.lastName ||
        (student.lastName == node->data.lastName && student.firstName > node->data.firstName) ||
        (student.lastName == node->data.lastName && student.firstName == node->data.firstName && student.group > node->data.group)) {
        return find(node->right, student);
    }
    else {
        return node;
    }
}

lab9::Node* lab9::findMin(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->left == nullptr) {
        return node;
    }

    return findMin(node->left);
}

void lab9::clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    clear(node->left);
    clear(node->right);
    delete node;
}

void lab9::insert(const Student& student) {
    root = insert(root, student);
}

void lab9::remove(const Student& student) {
    root = remove(root, student);
}

bool lab9::contains(const Student& student) {
    return find(root, student) != nullptr;
}

std::vector<Student> lab9::getAllStudents() const {
    vector<Student> result;
    toArray(root, result);
    return result;
}

void lab9::clear() {
    clear(root);
    root = nullptr;
}

void lab9::toArray(Node* node, std::vector<Student>& result) const {
    if (node == nullptr) {
        return;
    }

    toArray(node->left, result);
    result.push_back(node->data);
    toArray(node->right, result);
}
