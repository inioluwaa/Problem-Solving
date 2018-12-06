#include <string>
#include <iomanip>
#include <array>

#include <iostream>

class GradeBook {
public:
    static const size_t students{10};

    GradeBook(const std::string& name, const std::array<int, students>& gradesArray)
        : courseName{name}, grades{gradesArray} {
    }

    void setCourseName(std::string& name) {
        courseName = name;
    }

    const std::string& getCourseName() const {
        return courseName;
    }

    void displayMessage() const {
        std::cout << "Welcome to the grade book for /n" << getCourseName() << "!" << std::endl;
    }



private:
    std::string courseName;
    std::array<int, students> grades;
};