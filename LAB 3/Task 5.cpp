#include "iostream"
using namespace std;

class GroceryStore 
{
public:
    float price; 

    static void addItem(GroceryStore items[], int& Count, int num) 
    {
        if (Count >= num) 
        {
            cout << "Inventory is full, no more items can be added" << endl;
            return;
        }

        cout << "Enter the price for item " << Count + 1 << ": ";
        cin >> items[Count].price;
        cout << "Item " << Count + 1 << " added with price $" << items[Count].price << endl;
        Count++;
    }

    static void updatePrice(GroceryStore items[], int Count) 
    {
        if (Count == 0) 
        {
            cout << "No items in inventory to update" << endl;
            return;
        }

        int itemNumber;
        do {
            cout << "Enter item number (1-" << Count << ") to update price: ";
            cin >> itemNumber;
            if (itemNumber < 1 || itemNumber > Count) 
            {
                cout << "Invalid item number" << endl;
            }
        } while (itemNumber < 1 || itemNumber > Count);

        cout << "Enter new price for item " << itemNumber << ": ";
        cin >> items[itemNumber - 1].price;
        cout << "Price updated successfully" << endl;
    }

    static void viewInventory(GroceryStore items[], int Count) 
    {
        if (Count == 0) 
        {
            cout << "No items in inventory" << endl;
            return;
        }

        cout << "Inventory List: " << endl; 
        for (int i = 0; i < Count; i++) 
        {
            cout << "Item " << i + 1 << ": $" << items[i].price << endl;
        }
    }

    static void generateReceipt(GroceryStore items[], int Count) 
    {
        if (Count == 0) 
        {
            cout << "No items in inventory to generate receipt" << endl;
            return;
        }

        int quantity;
        double total = 0;
        cout << "Receipt: " << endl;
        for (int i = 0; i < Count; i++) 
        {
            cout << "Enter quantity for Item " << i + 1 << ": ";
            cin >> quantity;
            total = total + (quantity * items[i].price);
            cout << "Item " << i + 1 << ": $" << items[i].price << " x " << quantity << " = $" << quantity * items[i].price << endl;
        }
        cout << "Total Amount: $" << total << endl;
    }
};

int main() 
{
    int num;
    cout << "Enter the maximum number of items in the grocery store: ";
    cin >> num;

    GroceryStore items[num]; 
    int Count = 0; 

    int choice;
    do {
        cout << "What would you like to do?" << endl;
        cout << "1) Add an item" << endl << "2) Update price of an item" << endl << "3) View inventory" << endl << "4) Generate receipt" << endl << "5) Exit" << endl;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                GroceryStore::addItem(items, Count, num);
                break;
            case 2:
                GroceryStore::updatePrice(items, Count);
                break;
            case 3:
                GroceryStore::viewInventory(items, Count);
                break;
            case 4:
                GroceryStore::generateReceipt(items, Count);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, try again" << endl;
        }
    } while (choice != 5);

    return 0;
}
