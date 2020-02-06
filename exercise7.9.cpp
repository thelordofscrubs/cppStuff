#include <iostream>
#include <string.h>
using namespace std;

const int SLEN = 30;

struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.

int getinfo(student pa[], int n);

// display1() takes a student structure as an argument
// and displays its contents

void display1(student st);

// display2() takes the address of student structure as an
// argument and displays the structure’s contents

void display2(const student * ps);

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures

void display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    //cout << "the array contains " << entered << "students\n";
    for (int i = 0; i < entered; i++)
    {
        cout << "\nDisplaying info of student #" << i << "---------------------------------------------\n";
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "\n\nDone\n";
    return 0;
}

int getinfo(student pa[], int n)
{
    char name[SLEN];
    for (int i = 0; i < n; i++) {
        cout << "\n\nPlease enter the details for student #" << i+1 << "\nName:";
        cin.getline(name, SLEN);
        if ((int)name[0] == 0) {
        //    cout << "name == '" <<name<<"'";
            return i;
        }
        //cout << "name == '" <<(int)name[0]<<"'";
        strcpy(pa[i].fullname, name);
        cout << "\nHobby:";
        cin >> pa[i].hobby;
        cout << "\nOoplevel:";
        cin >> pa[i].ooplevel;
        //cout << "accessing student object;\nName: "<<pa[i].fullname<<"\nHobby: "<<pa[i].hobby<<"\nooplevel: "<<pa[i].ooplevel;
        cin.ignore(1);
    }
    return n;
}

void display1(student st)
{
    cout << "\n\nDisplaying by directly reading the struct:\n\nName: " << st.fullname << "\nHobby: " << st.hobby << "\nOOPlevel: " << st.ooplevel<< "\n";
    
}

void display2(const student * ps)
{
    cout << "\nDisplaying by reading the struct through a pointer:\n\nName: " << (*ps).fullname << "\nHobby: " << (*ps).hobby << "\nOOPlevel: " << (*ps).ooplevel<< "\n";
}

void display3(const student pa[], int n)
{
    cout << "\nDisplaying all the students via a pointer to the first element in the array:\n\n";
    for (int i = 0; i < n; i++) {
        cout << "\nName: " << (*(pa+i)).fullname << "\nHobby: " << (*(pa+i)).hobby << "\nOOPlevel: " << (*(pa+i)).ooplevel;
    }
}