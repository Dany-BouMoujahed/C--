#include <iostream>
#include <string>
using namespace std;
class Person
{
    private:
    string name;
    country_t origin;
    gender_t gender;
    int birthyear;
    string originString(country_t origin){
        switch (origin)
        {
        case country_error:
            return "country error";
            break;
        case Lebanon:
            return "Lebanon";
            break;
        case Syria:
            return "Syria";
            break;
        case Palestine:
            return "Palestine";
            break;
        case Jordan:
            return "Jordan";
            break;
        case Iraq:
            return "Iraq";
            break;
        case UK:
            return "UK";
            break;
        default:
            "Error converting to string";
            break;
        }
    }
    string genderString(gender_t gender){
        switch (gender)
        {
        case gender_error:
            return "gender error";
            break;
        case Male:
            return "Male";
            break;
        case Female:
            return "Female";
            break;
        case Undefined:
            return "Undefined";
            break;
        default:
            return "Error converting to string";
            break;
        }
    }
    public:
    Person(){
        name = "eece330";
        origin = Lebanon;
        gender = Undefined;
        birthyear = 1912;
    }
    Person(string n, country_t o, gender_t g, int b){
        name = n;
        origin = o;
        gender = g;
        birthyear = b;
    }
    Person(Person & p){
        name = p.name;
        origin = p.origin;
        gender = p.gender;
        birthyear = p.birthyear;
    }
    Person & operator=(Person & p){
        name = p.name;
        origin = p.origin;
        gender = p.gender;
        birthyear = p.birthyear;
        return *this;
    }
    bool operator < (Person & other) const{
        return name < other.name;
    }
    string get_name() const{
        return name;
    }
    country_t get_origin() const {
        return origin;
    }
    gender_t get_gender() const {
        return gender;
    }
    int get_year_of_birth() const {return birthyear;}
    void set_name(string n){
        name = n;
    }
    void set_origin(country_t o){origin=o;}
    void set_gender(gender_t g){
        gender = g;
    }
    void set_year_of_birth(int b){
        birthyear = b;
    }
    void print(ostream & ostr){
        ostr << "name: " << name << endl
        << "origin: " << originString(origin) << endl
        << "gender: " << genderString(gender) << endl
        << "Year Of Birth: " << birthyear << endl;
    }
    
    friend ostream & operator << (ostream & ostream, Person & p);
};
    ostream & operator << (ostream & ostr, Person & p){
        p.print(ostr);
        return ostr;
    }