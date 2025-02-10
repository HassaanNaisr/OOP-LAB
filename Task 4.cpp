#include <iostream>
#include <string>
using namespace std;

class Laptop 
{
    private:
        string brand;
        string model;
        string processor;
        int RAM;
        int storage;
        bool isOn;

    public:
        Laptop() : isOn(false) {}

        void inputSpecs() 
        {
            cout << "Enter Brand: ";
            cin >> brand;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Processor: ";
            cin.ignore();
            getline(cin, processor);
            cout << "Enter RAM (GB): ";
            cin >> RAM;
            cout << "Enter Storage (GB): ";
            cin >> storage;
        }

        void displaySpecs() 
        {
            cout << "Brand: " << brand << endl << "Model: " << model <<
            endl << "Processor: " << processor << endl << "RAM: " << RAM
             << endl << "Storage(GB): " << storage << "GB" << endl;
        }

        bool isBetterThan(Laptop laptop1) 
        {
            if (RAM > laptop1.RAM)
            {
                return true;
            }
            else if(RAM == laptop1.RAM)
            {
                if (storage > laptop1.storage)
                {
                    return true;
                }
                else 
                {
                    return false;
                }
            }
            else 
            {
                return false;
            }
            
        }
};

int main() 
{
    Laptop Bilal, Ayesha;

    cout << "Bilal enter your laptop details: " << endl;
    Bilal.inputSpecs();
    cout << endl;

    cout << "Ayesha enter your laptop details: " << endl;
    Ayesha.inputSpecs();
    cout << endl;

    cout << "Bilal's Laptop Specs: " << endl;
    Bilal.displaySpecs();
    cout << "Ayesha's Laptop Specs: " << endl;
    Ayesha.displaySpecs();
    cout << endl;

    cout << "Comparing Laptops" << endl;
    if (Bilal.isBetterThan(Ayesha)) 
    {
        cout << "Bilals laptop is better" << endl;;
    } 
    else
    {
        cout << "Ayeshas laptop is better" << endl;
    }

    return 0;
}
