#include <iostream>
#include <string>
#include <algorithm> // for std::sort
#include <limits>
using namespace std;

class Student {
private:
    std::string name;
    int id;
    double gpa;
    std::string major;

public:
    // Member functions to set values
    void setName(const std::string& newName) {
        name = newName;
    }

    void setID(int newID) {
        id = newID;
    }

    void setGPA(double newGPA) {
        gpa = newGPA;
    }

    void setMajor(const std::string& newMajor) {
        major = newMajor;
    }

    // Member functions to get values
    std::string getName() const {
        return name;
    }

    int getID() const {
        return id;
    }

    double getGPA() const {
        return gpa;
    }

    std::string getMajor() const {
        return major;
    }

    // Comparison operator for sorting by GPA in descending order
    bool operator<(const Student& other) const {
        return gpa > other.gpa;
    }
};

// Function to validate input for GPA between 0 and 4
double getValidGPAInput() {
    double gpa;

    do {
        std::cout << "Enter student's GPA (between 0 and 4): ";
        
        // Check if the input is a double
        if (std::cin >> gpa) {
            if (gpa < 0 || gpa > 4) {
                std::cout << "GPA must be between 0 and 4. Please try again.\n";
            } else {
                break; // Break out of the loop if the input is valid
            }
        } else {
            // Clear the error flag and discard invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter correct GPA. Please try again.\n";
        }
    } while (true);

    return gpa;
}
int main() {
    int numStudents; // Change the number of students as needed
    cout<<"Enter the number of Students: ";
    cin>>numStudents;
    Student students[numStudents];
    cout<<endl;

    // Input information for each student
    for (int i = 0; i < numStudents; i++) {
        std::cin.ignore(); // Clear the newline character from the buffer

        std::cout << "Enter information for student " << i + 1 << ":\n";
        std::cout << "Name: ";
        string NameInput;
        getline(cin, NameInput);
        students[i].setName(NameInput);
        
        students[i].setID(i + 1); // Using a simple sequential ID for demonstration
        students[i].setGPA(getValidGPAInput());

        std::cin.ignore(); // Clear the newline character from the buffer
        std::cout << "Major: ";
        string majorInput;
        std::getline(cin, majorInput);
        students[i].setMajor(majorInput);
    }

    // Sort the array of students by GPA in descending order
    std::sort(students, students + numStudents);

    // Display information for each student after sorting
    std::cout << "\nStudent Information (sorted by GPA in descending order):\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Student " << i + 1 << ":\n";
        std::cout << "Name: " << students[i].getName() << "\n";
        std::cout << "ID: " << students[i].getID() << "\n";
        std::cout << "GPA: " << students[i].getGPA() << "\n";
        std::cout << "Major: " << students[i].getMajor() << "\n\n";
    }

    return 0;
}