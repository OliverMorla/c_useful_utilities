#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <string.h>

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
                      "2: Student Management\n";

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
                          StudentManagement();

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

void StudentManagement(){
        // Considering the max length of data entered (name) to
    // be 15.
    char data[15];
    int n = 0, option = 0, count_n = 0;
    // This is the initial mark alloted to a subject.
    string empty = "00";
    string proctor = "";
    // Name of the file in which DB is stored.
    ifstream f("Example.txt");
    string line;

    // The following for loop counts the total number of
    // lines in the file.
    for (int i = 0; std::getline(f, line); ++i) {
        count_n++;
    }

    while (option != 6) {
        // This prints out all the available options in the
        // DB
        cout << "Available operations: \n1. Add New "
                "Students\n2."
             << "Student Login\n3. Faculty Login\n4. "
                "Proctor Login\n5. Admin View\n"
             << "6. Exit\nEnter option: ";
        cin >> option;

        if (option == 1) {
            cout << "Enter the number of students: ";
            cin >> n;

            count_n = count_n + n;

            for (int i = 0; i < n; i++) {
                ofstream outfile;
                outfile.open("Example.txt", ios::app);
                // The entire data of a single student is
                // stored line-by-line.
                cout << "Enter your registration number: ";
                cin >> data;
                outfile << data << "\t";

                cout << "Enter your name: ";
                cin >> data;
                int len = strlen(data);

                while (len < 15) {
                    data[len] = ' ';
                    len = len + 1;
                }
                outfile << data << "\t";
                // Inserting empty data initially into the
                // file
                outfile << empty << "\t";
                outfile << empty << "\t";

                cout << "Enter your proctor ID: ";
                cin >> proctor;

                outfile << proctor << endl;
            }
        }

        else if (option == 2) {
            char regno[9];
            cout << "Enter your registration number: ";
            cin >> regno;
            ifstream infile;
            int check = 0;
            infile.open("Example.txt", ios::in);

            // This loop prints out the data according to
            // the registration number specified.
            while (infile >> data) {
                if (strcmp(data, regno) == 0) {
                    cout
                        << "\nRegistration Number: " << data
                        << endl;
                    infile >> data;
                    cout << "Name: " << data << endl;

                    infile >> data;
                    cout << "CSE1001 mark: " << data
                         << endl;

                    infile >> data;
                    cout << "CSE1002 mark: " << data
                         << endl;

                    infile >> data;
                    cout << "Proctor ID: " << data << endl;

                    infile.close();
                    check = 1;
                }
            }

            if (check == 0) {
                cout << "No such registration number found!"
                     << endl;
            }
        }

        // This loop is used to view and add marks to the
        // database of a student.
        else if (option == 3) {
            char subcode[7];
            cout << "Enter your subject code: ";
            cin >> subcode;
            string code1 = "CSE1001", code2 = "CSE1002",
                   mark = "";
            ifstream infile;
            int check = 0;

            cout << "\nAvailable operations: \n1. Add data "
                    "about marks\n"
                 << "2. View data\nEnter option: ";
            cin >> option;

            if (option == 1) {
                cout
                    << "Warning! You would need to add mark"
                    << "details for all the students!"
                    << endl;
                for (int i = 0; i < count_n; i++) {
                    fstream file("Example.txt");

                    // The seek in file has been done
                    // according to the length
                    // of the data being inserted. It needs
                    // to adjusted accordingly for different
                    // lengths of data.

                    if (strcmp(subcode, code1.c_str())
                        == 0) {
                        file.seekp(26 + 37 * i,
                                   std::ios_base::beg);
                        cout << "Enter the mark of student#"
                             << (i + 1) << " : ";
                        cin >> mark;
                        file.write(mark.c_str(), 2);
                    }

                    if (strcmp(subcode, code2.c_str())
                        == 0) {
                        file.seekp(29 + 37 * i,
                                   std::ios_base::beg);
                        cout << "Enter the mark of student#"
                             << (i + 1) << " : ";
                        cin >> mark;
                        file.write(mark.c_str(), 2);
                    }
                }
            }

            // This loop is used to view marks of a student.
            // The extra infile commands have been used to
            // get a specific mark only since the data has
            // been separated by a tabspace.

            else if (option == 2) {
                infile.open("Example.txt", ios::in);
                if (strcmp(subcode, code1.c_str()) == 0) {
                    cout << "Registration number - Marks\n"
                         << endl;
                    while (infile >> data) {
                        cout << data;
                        infile >> data;
                        infile >> data;
                        cout << " - " << data << endl;
                        infile >> data;
                        infile >> data;
                        check = 1;
                    }
                }

                infile.close();
                infile.open("Example.txt", ios::in);

                if (strcmp(subcode, code2.c_str()) == 0) {
                    cout << "Registration number - Marks\n"
                         << endl;
                    while (infile >> data) {
                        cout << data;
                        infile >> data;
                        infile >> data;
                        infile >> data;
                        cout << " - " << data << endl;
                        infile >> data;
                        check = 1;
                    }
                }
            }

            infile.close();

            if (check == 0) {
                cout << "No such subject code found!"
                     << endl;
            }
        }

        // This loop displays all the details of students
        // under the same proctor ID.

        else if (option == 4) {
            char procid[7];
            cout << "Enter your proctor ID: ";
            cin >> procid;
            int check = 0;
            char temp1[100], temp2[100], temp3[100];
            char temp4[100], id[100];
            ifstream infile;
            infile.open("Example.txt", ios::in);

            while (infile >> temp1) {
                infile >> temp2;
                infile >> temp3;
                infile >> temp4;
                infile >> id;

                if (strcmp(id, procid) == 0) {
                    cout << "\nRegistration Number: "
                         << temp1 << endl;
                    cout << "Name: " << temp2 << endl;
                    cout << "CSE1001 Mark: " << temp3
                         << endl;
                    cout << "CSE1002 Mark: " << temp4
                         << endl;
                    check = 1;
                }
            }

            if (check == 0) {
                cout << "No such proctor ID found!" << endl;
            }
        }

        // This loop acts as an admin view to see all the
        // data in the file.

        else if (option == 5) {
            char password[25];
            cout << "Enter the admin password: ";
            cin >> password;

            // This variable value can be changed according
            // to your requirement of the administrator
            // password.

            string admin_pass = "admin";

            if (strcmp(password, admin_pass.c_str()) == 0) {
                cout << "Reg No.       "
                        "\tName\tCSE1001\tCSE1002\tProctor "
                        "ID"
                     << endl;
                ifstream infile;
                infile.open("Example.txt", ios::in);
                char data[20];

                while (infile >> data) {
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << "\t";
                    infile >> data;
                    cout << data << endl;
                }
            }
        }
    }
}

};
    int main(){

    //class object
    Ol7V3R myClass;

    //calls loginForm function
    myClass.loginForm();


    return 0;

    }


