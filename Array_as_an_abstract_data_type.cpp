#include <bits/stdc++.h>
using namespace std;

class Array_as_ADTs
{
private:
    int Total_Space;
    int used_Space;
    int *ptr;

public:
    Array_as_ADTs(int total, int used)
    {
        Total_Space = total;
        used_Space = used;
        ptr = new int[Total_Space * sizeof(int)]; // The Array of the given Size is intialized etc:-
        Total_Space = Total_Space - used_Space;
    }
    void creation_of_Array();             // done
    void display_the_Array();             // done
    void insertion_at_front();            // done
    void insertion_at_rear();             // done
    void insertion_at_a_given_Position(); // done
    void deletion_at_Front();             // done
    void deletion_at_rear();              // done
    void deletion_at_a_given_value();     // done
    void deletion_at_a_given_Position();  // done
    void memory_Description();            // done
};

void Array_as_ADTs::deletion_at_a_given_Position()
{
    int position;
    cout << "Enter the Position from where you want to Perform the deletion:- ";
    cin >> position;
    for (int i = position-1; i < used_Space; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    used_Space -= 1;
    Total_Space += 1;
}

void Array_as_ADTs::deletion_at_a_given_value()
{
    int value, position = 0;
    bool flag = false;
    cout << "Enter the value which you want to delete in the given Array:- ";
    cin >> value;
    for (int i = 0; i < used_Space; i++)
    {
        if (ptr[i] == value)
        {
            position = i;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        for (int i = position; i < used_Space; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        used_Space -= 1;
        Total_Space += 1;
    }
    else
    {
        cout << "The value is not Available in the Given Array" << endl;
    }
}

void Array_as_ADTs::memory_Description()
{
    cout << "The available Space is :- " << Total_Space << endl;
    cout << "The Space Used is :- " << used_Space << endl;
}

void Array_as_ADTs::deletion_at_rear()
{
    used_Space -= 1;
    Total_Space += 1;
}

void Array_as_ADTs::deletion_at_Front()
{
    for (int i = 0; i < used_Space; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    used_Space -= 1;
    Total_Space += 1;
}

void Array_as_ADTs::creation_of_Array()
{
    for (int i = 0; i < used_Space; i++)
    {
        cout << "Enter the Value at the position " << i + 1 << " :- ";
        cin >> ptr[i];
    }
}
void Array_as_ADTs::display_the_Array()
{
    cout << "The Values in the Given Array is :- ";
    for (int i = 0; i < used_Space; i++)
    {
        cout << ptr[i];
        if (i == used_Space - 1)
        {
            cout << " ";
        }
        else
        {
            cout << ",";
        }
    }
    cout << endl;
}

void Array_as_ADTs::insertion_at_front()
{
    int value;
    cout << "Enter the value which you want to insert at the Front:- ";
    cin >> value;
    used_Space += 1;
    Total_Space -= 1; // for updating the total Space.
    for (int i = used_Space - 1; i >= 0; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[0] = value;
}

void Array_as_ADTs::insertion_at_rear()
{
    int value;
    cout << "Enter the value which you want to insert at the rear Position:- ";
    cin >> value;
    used_Space += 1;
    Total_Space -= 1;
    ptr[used_Space - 1] = value;
}

void Array_as_ADTs::insertion_at_a_given_Position()
{
    int value, position;
    cout << "Enter the Position where you want to insert the value :-";
    cin >> position;
    cout << "Enter the value which you want to insert at the given position:- ";
    cin >> value;
    used_Space += 1;
    Total_Space -= 1;
    for (int i = used_Space; i >= position - 1; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[position - 1] = value;
}

int main()
{
    int choice, total, used;
    cout << "Enter the total Number of Space Which you want to Allocate for the given Array:- ";
    cin >> total;
    cout << "Enter the Space Which you want to used for the Given Array:- ";
    cin >> used;

    Array_as_ADTs obj(total, used);
    do
    {
        cout << "1. Enter the number in the dynamic Array" << endl;
        cout << "2. Display the Given Array and the Size used for the Array" << endl;
        cout << "3. Perform insertion in the given Position" << endl;
        cout << "4. Perform insetion in the Front" << endl;
        cout << "5. Perform Insertion in the Rear" << endl;
        cout << "6. Perform Deletion of a Given value" << endl;
        cout << "7. Perform Deletion at the given Position in the Array" << endl;
        cout << "8. Perform Deletion at the Front" << endl;
        cout << "9. Perform Deletion at the rear of the array" << endl;
        cout << "10.Show the Description of the Usage of the Memory" << endl;
        cout << "11. Exit" << endl;
        cout << endl;
        cout << "Enter your choice:- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            obj.creation_of_Array();
            break;
        }
        case 2:
        {
            obj.display_the_Array();
            break;
        }
        case 3:
        {
            obj.insertion_at_a_given_Position();
            break;
        }
        case 4:
        {
            obj.insertion_at_front();
            break;
        }
        case 5:
        {
            obj.insertion_at_rear();
            break;
        }
        case 6:
        {
            obj.deletion_at_a_given_value();
            break;
        }
        case 7:
        {
            obj.deletion_at_a_given_Position();
            break;
        }
        case 8:
        {
            obj.deletion_at_Front();
            break;
        }
        case 9:
        {
            obj.deletion_at_rear();
            break;
        }
        case 10:
        {
            obj.memory_Description();
            break;
        }
        case 11:
        {

            break;
        }

        default:
            cout << "WRONG CHOICE !!!!!!!!!!!!!!!!" << endl;
            break;
        }
    } while (choice != 11);

    return 0;
}