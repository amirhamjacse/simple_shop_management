#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Class to store item details
class Item {
public:
    string name;
    double price;
    int quantity;
};

// Function to display the item details
void displayItems(const vector<Item>& items) {
    cout << "Items available:" << endl;
    cout << setw(15) << "Item" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    for (const Item& item : items) {
        cout << setw(15) << item.name << setw(10) << item.price << setw(10) << item.quantity << endl;
    }
}

// Function to calculate and display the total price
double calculateTotal(const vector<Item>& items, const vector<int>& quantities) {
    double total = 0.0;
    cout << "\nItems selected:" << endl;
    cout << setw(15) << "Item" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        if (quantities[i] > 0) {
            cout << setw(15) << items[i].name << setw(10) << quantities[i] << setw(10) << items[i].price * quantities[i] << endl;
            total += items[i].price * quantities[i];
        }
    }
    return total;
}

int main() {
    vector<Item> items;
    vector<int> quantities;

    // Shopkeeper adds items
    cout << "Shopkeeper, enter item details (enter 'exit' for item name to stop):" << endl;
    while (true) {
        Item item;
        cout << "Item Name: ";
        getline(cin, item.name);

        if (item.name == "exit") {
            break;
        }

        cout << "Item Price: ";
        cin >> item.price;

        cout << "Item Quantity: ";
        cin >> item.quantity;

        cin.ignore(); // Clear the input buffer
        items.push_back(item);
        quantities.push_back(0);
    }

    // Buyer views items
    displayItems(items);

    // Buyer chooses items
    cout << "\nBuyer, enter the quantity of each item you want to purchase (enter 0 for items you don't want):" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << items[i].name << ": ";
        cin >> quantities[i];
    }

    // Calculate and display the total price
    double total = calculateTotal(items, quantities);
    cout << "\nTotal Price: " << total << endl;

    return 0;
}
