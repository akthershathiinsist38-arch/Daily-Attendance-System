#include <iostream>
#include <string>
using namespace std;

int id[100], present[100], total[100];
string name[100];
int n = 0;

// 1. Add Student
void addStudent() {
    cout << "Enter ID: ";
    cin >> id[n];

    cout << "Enter Name: ";
    cin >> name[n];

    present[n] = 0;
    total[n] = 0;

    n++;

    cout << "Student Added Successfully!" << endl;
}

// 2. Mark Attendance
void markAttendance() {
    for (int i = 0; i < n; i++) {
        char status;

        cout << name[i] << " (P/A): ";
        cin >> status;

        total[i]++;

        if (status == 'P' || status == 'p') {
            present[i]++;
        }
    }

    cout << "Attendance Recorded!" << endl;
}

// 3. View Records
void viewRecords() {
    for (int i = 0; i < n; i++) {
        double percent = (total [i] == 0) ? 0.0 :
                           present [i] * 100.0 / total [i] ;

        cout << id[i] << " "
             << name[i] << " "
             << percent << "%" << endl;
    }
}

// 4. Search Student
void searchStudent() {
    int key;

    cout << "Enter Student ID: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (id[i] == key) {
            cout << "Student Found: "
                 << name[i] << endl;
            return;
        }
    }

    cout << "Student Not Found!" << endl;
}

// 5. Highest Attendance
void highestAttendance() {
    int best = 0;

    for (int i = 1; i < n; i++) {
       double p1 = (total[i] == 0) ? 0.0 :
                    present [i] * 1.0 / total [i];
        double p2 = (total[best] == 0) ? 0.0 :
                     present [best] * 1.0 / total [best];
           if (p1 > p2) {
               best = i;
        }
    }

    cout << "Highest Attendance: "
         << name[best] << endl;
}

// 6. Bubble Sort
void bubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            double p1 = (total [j] == 0) ? 0.0 :
                         present [j] * 1.0 / total [j];
            double p2 = (total [j + 1] == 0) ? 0.0 :
                         present [j + 1] * 1.0 / total [j + 1];

            if (p1 < p2) {
                int temp;

                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;

                temp = present[j];
                present[j] = present[j + 1];
                present[j + 1] = temp;

                temp = total[j];
                total[j] = total[j + 1];
                total[j + 1] = temp;

                string tempName;

                tempName = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempName;
            }
        }
    }

    cout << "Records Sorted!" << endl;
    viewRecords();
}

// 7. Main Function
int main() {
    int choice;

    do {
        cout << "\nSTUDENT ATTENDANCE SYSTEM\n";
        cout << "1. Add Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. View Records\n";
        cout << "4. Search Student\n";
        cout << "5. Highest Attendance\n";
        cout << "6. Sort Attendance\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                markAttendance();
                break;

            case 3:
                viewRecords();
                break;

            case 4:
                searchStudent();
                break;

            case 5:
                highestAttendance();
                break;

            case 6:
                bubbleSort();
                break;

            case 7:
                cout << "Program Ended!" << endl;
                break;

            default:
                cout << "Wrong Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
