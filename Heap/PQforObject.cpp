#include <iostream>
#include <queue>
using namespace std;

class student {
public:
    string name;
    int marks;

    // Constructor
    student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    // Overload the < operator for priority_queue
    bool operator<(const student &object) const {
        return this->marks < object.marks; // Max-heap: higher marks have higher priority
    }
};

int main() {
    priority_queue<student> pq;

    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // Input student details
    for (int i = 0; i < n; i++) {
        string name;
        int marks;
        cout << "Enter name and marks for student " << i + 1 << ": ";
        cin >> name >> marks;
        pq.push(student(name, marks));
    }

    // Display students in descending order of marks
    cout << "\nStudents in descending order of marks:\n";
    while (!pq.empty()) {
        cout << "Name: " << pq.top().name << ", Marks: " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}
