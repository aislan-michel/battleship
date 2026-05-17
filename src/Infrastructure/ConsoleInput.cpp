#include "ConsoleInput.h"

#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

void clear_input()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool read_int(const string& label, int& value)
{
    cout << label;

    if(cin >> value)
    {
        return true;
    }

    if(cin.eof())
    {
        cout << "\nInput finished.\n" << endl;
        exit(0);
    }

    clear_input();
    cout << "\nInvalid value. Type a number.\n" << endl;

    return false;
}

CoordinateInput read_coordinate(const string& label, int& coordinate)
{
    string value;

    cout << label;
    if(!(cin >> value))
    {
        return CoordinateInput::Quit;
    }

    if(value == "q" || value == "Q")
    {
        return CoordinateInput::Quit;
    }

    try
    {
        coordinate = stoi(value);
    }
    catch(...)
    {
        cout << "\nInvalid value. Type a number from 0 to 9, or q to quit.\n" << endl;
        return CoordinateInput::Invalid;
    }

    return CoordinateInput::Value;
}
