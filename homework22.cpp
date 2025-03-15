#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Student {
private:
    string name;
    string surname;
    int album_number;
    vector<float> grades;

public:
   
    Student() {}

   
    void set_name(string n, string s) {
        name = n;
        surname = s;
    }

  
    bool set_album_number(int album) {
        if (album >= 10000 && album <= 999999) {
            album_number = album;
            return true;
        }
        cout << "Invalid album number! It must be 5 or 6 digits.\n";
        return false;
    }

  
    bool add_grade(float grade) {
        if (grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
        cout << "Invalid grade! Must be between 2.0 and 5.0.\n";
        return false;
    }

    
    float calculate_mean_grade() {
        if (grades.empty()) return 0.0;
        return accumulate(grades.begin(), grades.end(), 0.0f) / grades.size();
    }

    
    bool passed_semester() {
        int count_of_twos = count(grades.begin(), grades.end(), 2.0);
        return count_of_twos <= 1;
    }


    void print_summary() {
        cout << "\nStudent: " << name << " " << surname << "\n";
        cout << "Album number: " << album_number << "\n";
        cout << "Grades: ";
        for (float g : grades) {
            cout << g << " ";
        }
        cout << "\nMean Grade: " << calculate_mean_grade() << "\n";
        cout << "Semester Passed: " << (passed_semester() ? "Yes" : "No") << "\n";
    }

    
    void get_student_info() {
        string n, s;
        int album;
        float grade;
        int num_grades;

        cout << "Enter student name: ";
        cin >> n;
        cout << "Enter student surname: ";
        cin >> s;
        set_name(n, s);

        do {
            cout << "Enter album number (5 or 6 digits): ";
            cin >> album;
        } while (!set_album_number(album));

        cout << "How many grades do you want to enter? ";
        cin >> num_grades;

        for (int i = 0; i < num_grades; i++) {
            do {
                cout << "Enter grade " << (i + 1) << " (between 2.0 and 5.0): ";
                cin >> grade;
            } while (!add_grade(grade));
        }
    }
};

int main() {
    Student student;
    student.get_student_info();
    student.print_summary();

    return 0;
}
