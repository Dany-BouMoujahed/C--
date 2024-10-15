#pragma once
#include <iostream>
using namespace std;
class Course{
    private:
    string title;
    int cap;
    int reg;
    Student ** st;
    public:
    Course(string t, int c){
        title = t;
        cap = c;
        reg = 0;
        st = new Student * [c];
    }
    Course(string t, int c, Student * in[], int r){
        title = t;
        cap = c;
        reg = r;
        st = in;
    }
    int countFilter(double g){
        int count = 0;
        for (int i = 0; i < reg; i++){
            if (st[i]->returnGPA() >= g){
                count++;
            }
        }
        return count;
    }
    bool addStudent(Student * s){
        if (reg >= cap){
            return false;
        }
        else{
            st[reg] = s;
            reg++;
            s->addCourse();
            return true;
        }
    }
    Student** filter(double g){
        Student** b = new Student*[countFilter(g)];
        int j = 0;
        for (int i = 0; i < reg; i++){
            if (st[i]->returnGPA() >= g){
                b[j] = st[i];
                j++;
            }
        }
        return b;
    }
};