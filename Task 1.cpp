#include "iostream"
#include "string"
using namespace std;

class MarkerPen
{
    public:
    string brand;
    string color;
    int inkLevel;
    bool refillability;
    
    void write(MarkerPen MPS[], int i);
    void refill(MarkerPen MPS[], int i);
    void status(MarkerPen MPS[], int num);
};

void status(MarkerPen MPS[], int num)
{
    cout << "Displaying the status for all markers" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "Brand : " << MPS[i].brand << endl; 
        cout << "Color : " << MPS[i].color << endl; 
        cout << "Ink Level : " << MPS[i].inkLevel << endl; 
    }
}

void refill(MarkerPen MPS[], int i)
{
    MPS[i-1].inkLevel = 10;
    cout << "Marker refilled" << endl;
}

void write(MarkerPen MPS[], int i)
{
    if (MPS[i-1].inkLevel == 0)
    {
        cout << "The ink level for this marker is insufficient, preparing to refill" << endl;
        refill(MPS, i);
    }
    else
    {
        MPS[i-1].inkLevel = MPS[i-1].inkLevel - 1;
        cout << "Marker used for writing, ink level reduced by 1" << endl;
    }
}

int main()
{
    int num;
    cout << "How many Marker pens do you have at your disposal?" << endl;
    cin >> num;
    
    MarkerPen MPS[num];
    
    cin.ignore(); 
    
    for (int i = 0; i < num; i++)
    {
        cout << "Enter details for marker " << i+1 << endl;
        cout << "Brand : ";
        getline(cin, MPS[i].brand);
        cout << "Color : ";
        getline(cin, MPS[i].color);
        cout << "Ink level (1-10) : ";
        do
        {
            cin >> MPS[i].inkLevel;
            if (MPS[i].inkLevel < 1 || MPS[i].inkLevel > 10)
            {
                cout << "Not a valid option" << endl;
            }
        }
        while (MPS[i].inkLevel < 1 || MPS[i].inkLevel > 10);
        
        if (MPS[i].inkLevel < 10)
        {
            MPS[i].refillability = true;
        }
        else
        {
            MPS[i].refillability = false;
        }

        cin.ignore(); 
    }
    
    int choice = 0;
    
    while (choice != 3)
    {
        cout << "What would you like to do?" << endl;
        cout << "1) Write" << endl << "2) Check status" << endl << "3) Exit" << endl;
        
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                int marker = 0; 
                cout << "Please choose which marker you would like to write with : (1-" << num << ")" << endl;
                while (marker < 1 || marker > num)
                {
                    cin >> marker;
                    if (marker < 1 || marker > num)
                    {
                        cout << "Not a valid option" << endl;
                    }
                }
                write(MPS, marker);
                break;
            }
            
            case 2:
            {
                status(MPS, num);
                break;
            }
            
            case 3:
            {
                cout << "Exiting program" << endl;
                break;
            }
            
            default:
            {
                cout << "Enter a valid option" << endl;
                break;
            }
        }
    }
    
    return 0;
}
