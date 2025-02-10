#include "iostream"
#include "string"
using namespace std;

class TeaMug
{
    public:
    string brand;
    string color;
    int capacity;
    int currentFillLevel;

    void sip(TeaMug mugs[], int i);
    void refill(TeaMug mugs[], int i);
    void status(TeaMug mugs[], int num);
};

void status(TeaMug mugs[], int num)
{
    cout << "Displaying the status for all tea mugs" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "Brand : " << mugs[i].brand << endl; 
        cout << "Color : " << mugs[i].color << endl; 
        cout << "Capacity : " << mugs[i].capacity << " ml" << endl;
        cout << "Current Fill Level : " << mugs[i].currentFillLevel << " ml" << endl;
    }
}

void refill(TeaMug mugs[], int i)
{
    mugs[i-1].currentFillLevel = mugs[i-1].capacity;
    cout << "Tea mug refilled to full capacity" << endl;
}

void sip(TeaMug mugs[], int i)
{
    if (mugs[i-1].currentFillLevel == 0)
    {
        cout << "The mug is empty! Time for a refill." << endl;
        refill(mugs, i);
    }
    else
    {
        mugs[i-1].currentFillLevel -= 50; // Assume each sip reduces 50ml
        if (mugs[i-1].currentFillLevel < 0)
        {
            mugs[i-1].currentFillLevel = 0;
        }
        cout << "Took a sip of tea, current fill level reduced." << endl;
    }
}

int main()
{
    int num;
    cout << "How many tea mugs do you have?" << endl;
    cin >> num;
    
    TeaMug mugs[num];
    
    cin.ignore(); 
    
    for (int i = 0; i < num; i++)
    {
        cout << "Enter details for tea mug " << i+1 << endl;
        cout << "Brand : ";
        getline(cin, mugs[i].brand);
        cout << "Color : ";
        getline(cin, mugs[i].color);
        cout << "Capacity (in ml) : ";
        cin >> mugs[i].capacity;
        
        cout << "Current Fill Level (in ml) : ";
        do
        {
            cin >> mugs[i].currentFillLevel;
            if (mugs[i].currentFillLevel < 0 || mugs[i].currentFillLevel > mugs[i].capacity)
            {
                cout << "Not a valid option" << endl;
            }
        }
        while (mugs[i].currentFillLevel < 0 || mugs[i].currentFillLevel > mugs[i].capacity);
        
        cin.ignore();
    }
    
    int choice = 0;
    
    while (choice != 3)
    {
        cout << "What would you like to do?" << endl;
        cout << "1) Sip Tea" << endl << "2) Check status" << endl << "3) Exit" << endl;
        
        cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                int mug = 0;
                cout << "Please choose which tea mug you want to sip from: (1-" << num << ")" << endl;
                while (mug < 1 || mug > num)
                {
                    cin >> mug;
                    if (mug < 1 || mug > num)
                    {
                        cout << "Not a valid option" << endl;
                    }
                }
                sip(mugs, mug);
                break;
            }
            
            case 2:
            {
                status(mugs, num);
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
