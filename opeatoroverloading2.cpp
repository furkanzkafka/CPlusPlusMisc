#include <iostream>
using namespace std;

class Employee {
public:
    Employee() {};
    Employee(int salary) {
        employee_salary = salary;
    };

    void print_employee() {
        cout << employee_name << " " << employee_salary << endl;
    };


    string getName() {
        return employee_name;
    }
    int getSalary()const {
        return employee_salary;
    }

    void setName(string name) {
        employee_name = name;
    }
    void setSalary(int salary) {
        employee_salary = salary;
    }


private:
    string employee_name;     
    int employee_salary;
};


const Employee operator +(const Employee& a, const Employee& b);
const Employee operator +(const Employee& a, const Employee& b) {
    int employee_salary = a.getSalary() + b.getSalary();

    return Employee(employee_salary);
};


int main()
{
    Employee emp1(200);
    emp1.setName("Furkan");


    Employee emp2(150);
    emp2.setName("John");

 

    emp1.print_employee();
    emp2.print_employee();

    
    Employee employee_total;
    employee_total = emp1 + emp2;

    cout << " emp1 + emp2 is: ";
    employee_total.print_employee();
    cout << endl;
   

}
