#include <iostream>
#include <limits>

using namespace std;

int main() {
    double num1, num2;
    char operation;
    double result;

    cout << "\nWelcome to the Basic Calculator!" << endl;

    // Input validation for the first number
    
    int choice;

    while(1){
        cout << "\nEnter the first number: ";
        while (!(cin >> num1)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number: ";
        }

        // Input validation for the second number
        cout << "Enter the second number: "<<endl;
        while (!(cin >> num2)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number: ";
        }
        cout << "\nChoose an operation: "<<endl;
        cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n"<<endl;
        cin >> choice;
        switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "\nResult: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "\nResult: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "\nResult: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "\nResult: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "\nError: Division by zero is not allowed." << endl;
            }
            break;
        case 5:exit(0);
        default:
            cout << "\nError: Invalid operation." <<endl;
            break;
    }
    }

    return 0;
}
