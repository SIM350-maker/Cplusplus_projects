#include<iostream>
#include<vector>
using namespace std;

class Item {

  public:
  int id;
  string name;
  int quantity;
  double price;

  Item(int i, string n, int q, double p){
    id = i;
    name = n;
    quantity = q;
    price = p;
    }
  };

  class Inventory{
    private:
      vector<Item>items;

      public:
      void addItem(int id, string name, int quantity, double price){
        items.push_back(Item(id, name, quantity, price));
        cout<<"Item added to successfully!\n;";
      }

      void displayItems(){
        if(items.empty()){
          cout<<"No items available.\n";
          return;
        }

        cout<<"\nInventory List.\n";
        for(const auto& item : items){
          cout<<"ID:"<<item.id<<", Name:"<<item.name<<", Quantity:"<<item.quantity<<", Price: $"<<item.price<<endl;
        }
      }

      void searchItem(int id){
        for (const auto& item : items){
          if(item.id == id){
            cout <<"Item Found ID:"<<item.id <<", Name:"<<item.name<<", Quantity:"<<item.quantity<<", Price: $"<<item.price<<endl;
            return;
      }
    }
    cout<<"Item not found.\n";
  }

  void updateItem(int id, string newName, int newQuantity, double newPrice){
    for (auto& item : items){
      if(item.id == id){
        item.name = newName;
        item.quantity = newQuantity;
        item.price = newPrice;
        cout<<"Item Updated successfully!\n";
        return;
      }
    }
    cout<<"Item not found.\n";
  }

  void deleteItem(int id){
    for (size_t i = 0; i < items.size(); i++)
    {
      if(items[i].id == id){
        items.erase(items.begin() + i);
        cout<<"Item deleted successfully!\n";
        return;
      }
    }
    cout<<"Item not found.\n";
  }
};

int main(){
  Inventory inv;
  int choice;

  while(true){
    cout<<"\n Inventory Management system \n";
    cout<<"1. Add Item\n2. View items\n3. Search Item\n4. Update Item\n5. Delete item\n6. Exit\n";
    cout<<"Enter choice:";
    cin>>choice;

    if(choice==1){
      int id, quantity;
      string name;
      double price;
      cout<<"Enter item ID:";
      cin>>id;
      cout<<"Enter Name:";
      cin.ignore();
      getline(cin, name);
      cout<<"Enter quantity:";
      cin>>quantity;
      cout<<"Enter price:";
      cin>>price;
      inv.addItem(id, name, quantity, price);
    }
    else if(choice == 2){
      inv.displayItems();
    }
    else if(choice == 3){
      int id;
      cout<<"Enter item ID to search:";
      cin>>id;
      inv.searchItem(id);
  }
  else if(choice == 4){
    int id, newQuantity;
    string newName;
    double newPrice;
    cout<<"Enter Item ID to update:";
    cin>>id;
    cout<<"Enter new Name:";
    cin.ignore();
    getline(cin, newName);
    cout<<"Enter new Quantity:";
    cin>>newQuantity;
    cout<<"Enter new Price:";
    cin>>newPrice;
    inv.updateItem(id, newName, newQuantity, newPrice);
  }
  else if(choice == 5){
    int id;
    cout<<"Enter Item ID to delete:";
    cin>>id;
    inv.deleteItem(id);
  }
  else if (choice == 6)
  {
    cout<<"xisting program...\n";
    break;
  }
  else{
    cout<<"Invalid choice, try again.\n";
  }
}
return 0;
}
    


  