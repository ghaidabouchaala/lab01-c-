#define MODE 2

#include <iostream>
#include <array_list.h>
#include <fstream>
using namespace std;

#if MODE == 1 
void main() {
    // The basic test Program
    ssuds::ArrayList test;
    test.append("Bob");
    test.append("Carl");
    cout << test.size() << endl; // 2
    cout << test.get(0) << endl; // Bob
    cout << test.get(1) << endl; // Carl
    test.insert("Abe", 0); // ["Abe", "Bob", "Carl"]
    test.insert("Josh", 2); // ["Abe", "Bob", "Josh", "Carl"]
    cout << test.find("Carl", 2) << endl; // 3
    cout << test.find("Bob") << endl; // 1
    test.insert("Abe", 2); // ["Abe", "Bob", "Abe", "Josh", "Carl"]
    test.remove(3); // ["Abe", "Bob",  "Abe", "Carl"]
    test.remove_all("Abe"); // 2
    test.list(); // ["Bob", "Carl"]

    // Raise of exceptions
    cout << "Raising exceptions" << endl;
    try {
        test.insert("Justin", 5);
    }
    catch (out_of_range& e) {
        cerr << e.what() << endl;
    }
    try {
        cout << "printing element  "<< test.get(6) << endl;
    }
    catch (out_of_range& e) {
        cerr << e.what() << endl;
    }

    try {
        test.remove(8);
    }
    catch (out_of_range& e) {
        cerr << e.what() << endl;
    }

}
#else
int main()
{

    ssuds::ArrayList test;

    ifstream myfile;
    myfile.open("../Debug/file.txt");
    string line;
    if (myfile.is_open()) {
        while (myfile) {
            getline(myfile, line);
            test.append(line);
            if (myfile.eof())
                break;
        }
        myfile.close();
    }
    else {
        cout << "Couldn't open file\n";
    }

    char choice; 
    do 
    {
        cout << "\nPlease select one of the following options:  \n"
            "0- append     | 1- size   | 2- list                  \n"
            "3- insert     | 4- clear  | 5- get                   \n"
            "6- find       | 7- remove | 8- remove_all | 9- exit \n";
        cout << "Enter your selection   \n";
        cin >> choice;
        switch (choice)
        {
            case '0':
            {   
                cout << "Enter the string you want to append " << endl;
                string value;
                cin >> value;
                test.append(value);
                test.list();
                break;
            }
            case '1':
                cout << "The size of the array is " << test.size() << endl;
                break;
            case '2':
                cout << "All array elements " << endl;
                test.list();
                break;
            case '3':
            {
                cout << "Enter the string you want to insert " << endl;
                string value;
                cin >> value;
                cout << "Enter the position of the string you want to insert " << endl;
                int pos;
                cin >> pos;
                test.insert(value,pos);
                test.list();
                break;
            }
            case '4':
            {
                cout << "Array Cleared " << endl;
                test.clear();
                break;
            }
            case '5':
            {
                cout << "Enter the position of the string you want to get " << endl;
                int pos;
                cin >> pos;
                cout << test.get(pos) << endl;
                break;
            }
            case '6':
            {
                cout << "Enter the string you want to find " << endl;
                string value;
                cin >> value;
                cout << "Enter the position from where you want to start looking " << endl;
                int pos;
                cin >> pos;
                if (test.find(value, pos) != -1)
                    cout << "The position of the string you're looking for is : " << test.find(value, pos) << endl;
                else
                    cout << "Cannot find your string in the array " << endl;
                break;
            }
            case '7':
            {
                cout << "Enter the position of the element you want to remove " << endl;
                int pos;
                cin >> pos;
                test.remove(pos);
                test.list();
                break;
            }
            case '8':
            {
                cout << "Enter the string you want to remove all of its occurrences " << endl;
                string value;
                cin >> value;
                cout << "The number of instances removed " << test.remove_all(value) << endl;
                test.list();
                break;
            }
            case '9':
            {
                int array_size = test.size();
                ofstream myfile("../Debug/file.txt", ios::trunc);
                if (myfile.is_open())
                {
                    for (int i = 0; i < array_size; i++) {
                        myfile << test.get(i);
                        if (i < array_size - 1)
                            myfile << '\n';
                    }
                    myfile.close();
                }
                else cout << "Unable to open file";
                cout << "You have chosen Exit, Goodbye." << endl;
                break;
            }
            default:
            {
                cout << "You must enter an integer " << endl;
                break;
            }
        }
    }while (choice!='9' );

    

    return 0;
}
#endif

