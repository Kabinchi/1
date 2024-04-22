#include <iostream>
#include "lab9.h"

using namespace std;

// Функция для ввода студента
Student inputStudent() {

    string lastName, firstName, group;
    int studentID;

    cout << "Введите фамилию: ";
    cin >> lastName;
    cout << "Введите имя: ";
    cin >> firstName;
    cout << "Введите группу: ";
    cin >> group;
    cout << "Введите номер зачетной книжки: ";
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
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Проверить наличие студента" << endl;
        cout << "3. Удалить студента" << endl;
        cout << "4. Вывести всех студентов" << endl;
        cout << "0. Выйти из программы" << endl;
        cout << "==============================\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nДобавление студента:\n";
            Student newStudent = inputStudent();
            tree.insert(newStudent);
            cout << "Студент добавлен.\n";
            break;
        }
        case 2: {
            cout << "\nПоиск студента:\n";
            studentToFind = inputStudent();
            if (tree.contains(studentToFind)) {
                cout << "Студент найден!" << endl;
            }
            else {
                cout << "Студент не найден." << endl;
            }
            break;
        }
        case 3: {
            cout << "\nУдаление студента:\n";
            studentToRemove = inputStudent();
            if (tree.contains(studentToRemove)) {
                tree.remove(studentToRemove);
                cout << "Студент удален." << endl;
            }
            else {
                cout << "Студент не найден для удаления." << endl;
            }
            break;
        }
        case 4: {
            cout << "\nСписок всех студентов:\n";
            vector<Student> allStudents = tree.getAllStudents();
            for (const auto& student : allStudents) {
                cout << "Фамилия: " << student.lastName << ", Имя: " << student.firstName << ", Группа: " << student.group << ", Зачетка: " << student.studentID << endl;
            }
            break;
        }
        case 0: {
            cout << "Завершение программы.\n";
            break;
        }
        default: {
            cout << "Некорректный ввод. Пожалуйста, введите число от 0 до 4." << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
