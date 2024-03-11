#include <iostream>
#include <string>
using namespace std;
class User {
private:
    string name;
    int birth_Year;
    int birth_Month;
    int birth_Day;
    double salary;
public:
    User(const string& n, int year, int month, int day, double sal)
        : name(n), birth_Year(year), birth_Month(month), birth_Day(day), salary(sal) {}
    int operator==(const User& other) const {
        if (birth_Year < other.birth_Year)
            return 1;
        else if (birth_Year > other.birth_Year)
            return -1;
        else {
            if (birth_Month < other.birth_Month)
                return 1;
            else if (birth_Month > other.birth_Month)
                return -1;
            else {
                if (birth_Day < other.birth_Day)
                    return 1;
                else if (birth_Day > other.birth_Day)
                    return -1;
                else
                    return 0;
            }
        }
    }
    double operator+(const User& other) const {
        return (salary + other.salary) / 2.0;
    }
    User operator+(const int& percent_increment) const {
        double increment_factor = (percent_increment + 100) / 100.0;
        double new_salary = salary * increment_factor;
        return User(name, birth_Year, birth_Month, birth_Day, new_salary);
    }
    void display() const {
        cout << "Name: " << name << ", Birthdate: " << birth_Day << "/" << birth_Month << "/" << birth_Year
             << ", Salary: " << salary << endl;
    }
};
int main() {
    User user1("Mohan Lal", 1995, 5, 15, 50000.0);
    User user2("Sham Lal", 1985, 9, 25, 60000.0);
    int result = user1 == user2;
    cout << "Comparison result: " << result << endl;
    double average_sal = user1 + user2;
    cout << "Average salary: " << average_sal << endl;
    User user1_with_increment = user1 + 5;
    cout << "User 1 with 5% increment: ";
    user1_with_increment.display();
    User user2_with_increment = user2 + 10;
    cout << "User 2 with 10% increment: ";
    user2_with_increment.display();
    return 0;
}