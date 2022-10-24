#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Ol7V3R{

private:

    //login form
   string username, password; //this is sensitive data, therefore its private.

   unsigned int choice; //unsigned int = positive integers only


public:

//login form
void setUsername(string sUsername){ //When setting we pass a parameter.


                username = sUsername;

    }

    string getUsername(){ //When getting we return private member.

            return username;
    }


    void setPassword(string sPassword){ //When setting we pass a parameter.

        password = sPassword;

    }

    string getPassword(){ //When getting we return private member.

    return password;

    }


 //Constructor
    Ol7V3R(){ //This will we called when creating class object.

        //declaring 'title' string variable
        string title;

        //defining 'title' variable
        title = "Welcome to 0l7V3R!";

        //prints out 'title'
        cout << title << endl;

    }

    void loginForm(){


    //menu
    cout << "0: Exit\n"
                "1: Login\n"
                "2: Register\n";

                    //user inputs a choice
                    cout << "Enter a choice: ";
                    cin >> choice;

                  //decision making with if-else-if statements
                  if (choice == 0 ){

                    //Will print if user inputs 0
                    cout << "\n\tThank you for using 0l7V3R! \n\t Have a wonderful day :)\n";


                  }

                  else if(choice == 1){

                    system("cls"); //clears console


                    //variables used to verify 'username' & 'password'
                    string us, pa;

                    //user inputs username
                    cout << "Enter username: ";
                    cin >> username;

                    //user inputs password
                    cout << "Enter password: ";
                    cin >> password;

                    //ifstream reads given file
                    ifstream read(username + " .txt");
                    //format: ifstream objName (filename);

                    getline(read, us); //stores first line into 'us'
                    getline(read, pa); //stores second line into 'pa'

                    if (username == us && password == pa && read.is_open()){ //checks if inputted 'username' & 'password' is equal to 'us' & 'pa'

                            system("cls"); //clears console

                            cout << "Congrats you have logged in successfully!" << endl;

                            cout << "File Open: " << read.is_open(); //prints out if file is opened. returns 1/0;

                            read.close(); //IMPORTANT to close file, if opened.

                            system("cls");
                            cout << "Welcome " + username + " to 0l7V3R!" << endl; //Introduction
                            cout << "uLength: " + to_string(username.length()) << endl; //number of characters on 'username'
                            cout << "Initial:";cout<< username[0]; //initials

                            menuList();




                    }

                    else if (username != us  || password != pa){

                        cout << "Login information incorrect! please try again." << endl;
                    }



                  }


                  else if (choice == 2){

                    //user inputs username
                    cout << "Enter username: ";
                    cin >> username;

                    //user inputs password
                    cout << "Enter password: ";
                    cin >> password;

                    //creating file
                    ofstream file; //calling the object file

                    file.open(username + " .txt"); //open
                    file << username << endl << password; //write
                    file.close(); //close

                    system("cls");

                    loginForm(); //restarts

                  }

                  else{

                    system("cls");
                    loginForm(); //restarts

                  }


    }

    void menuList(){

        //variable declaration
        unsigned int menuChoice;

        //menu
        cout << "\n0: Exit\n"
                      "1: Currency Converter\n"
                      "2: Digital Calculator\n"
                      "3: TicTacToe\n"
                      "4: Student Management\n"
                      "5: Address Handbook\n"
                      "6: Snake Game\n";

                      //user inputs a choice
                      cout << "Enter a choice: ";
                      cin >> menuChoice;

                      //decision making with switch statements
                      switch(menuChoice){

                      case 0:

                        cout << "\n\tThank you for using 0l7V3R! \n\t Have a wonderful day :)\n";
                        exit(0);


                        break;

                      case 1:

                          system("cls");
                          CurrencyConverter();

                        break;

                      case 2:

                          system("cls");
                          DigitalCalculator();

                        break;

                      case 3:

                        system("cls");
                        TicTacToe();

                        break;

                      case 4:

                          system("cls");
                          StudentManagement();
                        break;

                      case 5:

                          system("cls");
                          AddressHandbook();

                        break;

                      default:

                          system("cls");

                          cout << "Please enter the correct choice!" << endl;

                          menuList(); //restarts

                        break;

                      }

    }

    void CurrencyConverter(){

    restart:

    cout << "Welcome to the Currency Converter!" << endl;

    //variable declaration
    long double currency, total;
    //currency has coins, therefore double.

    int choiceConverter;


    //user enters amount in USD
    cout << "Enter USD amount (Enter -1 to exit): $";
    cin >> currency;
    cin.ignore();

    if (currency == -1){

        system("cls");

        cout << "Welcome " + username + " to 0l7V3R!" << endl; //Introduction
        cout << "uLength: " + to_string(username.length()) << endl; //number of characters on 'username'
        cout << "Initial:";cout<< username[0]; //initials
        menuList();

    }


    //options
    cout << "\nConvert to:\n"
                  "1: EURO\n"
                  "2: CAD\n"
                  "3: ARG\n"
                  "4: GBP\n";

                  //user enters choice
                  cout << "Enter a choice: ";
                  cin >> choiceConverter;

                  //decision making
                  switch(choiceConverter){

              case 1:

                //formula
               total = currency * 0.86;

                //display
                cout << "\nUSD: $" << currency;
                cout << "\nEURO: �" << total << endl << endl;

                //revert back to zero to avoid any overlapping.
                currency = 0;
                total = 0;

                goto restart;


                break;

              case 2:

                //formula
                total = currency * 1.2472104;

                //display
                cout << "\nUSD: $" << currency;
                cout << "\nCAD: C$" << total << endl << endl;

                //revert back to zero to avoid any overlapping.
                currency = 0;
                total = 0;

                goto restart;

                break;

              case 3:

                //formula
                total = currency * 98.960887;

                //display
                cout << "\nUSD: $" << currency;
                cout << "\nARG: A$" << total << endl << endl;

                //revert back to zero to avoid any overlapping.
                currency = 0;
                total = 0;

                //restarts method
                goto restart;

                break;

                case 4:

                //formula
                total = currency * 0.7346;

                //display
                cout << "\nUSD: $" << currency;
                cout << "\nGBP: �" << total << endl << endl;

                //revert back to zero to avoid any overlapping.
                currency = 0;
                total = 0;

                goto restart;

                break;

                default:

                    cout << "Please try again!" << endl;

                    system("cls");
                    goto restart; //restarts

                    break;

                  }

    }

    void DigitalCalculator(){

        int calculatorChoice;

        //declaring
         int firstNum, secondNum, thirdNum;

         double total;

        //defining
        firstNum = 0;
        secondNum = 0;
        thirdNum = 0;

        cout << "Welcome " << getUsername() << " to Digital Calculator v1.0!" << endl;

        restart:

        cout << "0: Menu\n"
                    "1: Arithmetic\n"
                    "2: Geometric\n";

                    cout << "Enter a choice: ";
                    cin >> calculatorChoice;
                    cin.ignore();

                    switch(calculatorChoice){

                case 1:

                    system("cls");
                    cout << "0: Menu" << endl;
                    cout << "1: Addition" << endl;
                    cout << "2: Subtraction" << endl;
                    cout << "3: Multiplication" << endl;
                    cout << "4: Division" << endl;
                    cout << "5: Modulus" << endl;

                    int calculatorChoice2;

                    cout << "Enter a choice: ";
                    cin >> calculatorChoice2;

                    switch(calculatorChoice2){

            case 0:

                system("cls");
                menuList ();

                break;


                case 1:

                   cout << "Enter the first number: ";
                   cin >> firstNum;

                   cout << "Enter the second number: ";
                   cin >> secondNum;

                  total = (double)firstNum +  (double)secondNum;

                  cout << firstNum << " + " << secondNum << " = " << total << endl << endl;


                  //restart
                  goto restart;




                    break;

                case 2:

                   cout << "Enter the first number: ";
                   cin >> firstNum;

                   cout << "Enter the second number: ";
                   cin >> secondNum;

                  total = (double)firstNum - (double)secondNum;

                  cout << firstNum << " - " << secondNum << " = " << total << endl << endl;


                  //restart
                  goto restart;

                    break;

                case 3:

                cout << "Enter the first number: ";
                   cin >> firstNum;

                   cout << "Enter the second number: ";
                   cin >> secondNum;

                  total = (double)firstNum * (double)secondNum;

                  cout << firstNum << " * " << secondNum << " = " << total << endl << endl;


                  //restart
                  goto restart;


                    break;

                case 4:

                cout << "Enter the first number: ";
                   cin >> firstNum;

                   cout << "Enter the second number: ";
                   cin >> secondNum;

                  total = (double)firstNum * (double)secondNum;

                  cout << firstNum << " * " << secondNum << " = " << total << endl << endl;


                  //restart
                  goto restart;


                    break;



                    }

                    break;


                    }


    }

    void drawBoard(){


        int choice1,choice2;

        int board[3][3] ={{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

                                  //references

                                  int one = board[0][0];
                                  int two = board[0][1];
                                  int three = board[0][2];
                                  int four = board[1][0];
                                  int five = board[1][1];
                                  int six = board[1][2];
                                  int seven = board[2][0];
                                  int eight = board[2][1];
                                  int nine = board[2][2];

                                  cout << one << " | " << two << " | " << three << endl;
                                  cout << "__________" << endl;
                                  cout << four << " | " << five << " | " << six << endl;
                                  cout << "__________" << endl;
                                  cout << seven << " | " << eight << " | " << nine << endl;

                                  cout << "Player 1, enter a choice: ";
                                      cin >> choice1;





    }

    void TicTacToe(){




        drawBoard();

    }

    void StudentManagement(){

    system("cls");

    //declaring variable
    int studentChoice, numberOfStudents = 1, numberOfClasses = 0, studentAge, howManyStudents;

    string studentCourse, studentName;

    //arrays

    //title
    cout << "Welcome " << getUsername() + " to Student Managment!" << endl;

    //menu

    cout << "How many students are in total: ";
    cin >> numberOfStudents;


    string groupStudents[numberOfStudents];

    int groupStudentsAge[numberOfStudents];

    string groupCourses[numberOfStudents];

    system("cls");

    menu:

    cout << "0: Back to Menu\n"
                  "1: Add Student\n"
                  "2: Delete Student\n"
                  "3: Add Class\n"
                  "4: Delete Class\n"
                  "5: View Student & Class List\n";

                    //user inputs a choice
                  cout << "Enter a choice: ";
                  cin >> studentChoice;

        switch(studentChoice){

    case 0:

        system("cls");
        menuList();

        break;

    case 1:

        system("cls");

        cout << "How many students would you like to add: ";
        cin >> howManyStudents;

        for (int i =0; i < howManyStudents; i++){

            cout << "Enter the students name: ";
            cin >> studentName;

            cout << "Enter the student's age: ";
            cin >> studentAge;

            cout << "Enter the student's Major: ";
            cin >> studentCourse;

            groupStudents[i] = studentName;
            groupStudentsAge[i] = studentAge;
            groupCourses[i] = studentCourse;

            cout << "" << endl;

            cout << "groupStudents[" << i << "]: "  << groupStudents[i] << endl;
            cout << "groupStudentsAge[" << i << "]: "  << groupStudentsAge[i] << endl;
            cout << "groupCourses[" << i << "]: "  << groupCourses[i] << endl;

            cout << "" << endl;

            numberOfStudents += howManyStudents;

            }

            goto menu;

        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:

        for(int i = 0; i < numberOfStudents; i++){


        cout << i + 1 << ". " << "Student's Name[" << i << "]: "  << groupStudents[i] << endl;
        cout << "Student's Age[" << i << "]: "  << groupStudentsAge[i] << endl;
        cout << "Student's Major[" << i << "]: "  << groupCourses[i] << endl;

        cout << "" << endl;

        }

        break;

    default:
        break;

        }

    }

    void AddressHandbook(){

    }

    };

    int main(){

    //class object
    Ol7V3R myClass;

    //calls loginForm function
    myClass.loginForm();


    return 0;

    }


