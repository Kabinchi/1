#include <iostream>
#include "lab9.h"

using namespace std;

// ������� ��� ����� ��������
Student inputStudent() {

    string lastName, firstName, group;
    int studentID;

    cout << "������� �������: ";
    cin >> lastName;
    cout << "������� ���: ";
    cin >> firstName;
    cout << "������� ������: ";
    cin >> group;
    cout << "������� ����� �������� ������: ";
    cin >> studentID;

    return { lastName, firstName, group, studentID };
}

int main() {
    setlocale(LC_ALL, "Russian");
    lab9 tree;

    tree.insert({ "Ivanov", "Ivan", "TMsp-100", 1234 });
    tree.insert({ "Petrov", "Egor", "TRsp-322", 4321 });
    tree.insert({ "Sidorov", "Sidor", "TMsp-100", 9876 });
    tree.insert({ "Ivanov", "Petr", "PKsp-121", 2468 });

    int choice;
    Student studentToFind;
    Student studentToRemove;

    do {
        cout << "\n==============================\n";
        cout << "�������� ��������:" << endl;
        cout << "1. �������� ��������" << endl;
        cout << "2. ��������� ������� ��������" << endl;
        cout << "3. ������� ��������" << endl;
        cout << "4. ������� ���� ���������" << endl;
        cout << "0. ����� �� ���������" << endl;
        cout << "==============================\n";
        cout << "�����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\n���������� ��������:\n";
            Student newStudent = inputStudent();
            tree.insert(newStudent);
            cout << "������� ��������.\n";
            break;
        }
        case 2: {
            cout << "\n����� ��������:\n";
            studentToFind = inputStudent();
            if (tree.contains(studentToFind)) {
                cout << "������� ������!" << endl;
            }
            else {
                cout << "������� �� ������." << endl;
            }
            break;
        }
        case 3: {
            cout << "\n�������� ��������:\n";
            studentToRemove = inputStudent();
            if (tree.contains(studentToRemove)) {
                tree.remove(studentToRemove);
                cout << "������� ������." << endl;
            }
            else {
                cout << "������� �� ������ ��� ��������." << endl;
            }
            break;
        }
        case 4: {
            cout << "\n������ ���� ���������:\n";
            vector<Student> allStudents = tree.getAllStudents();
            for (const auto& student : allStudents) {
                cout << "�������: " << student.lastName << ", ���: " << student.firstName << ", ������: " << student.group << ", �������: " << student.studentID << endl;
            }
            break;
        }
        case 0: {
            cout << "���������� ���������.\n";
            break;
        }
        default: {
            cout << "������������ ����. ����������, ������� ����� �� 0 �� 4." << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
