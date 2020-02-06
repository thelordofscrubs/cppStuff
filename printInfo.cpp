//Assignment #2 by Eemeli Kaituri
//02/02/2020

#include <iostream>
using namespace std;

int main() {
    char name[] = "Eemeli (Eli) Kaituri";
    char email[] = "ekaituri@gmail.com";
    char home[] = "Helsinki";
    char college[] = "Normandale Community College";
    int currentYear = 2;
    int aged = 20;
    int ageo = 024;
    int ageh = 0x14;
    cout << "My name is " <<name;
    cout << "\nMy email address is " << email;
    cout << "\nMy hometown is " << home;
    cout << "\nThe college I am currently attending is " << college;
    cout << "\nI am currently in year " << currentYear << " of college";
    cout << "\nMy age in decimal notation is " << aged;
    cout << "\nMy age in octal notation is " << oct << ageo;
    cout << "\nMy age in hexadecimal notation is " << hex << ageh;


    return 0;
}