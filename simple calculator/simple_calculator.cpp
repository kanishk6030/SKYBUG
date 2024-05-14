
#include <bits/stdc++.h>
using namespace std;

// Simple Calculator 
class Simple{
    protected:
    float n1,n2;
    
    public:
    float funtionalites(float num1,float num2){
        n1=num1;
        n2=num2;
        int a;
        cout << "1.Add" <<endl<< "2.Subtract" <<endl<< "3.Multiply" <<endl<< "4.Divide"<<endl ;
        cout << "Enter the Choice:"<< endl;
        cin >> a;
        switch(a){
            case 1:
            // Addition
            return n1+n2;
            break;
            case 2:
            // Substraction
            return n1-n2;
            break;
            case 3:
            // Multiplication
            return n1*n2;
            break;
            case 4:
            // Divide
            return (n1/n2);
            break;
        }
    }
    
};

// Hybrid Calculator
int main (){
    Simple Calc;
    float ans;
    float a,b;
    cout << "Enter the numbers 1: "<<endl;
    cin  >> a;
    cout << "Enter the number 2: "<<endl;
    cin >> b;
    ans = Calc.funtionalites(a,b);
    cout << "The answer is :"<< ans;
}

