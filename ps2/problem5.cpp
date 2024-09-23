#include <iostream>
using namespace std;
struct Fnumber{
    private:
    double a;
    double b;
    public:
    Fnumber(){
        a = 0;
        b = 0;
    }
    Fnumber(double aa, double bb){
        a= aa;
        b=bb;
    }

    friend ostream &operator <<(ostream &ostr,Fnumber &Fnum);

    Fnumber operator*(Fnumber & f) const {
        return Fnumber((a*f.a)+(b*f.b*2),(a*f.b)+(b*f.a));
    }
    bool operator >(Fnumber & f) const {
        return (a +(b*1.41421356) > f.a+(f.b*1.41421356));
    }
    bool isPositive(){
        if (a+(b*1.41421356)>= 0){
            return true;
        }    
        else {
            return false;
        }    
    }      
};
void FnumbubbleSort(Fnumber arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                Fnumber temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

ostream & operator <<(ostream & ostr, Fnumber & Fnum){
            if (Fnum.b!=0){
            if (Fnum.b>0){
                if(Fnum.b==1){
                    ostr << Fnum.a <<"+sqrt(2)";}
                else{    
                    ostr << Fnum.a <<"+"<<Fnum.b<<"sqrt(2)";}
            }
            else{
                if(Fnum.b==-1){
                    ostr << Fnum.a <<"-sqrt(2)";
                }
                else{    
                    ostr << Fnum.a<<Fnum.b<<"sqrt(2)";
                }   
            }
        }
        else{
            ostr << Fnum.a;} 
        return ostr;
}
int main(){
    Fnumber A[1024];
    int num=0;
    int maxnum;
    while (true)
    {
      int code;
      cin>>code;
      if (code==1){
        double a;
        cin>>a;
        double b;
        cin>>b;
        A[num]=Fnumber(a,b);
        if (A[num]>A[maxnum] && num!=0){
            maxnum=num; 
        }    
        num++;
        }   
      else if (code==2){
        for (int i = 0; i < num-1; i++)
        {
            cout<<A[i]<<", ";     
        }
        cout<<A[num-1]<<endl;
        }
      else if (code==3){
        Fnumber sorted[1024];
        for (int i = 0; i < num; i++)
        {
            sorted[i]=A[i];     
        } 
        FnumbubbleSort(sorted,num);
        for (int i = 0; i < num-1; i++)
        {
            cout<<sorted[i]<<", ";     
        }
        cout << sorted[num-1]<<endl;
        }
      else if (code==4){
        cout<<A[maxnum]<<endl;
      }
      else if (code==5){
        int i;
        cin>>i;
        int j;
        cin>>j;
        A[num]=A[i]*A[j];
        if (A[num]>A[maxnum] && num!=0){
            maxnum=num; 
        }    
        num++;
      }
      else if (code==6){
        int index;
        cin>>index;
        cout<<A[index].isPositive()<<endl;
      }
      else if (code==7){
        cout<<"Bye!";
        break;
      }           
    }
    return 0;
    
}