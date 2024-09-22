#include <cmath>
using namespace std;
class Complex{
    private:
    double x;
    double y;
    public:
    Complex(double ax = 0.0, double ay = 0.0): x(ax),y(ay){}
    double getReal() const {return x;}
    double getImaginary() const {return y;}
    void setReal(double ax) {x = ax;}
    void setImaginary(double ay){y = ay;}
    void scale(double factor){
        x*=factor;
        y*=factor;
    }
    double distance(Complex const & c) const {
        double dx = x - c.x;
        double dy = x - c.y;
        return sqrt(dx*dx+dy*dy);
    }
    void normalize(){
        double mag = distance(Complex(0,0));
        if (mag > 0.0) {scale(1/mag);}
    }
};
Complex operator+(Complex & a,Complex & b){
    return Complex((a.getReal()+b.getReal()),(a.getImaginary()+b.getImaginary()));
}
Complex operator-(Complex & a){
    return Complex(-a.getReal(),-a.getImaginary());
}
Complex operator-(Complex & a, Complex & b){
    Complex temp = -b;
    return a+temp;
}
int main(){
    Complex c1(2,1);
    return 0;
}