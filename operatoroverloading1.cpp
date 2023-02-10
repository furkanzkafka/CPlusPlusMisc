class Department {
public:
    Department() {};
    Department(int dept_id, string name, int total)
    {
        dept_id = dept_id;
        employee_name = name;
        employee_total = total;
    }

    int getId() const { return dept_id; };
    string getName() { return employee_name; };
    int operator+(Department const& a) const;


private:
    int dept_id;
    string employee_name;
    int employee_total = 0;
};


int Department::operator+(Department const& d) const {
    int sum = (employee_total + d.employee_total);
    return sum;
}


int main()
{
    Department dept1(100, "Comp", 10);
    Department dept2(20, "Math", 20);
    
    cout << "Sum of total employee: " << dept1 + dept2 << endl;

}
