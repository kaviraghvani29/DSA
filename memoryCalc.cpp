#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Student {
public:
    T id;
    string name;

    Student(T i, string n) {
        id = i;
        name = n;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    vector<Student<int>> students;

    students.push_back(Student<int>(1, "Kavita"));
    students.push_back(Student<int>(2, "Ravi"));
    students.push_back(Student<int>(3, "Sneha"));

    cout << "\nAll Students:\n";
    for (int i = 0; i < students.size(); i++)
        students[i].display();

    int searchId;
    cout << "\nEnter ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchId) {
            cout << "Student found: ";
            students[i].display();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student not found!\n";

    int removeId;
    cout << "\nEnter ID to remove: ";
    cin >> removeId;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == removeId) {
            students.erase(students.begin() + i);
            cout << "Student removed successfully!\n";
            break;
        }
    }

    cout << "\nStudents after removal:\n";
    for (int i = 0; i < students.size(); i++)
        students[i].display();

    return 0;
}
