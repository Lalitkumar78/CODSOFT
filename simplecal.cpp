#include <iostream>
using namespace std;

int main() {
    double n1, n2;
    char op;

    cout<<"Welcome to Simple Calculator"<<endl;
    cout<<"Enter first number: ";
    cin>>n1;

    cout<<"Enter an operator (+, -, *, /): ";
    cin>>op;

    cout<<"Enter second number: ";
    cin>>n2;

    cout<<"\nResult: ";

    switch(op)
    {
        case '+':
            cout<<n1<<" + "<<n2<<" = "<<n1 + n2;
            break;
        case '-':
            cout<<n1<<" - "<<n2<<" = "<<n1 - n2;
            break;
        case '*':
            cout<<n1<<" * "<<n2<<" = "<<n1 * n2;
            break;
        case '/':
            if(n2 != 0)
                cout<<n1<<" / "<<n2<<" = "<<n1 / n2;
            else
                cout<<"Division by zero is not allowed";
            break;
        default:
            cout<<"Invalid operator";
    }

    cout<<"\nThank you for using the calculator."<<endl;
    return 0;
}