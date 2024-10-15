#pragma once
#include <iostream>
using namespace std;
class Student {
    private:
    int ID;
    string name;
    double GPA;
    int totalCourses;
    public:
    Student(int i=0, string n="Fadi", double g=0, int t=0){
        ID = i;
        name = n;
        GPA = g;
        totalCourses = t; 
    }
    friend ostream & operator<<(ostream & o, Student & s){
        o << "ID: " << s.ID << "," << endl << "Name: " << s.name << "," << endl << "GPA: " << s.GPA << "," << endl << "Total Number of Courses: " << s.totalCourses << endl;
        return o;
    }
    bool operator < (Student & s)const{
        return ID < s.ID;
    }
    friend void raiseGPA(Student * s[], int n, int raise){
        for (int i = 0; i < n; i++){
            s[i]->GPA+=raise;
        }
    }
    double returnGPA() const {
        return GPA;
    }
    void addCourse() {
        totalCourses++;
    }
};