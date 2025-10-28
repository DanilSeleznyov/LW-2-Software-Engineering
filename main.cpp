#include <iostream> 
#include <cmath>
#include <typeinfo>
#include <iomanip> 
#include <limits>
#include <sstream>
#include <string>
using namespace std;

int readN(const string& prompt) {
    int value;
    string input;
    bool valid = false;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do {
        cout << prompt;
        
        getline(cin, input);

        stringstream ss(input);
        if (ss >> value && ss.eof() && value > 1) {
            valid = true;
        } else {
            cout << "|--> Invalid input! Please enter an integer greater than 1!\n";
        }
    } while (valid == false);
    return value;
}

int subMenu(){
    int choice = 0;

    cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n"
            "| 1. Main Menu                                                   |\n"
            "| 2. Exit                                                        |\n"
            "|----------------------------------------------------------------|\n"
            "| Choose use case (enter the number 1-2): "; 
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {  
        cout << "| Invalid input! Please enter 1 or 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "|________________________________________________________________|\n"
            " " << endl;   

    return choice;
}

int mainScreen(){
    int choice = 0;
    do{

        cout << "                                                                  \n"
                "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n"
                "|                       ---- MAIN MENU ----                      |\n"
                "|________________________________________________________________|\n"
                "| 1. Calclate the value of function                              |\n"
                "| 2. About Author                                                |\n"
                "| 3. FAQ                                                         |\n"
                "| 4. System Documenation                                         |\n"
                "| 5. Exit                                                        |\n"
                "|----------------------------------------------------------------|\n"
                "| Choose use case (enter the number 1-5): "; 
        while (!(cin >> choice)) {  
            cout << "| Invalid input! Please enter an integer from 1 to 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "|________________________________________________________________|\n"
                " " << endl;

        return choice;

    } while (choice == 0);
}

int calculator(){
    int choice = 0;

    do{
        
        double x, x1, xN, step;
        long long n;
        int counter = 0;
        string inputValue;

        cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n"
                "|                     ---- CALCULATION OF FUNCTION ----                     |\n"
                "|___________________________________________________________________________|\n"
                "| Enter the value of x₁ (the lower constraint, must be Real number): ";

        while (!(cin >> x1)) {  
            cout << "|------------------>Invalid input of x₁! Please enter a Real number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        

        cout << "| Enter the value of xₙ (the upper constraint, must be Real number): ";
        while (!(cin >> xN) || xN < x1) {  
            cout << "|--->Invalid input of xₙ! Please enter a number that bigger than x1: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        if(xN == x1){
            cout << "|---------------------------------------------------------------------------|\n"
                    "| Attention! You have entered the same values of x₁ and xn, so the program  |\n"
                    "| will calculate the result only for this value and 'step' will not be used.|\n"
                    "|---------------------------------------------------------------------------|\n";
        }

        cout << "| Enter the step between each «x» (must be positive Real number): ";
        while (!(cin >> step) || step <= 0) {  
            cout << "|-->Invalid input of 'step'! Please enter a positive Real number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }  

        n = readN("| Enter the value of n (must be an integer and bigger than 1): ");

        cout << "|___________________________________________________________________________|\n"   
                " " << endl;   
        
        x = x1;
        do{
            counter++;
                if(x < 1){
                    double prod = 1.0, sum = 0.0;
                    long long j, i;                
                    for(i = 0; i <= n; i++){
                        prod = 1.0;                                   
                        for (j = 1; j <= n + 1; j++){              
                            long long base = (7*i + j - (3*i*j));
                            prod *= base * base;                        
                        }
                        sum += prod;                    
                    }
                    cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n";
                    cout << "| If x" << counter << " = " << x << ", y = " << fixed << setprecision(5) << sum << endl;
                    cout << "|____________________________________|\n"
                            " " << endl;
                }else{                        
                    double prod = 0, res;
                    long long j;

                    // for(j = 1; j < n+1; j++){
                    //     if((2*x + 3*j) == 0){
                    //         cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n"
                    //                 "|      The value of y is undefined (division by zero).      |\n"
                    //                 "|___________________________________________________________|\n"
                    //                 " " << endl;
                    //     }else{                            
                    //         prod *= ((double)(j - 2)) / (2.0 * x + 3.0 * j);                            
                    //     }
                    // }
                    // // Here must be such a cycle working with a compicated formula and checking if there is division by zero,       
                    // // but if parameter n >=2 (it must always be equal or more than 2 according to condition!), the part (j-2)/(2*x + 3*j) 
                    // // always turns zero ("j" starts from 1 and always increases to 2, so j-2==2-2==0 and 0/(2*x + 3*j)==0), 
                    // // so we can just calculate 4*x - 0
                    
                    res = 4.0*x - prod;
                    cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n";
                    cout << "| If x" << counter << " = " << x << ", y = " << fixed << setprecision(5) << res << endl;
                    cout << "|____________________________________|\n" 
                            " " << endl;
                }
            
                x += step;
        }while (x <= xN);
        
        choice = subMenu();
    
    return choice;

    } while (choice == 0);

}

int aboutAuthor(){
    int choice = 0;
    do{
        cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n"
                "|                          ---- ABOUT AUTHOR INFO ----                            |\n"
                "|_________________________________________________________________________________|\n"
                "| The author of this application is a 17 y.o. student of National Technical       |\n"
                "| University «Kharkiv Politechnical Institute» majoring in «Software Engineering».|\n"
                "| He created this program in Septemper 2025, during the execution of laboratory   |\n"
                "| works from the discipline «Fundamentals of Software Engineering».               |\n"
                "|_________________________________________________________________________________|\n"
                " " << endl;
            
        choice = subMenu();
        return choice;

    } while (choice == 0);   
}

int documentation(){
    int choice = 0;
    do{
        cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n"
                "|                          ---- SYSTEM DOCUMENTATION ----                             |\n"
                "|_____________________________________________________________________________________|\n"
                "| Generally, this algorithm works as follows:                                         |\n"
                "| Firsly, the user inputs “x1”, “xN”, “step” and “n” in the input fields.             |\n"
                "| Then, there are some checks, where the program shows the error message, if the      |\n" 
                "| entered data is not right. If everything is good, it checks if x < 1 or x ≥ 1. In   |\n" 
                "| the first case, the program uses the formula from the top of the system, and start  |\n"
                "| 2 cycles (inner with J, and outer with I), where the value of “j” and “i” increases |\n"
                "| by 1 on each iteration, till j > n+1 (for the inner cycle), and i > n (for the      |\n"
                "| outer). When “i” comes bigger than “n”, the program shows the value of function on  |\n"
                "| the screen. In the case when x ≥ 1, it goes on another branch, and does the common  |\n"
                "| manipulations with the formula from the bottom.                                     |\n"
                "| There we have only one cycle – with production, that repeats until j > n. However,  |\n"
                "| if parameter n >=2 (it must always be equal or more than 2 by the condition), the   |\n"
                "| part (j-2)/(2*x + 3*j) always turns zero ('j' starts from 1 and always increases to |\n"
                "| 2, so j-2==0 and 0/(2*x + 3*j)==0), so we just calculate 4*x - 0.                   |\n"
                "|_____________________________________________________________________________________|\n"
                " " << endl;

        choice = subMenu();
        return choice;

    } while (choice == 0);
}

int faq(){
    int choice = 0;
    do{

        cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n" 
                "|              ---- FREQUENTLY ASKED QUESTIONS ----                 |\n" 
                "|___________________________________________________________________|\n" 
                "| Q1: What does this program do ?                                   |\n" 
                "|  -Answer: The program calculates the value of a given math        |\n" 
                "|   expression using the numbers x₁, xn, «step» and «n».            |\n" 
                "|-------------------------------------------------------------------|\n"
                "| Q2: What happens if letters or symbols entered instead of numbers?|\n" 
                "|  -Answer: The program will show an error message, so you should   |\n"  
                "|   launch it again.                                                |\n" 
                "|-------------------------------------------------------------------|\n"
                "| Q3: What happens if I enter a negative «n» ?                      |\n"
                "|  -Answer: Negative «n» is not allowed. The program will show an   |\n" 
                "|   error.                                                          |\n"
                "|-------------------------------------------------------------------|\n"
                "| Q4: What is the range of acceptable values for x₁, xn, and «step»?|\n" 
                "|  -Answer: they must be Real numbers from the range (-∞ ; +∞).     |\n" 
                "|-------------------------------------------------------------------|\n"
                "| Q5: What is the range of acceptable values for «n» ?              |\n" 
                "|  -Answer: «n» must be an integer number from the range [2 ; +∞).  |\n" 
                "|___________________________________________________________________|\n" 
                " " << endl;

        choice = subMenu();
        return choice;

    } while (choice == 0);   
}

void exitScreen(){
    cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n" 
            "|                   Good Bye!                   |\n" 
            "|_______________________________________________|\n" 
            " " << endl;
}

int main(){
    int state = 0;
    do{
        int choice;
        int option;
        choice = mainScreen();
        if(choice == 1){
            option = calculator();
            if (option == 2){
                exitScreen();
                state = 1;
            }
        }else if (choice == 2){
            option = aboutAuthor();
            if (option == 2){
                exitScreen();
                state = 1;
            }
        } else if(choice == 3){
            option = faq();
            if (option == 2){
                exitScreen();
                state = 1;
            }
        } else if (choice == 4){
            option = documentation();
            if (option == 2){
                exitScreen();
                state = 1;
            }
        } else if(choice == 5){
            exitScreen();
            state = 1;
        } else{
            cout << "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|\n"
                    "|              Error: There is no such option.              |\n"
                    "|___________________________________________________________|\n"
                    " " << endl;     
        }
    } while (state == 0);
    return 0;
}