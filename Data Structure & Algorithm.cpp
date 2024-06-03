#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Node structure for the tree
struct TreeNode {
    string Name;
    int Price;
    int Stock;
    TreeNode* LeftChild;   // Pointer to the leftmost child
    TreeNode* RightSibling; // Pointer to the right sibling

    // TreeNode() : Price(NULL), Stock(NULL) {}
};

//Untuk WriteIntoFile dan AddNewItem
int I_Parent_t, I_Stock_t, I_Price_t;
string S_Name_t;



TreeNode Member[70]; //array menu
TreeNode Member1[500]; //array event

TreeNode* AddMember(int index, string name, int stock, int price)
{
    Member[index].Name = name;
    Member[index].Stock = stock;
    Member[index].Price = price;
    Member[index].LeftChild = Member[index].RightSibling = nullptr;
    return &Member[index];
}

TreeNode* AddSibling(TreeNode* n, int index, string name, int stock, int price)
{
    if (n == nullptr)
        return nullptr;
    
    while (n->RightSibling)
        n = n->RightSibling;
    
    return (n->RightSibling = AddMember(index, name, stock, price));
}

TreeNode* AddChild(TreeNode* n, int index, string name, int stock, int price)
{
    if (n == nullptr)
        return nullptr;

    if (n->LeftChild)
        return AddSibling(n->LeftChild, index, name, stock, price);
    else
        return (n->LeftChild = AddMember(index, name, stock, price));
}

/*
    Mekanismenya adalah di dalam program ini terdapat root yaitu "DataBase Menu".
    Ia memiliki 3 child yaitu untuk 3 kategori menu (Makanan-Utama, Minuman, Roti-dan-Kue)
    Setiap member dari kategori akan ditampilkan dan jika ada penambahan kategori, maka
    akan ditampilkan sibling dari category sebelahnya.
*/

//Fungsi untuk traverse root (menampilkan keseluruhan tree menu)
void traverseTree(TreeNode* root, int depth = 0)
{
    for (int i = 0; i < depth; i++)
        cout << "   ";
    
    if (root->Stock > 0 && root->Price > 0)
    {
        cout << root->Name << " - " << root->Stock << " - " << root->Price << endl;
    }
    else
        cout << root->Name << endl;
    

    TreeNode* currentChild = root->LeftChild;
    while (currentChild != nullptr)
    {
        traverseTree(currentChild, depth + 1);
        currentChild = currentChild->RightSibling;
    }

}

//Pengisian menu
void InsertAll()
{
    
    AddChild(&Member[1], 4, "Viennoiseries", 0, -2);
    AddChild(&Member[1], 5, "Pastry", 0, -2);
    AddChild(&Member[1], 6, "Bread", 0, -2);
    AddChild(&Member[1], 7, "Bun", 0, -2);

    AddChild(&Member[2], 8, "Juice", 0, -2);
    AddChild(&Member[2], 9, "Tea", 0, -2);
    AddChild(&Member[2], 10, "Coffee", 0, -2);

    AddChild(&Member[3], 11, "Salad", 0, -2);
    AddChild(&Member[3], 12, "Soup", 0, -2);
    AddChild(&Member[3], 13, "Sandwich", 0, -2);
    AddChild(&Member[3], 14, "Pasta", 0, -2);

    // Adding items
    AddChild(&Member[4], 15, "Croissant", 10, 25000);
    AddChild(&Member[4], 16, "Pain-au-Chocolat", 10, 18000);
    AddChild(&Member[4], 17, "Brioche", 10, 20000);

    AddChild(&Member[5], 18, "Eclair", 10, 22000);
    AddChild(&Member[5], 19, "Mille-feuille", 10, 30000);
    AddChild(&Member[5], 20, "Tarte-Tatin", 10, 35000);
    AddChild(&Member[5], 21, "Tartlet", 10, 25000);

    AddChild(&Member[6], 22, "Baguette", 10, 18000);
    AddChild(&Member[6], 23, "Sourdough", 10, 22000);
    AddChild(&Member[6], 24, "Brioche-Long", 10, 25000);

    AddChild(&Member[7], 25, "Bagel", 10, 20000);
    AddChild(&Member[7], 26, "Burger", 10, 25000);
    AddChild(&Member[7], 27, "Hotdog", 10, 20000);

    AddChild(&Member[8], 28, "Apple-Juice", 10, 15000);
    AddChild(&Member[8], 29, "Orange-Juice", 10, 16000);
    AddChild(&Member[8], 30, "Strawberry-Juice", 10, 18000);

    AddChild(&Member[9], 31, "Earl-Grey", 10, 12000);
    AddChild(&Member[9], 32, "Chamomile", 10, 13000);
    AddChild(&Member[9], 33, "English-Breakfast", 10, 14000);
    AddChild(&Member[9], 34, "Darjeeling", 10, 15000);
    AddChild(&Member[9], 35, "Oolong", 10, 16000);
    AddChild(&Member[9], 36, "Matcha", 10, 20000);
    AddChild(&Member[9], 37, "Jasmine", 10, 17000);

    AddChild(&Member[10], 38, "Long-Black", 10, 18000);
    AddChild(&Member[10], 39, "Cappuccino", 10, 22000);
    AddChild(&Member[10], 40, "Latte", 10, 23000);
    AddChild(&Member[10], 41, "Espresso", 10, 20000);
    AddChild(&Member[10], 42, "Macchiato", 10, 21000);
    AddChild(&Member[10], 43, "Piccolo", 10, 24000);

    AddChild(&Member[11], 44, "Caesar-Salad", 10, 25000);
    AddChild(&Member[11], 45, "Caprese-Salad", 10, 20000);
    AddChild(&Member[11], 46, "Waldorf-Salad", 10, 22000);
    AddChild(&Member[11], 47, "Nicoise-Salad", 10, 25000);

    AddChild(&Member[12], 48, "Pumpkin-Soup", 10, 18000);
    AddChild(&Member[12], 49, "Mushroom-Soup", 10, 19000);
    AddChild(&Member[12], 50, "Corn-Soup", 10, 17000);

    AddChild(&Member[13], 51, "Club-Sandwich", 10, 22000);
    AddChild(&Member[13], 52, "Tuna-Sandwich", 10, 20000);

    AddChild(&Member[14], 53, "Gnocchi", 10, 25000);
    AddChild(&Member[14], 54, "Aglio-e-Olio", 10, 23000);
    AddChild(&Member[14], 55, "Lasagna", 10, 28000);
    AddChild(&Member[14], 56, "Fettuccine", 10, 22000);
    AddChild(&Member[14], 57, "Carbonara", 10, 24000);
}

//Untuk keperluan checking
int currentmember;
int nextAvailableIndex = 58;

void CheckValue(TreeNode Member[]) {
    for (int i = 0; i < 70; i++) {
        if (Member[i].Name.empty() && Member[i].LeftChild == nullptr && Member[i].RightSibling == nullptr) {
            currentmember = i;
            if (currentmember < 70) {
                nextAvailableIndex++;
            } 
            return;
        }
    }
    currentmember = nextAvailableIndex;
    nextAvailableIndex++;
}

TreeNode* findNode(TreeNode* root, string& targetName) 
{
    if (root->Name == targetName) 
    {
        return root;
    }

    TreeNode* currentChild = root->LeftChild;
    while (currentChild != nullptr) 
    {
        TreeNode* result = findNode(currentChild, targetName);
        if (result)
            return result;
        currentChild = currentChild->RightSibling;
    }

    return nullptr;
}
bool validInput;

//0 - 57 already filled, 58 - 69 empty

//Fungsi menambahkan kategori baru
void AddCategory(TreeNode* root, string Name)
{
    //Kondisi jika kategori yang dimasukkan berupa string kosong
    if (Name.empty()) {
        cout << "---Warning---" << endl;
        cout << "Name of category can't be empty. Please insert string." << endl << endl;
        return;
    }

    //Kondisi jika kategori yang dimasukkan sudah ada
    TreeNode* category = findNode(root,Name);
    if(category != nullptr) {
        cout << "---Warning---" << endl;
        cout << "Category "<< Name <<  " already exists." << endl << endl;
        return;
    }

    //Menambahkan kategori baru
    CheckValue(Member);
    if (currentmember >= 70)
    {
        cout << "!! Array is Full !! You can't add more category" << endl << endl;
    }
    else
    {
        //cout << currentmember << " Pass add" << endl;
        AddChild(root, currentmember, Name, 0, -1);
        nextAvailableIndex++;
    }
        
    // CheckValue(Member);
}

//Fungsi menambahkan subkategori baru
void AddSubCategory(TreeNode* root, int Parent, string Name)
{
    
    ERR:
    
    //Menanyakan kepada user, parent/kategori mana yang ingin ditambahkan subkategori
    cout << endl << "Insert index of category" << endl;
    for (int i = 1; i <= 69; i++)
    {
        if (Member[i].Price == -1 && Member[i].Stock == 0 && !Member[i].Name.empty())
            cout << Member[i].Name << ", index: " << i << endl;
    }
    cout << "Input: ";
    cin >> Parent;

    //Memvalidasi input untuk memastikan kategori yang dipilih adalah valid
    validInput = false;
    for (int i = 1; i <= 69; i++) 
    {
        if (Member[i].Price == -1 && Member[i].Stock == 0 && !Member[i].Name.empty() && Parent == i) 
        {
            validInput = true;
            break;
        }
    }

    //Jika input tidak valid, maka akan looping
    if (!validInput)
        goto ERR;

    //Memeriksa apakah subkategori dengan nama yang sama sudah ada
    TreeNode* parentNode = &Member[Parent];
    TreeNode* existingSubcategory = findNode(parentNode, Name);
    if (existingSubcategory) {
        cout << endl << Name << " already exist. Please insert another subcategory name." << endl << endl;
        return;
    }

    //Memeriksa apakah masih ada ruang untuk menambahkan subkategori
    CheckValue(Member);
    if (currentmember >= 70) {
        cout << endl << "---Warning---" << endl;
        cout << "!! Array is Full !!" << endl << endl;
    } else {
        AddChild(&Member[Parent], currentmember, Name, 0, -2);
    }
    CheckValue(Member);
}

//Fungsi menambahkan item baru
void AddNewItem(TreeNode* root, int Parent, string Name, int Stock, int Price) //nambah item
{
    ERR:
    if (Price <= 0)
    {
        cout << "PRICE ERROR" << endl;
        return;
    }
    
    //Menanyakan kepada user indeks subkategori yang ingin ditambah itemnya
    cout << endl << "Insert index of subcategory" << endl;
    for (int i = 1; i <= 69; i++)
    {
        if (Member[i].Price == -2 && Member[i].Stock == 0 && !Member[i].Name.empty())
            cout << Member[i].Name << ", index: " << i << endl;
    }
    cout << "Input: ";
    cin >> Parent;
    validInput = false;
    for (int i = 1; i <= 69; i++) 
    {
        if (Member[i].Price == -2 && Member[i].Stock == 0 && !Member[i].Name.empty() && Parent == i) 
        {
            validInput = true;
            break;
        }
    }
    //Jika input tidak valid, program akan looping
    if (!validInput)
        goto ERR;
    
    TreeNode* parentNode = &Member[Parent];
    TreeNode* existingSubcategory = findNode(parentNode, Name);
    if (existingSubcategory) {
        cout << endl << Name << " already exist. Please insert another item name." << endl << endl;
        return;
    }
    
    //Memeriksa apakah masih ada ruang untuk menambahkan item
    CheckValue(Member); 
    if (currentmember >= 70) {
        cout << endl << "---Warning---" << endl;
        cout << "!! Array is Full !!" << endl << endl;
    } else {
        AddChild(&Member[Parent], currentmember, Name, Stock, Price);
    }
    CheckValue(Member);
}

// Untuk menghapus node
bool deleteNode(TreeNode* root, string& targetName) 
{
    TreeNode* parent = nullptr;
    TreeNode* currentChild = root->LeftChild;

    while (currentChild != nullptr && currentChild->Name != targetName) 
    {
        parent = currentChild;
        currentChild = currentChild->RightSibling;
    }

    if (currentChild && currentChild->Name == targetName) 
    {
        if (parent) 
            parent->RightSibling = currentChild->RightSibling;
        else
            root->LeftChild = currentChild->RightSibling;

        delete currentChild;
        return true;
    }

    return false;
}

//Fungsi menghapus kategori
bool deleteCategory(TreeNode* root, string categoryName) 
{
    if (deleteNode(root, categoryName)) 
    {
        
        cout << categoryName << " Deleted" << endl;
        return true;
    } 
    else
    {
        cout << "Category not found: " << categoryName << endl;
        return false;
    }
}

//Fungsi menghapus subkategori
bool deleteSubCategory(TreeNode* root, string parentCategory, string subCategoryName)
{
    TreeNode* parentNode = findNode(root, parentCategory);

    if (parentNode)
    {
        if (deleteNode(parentNode, subCategoryName))
        {
            cout << subCategoryName << " Deleted" << endl;
            return true;
        }
        else
        {
            cout << "Subcategory not found, failed to delete" << endl;
            return false;
        }
    }
    else
    {
        cout << "Invalid parent category: " << parentCategory << endl;
        return false;
    }
}

//Fungsi menghapus item
bool deleteItem(TreeNode* root, string parentCategory, string itemName) 
{
    TreeNode* parentNode = findNode(root, parentCategory);

    if (parentNode && parentNode->LeftChild) 
    {
        if (deleteNode(parentNode, itemName)) 
        {
            cout << itemName << " Deleted" << endl;
            return true;
        } 
        else 
        {
            cout << "Item not found, failed to delete" << endl;
            return false;
        }
    }
    else
    {
        cout << "Invalid parent category: " << parentCategory << endl;
        return false;
    }
}

//Fungsi mengedit(mengubah nama) kategori
void EditCategory(TreeNode* root, string OldName, string NewName)
{
    //Pengecekan kondisi apakah kategori lama ada di data menu
    TreeNode* category = findNode(root, OldName);
    if (category == nullptr) {
        cout << "---Warning---" << endl;
        cout << "Category " << OldName << " doesn't exist." << endl << endl;
        return;
    }

    //Pengecekan kondisi apakah nama kategori baru ada di data menu
    TreeNode* existing = findNode(root, NewName);
    if(existing != nullptr) {
        cout << "---Warning---" << endl;
        cout << "Category " << NewName << " exist or name of category used by another." << endl << endl;
        return;
    }

    //Edit nama kategori
    for (int i = 0; i < 70; i++)
    {
        if (Member[i].Price == -1 && Member[i].Name == OldName)
        {
            Member[i].Name = NewName;
            break;
        }
    }
}

//Fungsi mengedit (mengubah nama) subkategori
void EditSub(TreeNode* root, string OldName, string NewName)
{
    //Pengecekan kondisi apakah subkategori lama ada di data menu
    TreeNode* subcategory = findNode(root, OldName);
    if (subcategory == nullptr) {
        cout << "---Warning---" << endl;
        cout << "SubCategory " << OldName << " doesn't exist." << endl << endl;
        return;
    }

    //Pengecekan kondisi apakah nama subkategori baru ada di data menu
    TreeNode* existing = findNode(root, NewName);
    if(existing != nullptr) {
        cout << "---Warning---" << endl;
        cout << "SubCategory " << NewName << " exist. Please insert new name." << endl << endl;
        return;
    }

    // TreeNode* TargetNode = nullptr;
    for (int i = 1; i < 70; i++)
    {
        if (Member[i].Price == -2 && Member[i].Name == OldName)
        {
            Member[i].Name = NewName;
            break;
        }
    }
}

//Fungsi mengedit (mengubah nama dan keterangan) dalam item
void EditItem(TreeNode* root, string OldName, string NewName, int NewStock, int NewPrice)
{
    //Pengecekan kondisi apakah item lama ada di data menu
    TreeNode* item = findNode(root, OldName);
    if (item == nullptr) {
        cout << "---Warning---" << endl;
        cout << "Item " << OldName << " doesn't exist." << endl << endl;
        return;
    }

    if (NewPrice <= 0)
    {
        cout << "PRICE ERROR" << endl;
        return;
    }
    for (int i = 0; i < 70; i++)
    {
        if (Member[i].Name == OldName)
        {
            Member[i].Name = NewName;
            Member[i].Stock = NewStock;
            Member[i].Price = NewPrice;
            break;
        }
    }
}

//Fungsi mencari kategori, subkategori atau item
void ItemSearch(TreeNode* root, string name)
{
    for (int i = 0; i < 70; i++)
    {
        if (Member[i].Name == name)
        {
            if (Member[i].Price == -2 || Member[i].Price == -1)
            {
                cout << "Found! " << endl;
                cout << Member[i].Name << endl;
            }
            else
            {
                cout << "Found! " << endl;
                cout << Member[i].Name << " - " << Member[i].Stock << " - " << Member[i].Price << endl;
            }    
        }
    }
}


const string PaymentMethod[4] = {"MoePay", "Debit", "Credit", "Cash"};

struct Promotion
{
    bool Status;
    int StartDate, StartMonth, StartYear;
    int EndDate, EndMonth, EndYear;
    int PromotionType;
    string PMethod; 
    int MinimumPayment;
    string Product;
    string Benefit;

};
const int numberOfPromotions = 3;
Promotion promotions[numberOfPromotions];
int Total, disc;

//Fungsi menambahkan promosi baru
void AddPromotion (bool status, 
                   int startDate, int startMonth, int startYear,
                   int endDate, int endMonth, int endYear, 
                   int type, int paymenttype, int minimumpayment, string benefit, string product)
{
    if(endYear < startYear) {
    cout << "Error: End date cannot be earlier than start date!" << endl; 
    return;
  }
  if(endYear == startYear && endMonth < startMonth) {
    cout << "Error: End date cannot be earlier than start date!" << endl;
    return; 
  }
  if(endYear == startYear && endMonth == startMonth  
            && endDate < startDate) {
    cout << "Error: End date cannot be earlier than start date!" << endl;
    return;
  }
    for (int i = 0; i < numberOfPromotions; i++)
    {
        if (!promotions[i].Status)
        {
            promotions[i].Status = status;
            promotions[i].StartDate = startDate;
            promotions[i].StartMonth = startMonth;
            promotions[i].StartYear = startYear;
            promotions[i].EndDate = endDate;
            promotions[i].EndMonth = endMonth;
            promotions[i].EndYear = endYear;
            promotions[i].Benefit = benefit;
            promotions[i].PromotionType = type;
            promotions[i].PMethod = PaymentMethod[paymenttype];
            promotions[i].MinimumPayment = minimumpayment;
            promotions[i].Product = product;
            
            

            cout << endl << "Promotion added." << endl;
            return;
        }
    }

    cout << endl << "---Warning---" << endl;
    cout << "!! Array Promotion is Full !!" << endl << endl;
}

void EditPromotion(int selectedpromotion, bool status, 
                   int startDate, int startMonth, int startYear,
                   int endDate, int endMonth, int endYear, 
                   int type, int paymenttype, int minimumpayment, string benefit, string product)
{

    if (promotions[selectedpromotion-1].Status == NULL)
    {
        cout << "Error: No promotions exist yet!" << endl;
        return;
    }

    if (endYear < startYear || (endYear == startYear && endMonth < startMonth) || (endYear == startYear && endMonth == startMonth && endDate < startDate))
    {
        cout << "Error: End date is earlier than start date!" << endl;
        return;
    }

    promotions[selectedpromotion-1].Status = status;
    promotions[selectedpromotion-1].StartDate = startDate;
    promotions[selectedpromotion-1].StartMonth = startMonth;
    promotions[selectedpromotion-1].StartYear = startYear;
    promotions[selectedpromotion-1].EndDate = endDate;
    promotions[selectedpromotion-1].EndMonth = endMonth;
    promotions[selectedpromotion-1].EndYear = endYear;
    promotions[selectedpromotion-1].Benefit = benefit;
    promotions[selectedpromotion-1].PromotionType = type;
    promotions[selectedpromotion-1].PMethod = PaymentMethod[paymenttype];
    promotions[selectedpromotion-1].MinimumPayment = minimumpayment;
    promotions[selectedpromotion-1].Product = product;

    cout << "Promotion edited." << endl;
}

void DeletePromotion(int selectedpromotion)
{
    if (selectedpromotion <= 0 || selectedpromotion > numberOfPromotions)
        return;

    if (promotions[selectedpromotion-1].Status == NULL)
        return;
    promotions[selectedpromotion-1].Status = false;

    cout << "Promotion " << selectedpromotion << " deleted." << endl;
}


void DisplayPromotions()
{
    for (int i = 0; i < numberOfPromotions; i++)
    {
        if (promotions[i].Status)
        {
            cout << "Promotion Type: ";
            switch (promotions[i].PromotionType)
            {
            case 1:
                cout << "Discount" << endl;
                break;
            
            case 2:
                cout << "Free Item" << endl;
                break;

            default:
                break;
            }
            cout << "Status: " << (promotions[i].Status ? "Active" : "Inactive") << endl;
            cout << "Start Date: " << promotions[i].StartDate << "/" << promotions[i].StartMonth << "/" << promotions[i].StartYear << endl;
            cout << "End Date: " << promotions[i].EndDate << "/" << promotions[i].EndMonth << "/" << promotions[i].EndYear << endl;
            cout << "Terms and Condition: " << endl;
            cout << "1. Payment method: " << promotions[i].PMethod << endl;
            cout << "2. Minimum payment: " << promotions[i].MinimumPayment << endl;
            cout << "3. Product: " << promotions[i].Product << endl;
            cout << "Benefit: " << promotions[i].Benefit << endl;
            cout << "------------------------" << endl;
        }
    }
}


void ApplyPromotion(int CurrentDate, int CurrentMonth, int CurrentYear, int TotalPrice, int paymentmethod, string product)
{
    for (int i = 0; i < 5; i++)
    {
        if (promotions[i].Status)
        {
            if ( (promotions[i].StartDate <= CurrentDate && promotions[i].StartMonth <= CurrentMonth && promotions[i].StartYear <= CurrentYear) &&
                 (promotions[i].EndDate >= CurrentDate && promotions[i].EndMonth >= CurrentMonth && promotions[i].EndYear >= CurrentYear) &&
                  promotions[i].MinimumPayment < TotalPrice && promotions[i].PMethod == PaymentMethod[paymentmethod] && promotions[i].Product == product )
            {
                cout << "You got a discount!" << endl;
                cout << "Yout benefit: " << promotions[i].Benefit;
                return;
            }
        }
    }
    cout << "No discount applied." << endl;
}

TreeNode *Event;

TreeNode *AddMember1(int index, string Name)
{
    Member1[index].Name = Name;
    Member1[index].LeftChild = Member1[index].RightSibling = nullptr;
    return &Member1[index];
}

TreeNode *AddSibling1(TreeNode *n, int index, string Name)
{
    if (n == nullptr)
        return nullptr;

    while (n->RightSibling)
        n = n->RightSibling;

    return (n->RightSibling = AddMember1(index, Name));
}

TreeNode *AddChild1(TreeNode *n, int index, string Name)
{
    if (n == nullptr)
        return nullptr;

    if (n->LeftChild)
        return AddSibling1(n->LeftChild, index, Name);
    else
        return (n->LeftChild = AddMember1(index, Name));
}

void CheckValue1(TreeNode Member1[])
{
    for (int i = 0; i < 499; i++)
    {
        if (Member1[i].Name.empty() && Member1[i].LeftChild == nullptr && Member1[i].RightSibling == nullptr)
        {
            currentmember = i;
            return;
        }
    }
    currentmember = nextAvailableIndex;
    nextAvailableIndex++;
}

TreeNode *findNode1(TreeNode *Event, string &targetName)
{
    if (Event->Name == targetName)
    {
        return Event;
    }

    TreeNode *currentChild = Event->LeftChild;
    while (currentChild != nullptr)
    {
        TreeNode *result = findNode1(currentChild, targetName);
        if (result)
            return result;
        currentChild = currentChild->RightSibling;
    }

    return nullptr;
}

void AddEvent(TreeNode* Event, string Name)
{
    //Kondisi jika kategori yang dimasukkan berupa string kosong
    if (Name.empty()) {
        cout << "---Warning---" << endl;
        cout << "Name of event can't be empty. Please insert string." << endl << endl;
        return;
    }

    //Kondisi jika kategori yang dimasukkan sudah ada
    TreeNode* event = findNode1(Event,Name);
    if(event != nullptr) {
        cout << "---Warning---" << endl;
        cout << "Event "<< Name <<  " already exists." << endl << endl;
        return;
    }

    //Menambahkan kategori baru
    CheckValue1(Member1);
    if (currentmember >= 499)
    {
        cout << "!! Array is Full !! You can't add more event" << endl << endl;
    }
    else
    {
        //cout << currentmember << " Pass add" << endl;
        AddChild1(Event, currentmember, Name);
        nextAvailableIndex++;
    }
        
    // CheckValue(Member);
}


void traverseTree1(TreeNode *Event, int depth = 0)
{
    for (int i = 0; i < depth; i++)
        cout << "   ";
    if (Event->Stock > 0 && Event->Price > 0)
    {
        cout << Event->Name << " - " << Event->Price << endl;
    }
    else
        cout << Event->Name << endl;

    TreeNode *currentChild = Event->LeftChild;
    while (currentChild != nullptr)
    {
        traverseTree1(currentChild, depth + 1);
        currentChild = currentChild->RightSibling;
    }
}


void eventfill(TreeNode *Event, int Child)
{
    string Name;
    int Price, Stock;
    int i;
    if (Child == 0)
    {
        return;
    }

    validInput = false;
    CheckValue1(Member1);
    if (currentmember > 499)
    {
        cout << "!! Array is Full !! You can't add more event" << endl;
    }
    else
    {
        AddChild1(Event, currentmember, Member[Child].Name);
    }
    CheckValue1(Member1);
    for (int i = 1; i <= 499; i++)
    {
        if (Member1[i].Price > 0 && Member1[i].Stock >= 0 && !Member1[i].Name.empty() && currentmember == i)
        {
            validInput = true;
            break;
        }
    }

    if (!validInput)
    {
        // cout << "Input Succeed" << endl;
    }

    // Print the event category
    // cout << Member1[currentmember].Name << endl;

    // Print items under the event category
    TreeNode *currentChild = Event->LeftChild;
    while (currentChild != nullptr)
    {
        // traverseTree1(currentChild, 1);
        currentChild = currentChild->RightSibling;
    }
}

void EditEvent(TreeNode *Event, string OldName, string NewName)
{
    TreeNode* event = findNode1(Event, OldName);
    if (event == nullptr) {
        cout << "---Warning---" << endl;
        cout << "Event " << OldName << " doesn't exist." << endl << endl;
        return;
    }
    for (int i = 0; i < 499; i++)
    {
        if (Member1[i].Name == OldName)
        {
            TreeNode* event = findNode1(Event, NewName);
            if(event != nullptr) {
                cout << "---Warning---" << endl;
                cout << "Event "<< NewName <<  " already exists." << endl << endl;
                return;
            }
            Member1[i].Name = NewName;
            break;
        }
    }

}

void EditfillEvent(TreeNode *Event, string OldName, string NewName)
{
    TreeNode* event = findNode1(Event, OldName);
    if (event == nullptr) {
        cout << "---Warning---" << endl;
        cout << "Item " << OldName << " doesn't exist." << endl << endl;
        return;
    }
    for (int i = 0; i < 499; i++)
    {
        if (Member1[i].Name == OldName)
        {
            TreeNode* event = findNode1(Event, NewName);
            if(event != nullptr) {
                cout << "---Warning---" << endl;
                cout << "Item "<< NewName <<  " already exists." << endl << endl;
                return;
            }
            Member1[i].Name = NewName;
            break;
        }
    }

}

void insertEvent()
{
    eventfill(&Member1[1], 51);
    eventfill(&Member1[1], 52);
    eventfill(&Member1[1], 22);
    eventfill(&Member1[1], 23);
    eventfill(&Member1[1], 24);
    eventfill(&Member1[1], 25);
    eventfill(&Member1[1], 26);
    eventfill(&Member1[1], 27);
    eventfill(&Member1[1], 28);
    eventfill(&Member1[1], 29);
    eventfill(&Member1[1], 30);
    eventfill(&Member1[1], 31);
    eventfill(&Member1[1], 32);
    eventfill(&Member1[1], 33);
    eventfill(&Member1[1], 34);
    eventfill(&Member1[1], 35);
    eventfill(&Member1[1], 36);
    eventfill(&Member1[1], 37);
    eventfill(&Member1[1], 38);
    eventfill(&Member1[1], 39);
    eventfill(&Member1[1], 40);
    eventfill(&Member1[1], 41);
    eventfill(&Member1[1], 42);
    eventfill(&Member1[1], 43);

    eventfill(&Member1[2], 51);
    eventfill(&Member1[2], 52);
    eventfill(&Member1[2], 22);
    eventfill(&Member1[2], 23);
    eventfill(&Member1[2], 24);
    eventfill(&Member1[2], 25);
    eventfill(&Member1[2], 26);
    eventfill(&Member1[2], 27);
    eventfill(&Member1[2], 44);
    eventfill(&Member1[2], 45);
    eventfill(&Member1[2], 46);
    eventfill(&Member1[2], 47);
    eventfill(&Member1[2], 48);
    eventfill(&Member1[2], 49);
    eventfill(&Member1[2], 50);
    eventfill(&Member1[2], 28);
    eventfill(&Member1[2], 29);
    eventfill(&Member1[2], 30);
    eventfill(&Member1[2], 31);
    eventfill(&Member1[2], 32);
    eventfill(&Member1[2], 33);
    eventfill(&Member1[2], 34);
    eventfill(&Member1[2], 35);
    eventfill(&Member1[2], 36);
    eventfill(&Member1[2], 37);
    eventfill(&Member1[2], 38);
    eventfill(&Member1[2], 39);
    eventfill(&Member1[2], 40);
    eventfill(&Member1[2], 41);
    eventfill(&Member1[2], 42);
    eventfill(&Member1[2], 43);

    eventfill(&Member1[3], 44);
    eventfill(&Member1[3], 45);
    eventfill(&Member1[3], 46);
    eventfill(&Member1[3], 47);
    eventfill(&Member1[3], 48);
    eventfill(&Member1[3], 49);
    eventfill(&Member1[3], 50);
    eventfill(&Member1[3], 51);
    eventfill(&Member1[3], 52);
    eventfill(&Member1[3], 53);
    eventfill(&Member1[3], 54);
    eventfill(&Member1[3], 55);
    eventfill(&Member1[3], 56);
    eventfill(&Member1[3], 57);
    eventfill(&Member1[3], 18);
    eventfill(&Member1[3], 19);
    eventfill(&Member1[3], 20);
    eventfill(&Member1[3], 21);
    eventfill(&Member1[3], 28);
    eventfill(&Member1[3], 29);
    eventfill(&Member1[3], 30);
    eventfill(&Member1[3], 31);
    eventfill(&Member1[3], 32);
    eventfill(&Member1[3], 33);
    eventfill(&Member1[3], 34);
    eventfill(&Member1[3], 35);
    eventfill(&Member1[3], 36);
    eventfill(&Member1[3], 37);
    eventfill(&Member1[3], 38);
    eventfill(&Member1[3], 39);
    eventfill(&Member1[3], 40);
    eventfill(&Member1[3], 41);
    eventfill(&Member1[3], 42);
    eventfill(&Member1[3], 43);

    eventfill(&Member1[4], 28);
    eventfill(&Member1[4], 29);
    eventfill(&Member1[4], 30);
    eventfill(&Member1[4], 31);
    eventfill(&Member1[4], 32);
    eventfill(&Member1[4], 33);
    eventfill(&Member1[4], 34);
    eventfill(&Member1[4], 35);
    eventfill(&Member1[4], 36);
    eventfill(&Member1[4], 37);
    eventfill(&Member1[4], 38);
    eventfill(&Member1[4], 39);
    eventfill(&Member1[4], 40);
    eventfill(&Member1[4], 41);
    eventfill(&Member1[4], 42);
    eventfill(&Member1[4], 43);
    eventfill(&Member1[4], 15);
    eventfill(&Member1[4], 16);
    eventfill(&Member1[4], 17);
    eventfill(&Member1[4], 18);
    eventfill(&Member1[4], 19);
    eventfill(&Member1[4], 20);
    eventfill(&Member1[4], 21);

    eventfill(&Member1[5], 44);
    eventfill(&Member1[5], 45);
    eventfill(&Member1[5], 46);
    eventfill(&Member1[5], 47);
    eventfill(&Member1[5], 48);
    eventfill(&Member1[5], 49);
    eventfill(&Member1[5], 50);
    eventfill(&Member1[5], 51);
    eventfill(&Member1[5], 52);
    eventfill(&Member1[5], 53);
    eventfill(&Member1[5], 54);
    eventfill(&Member1[5], 55);
    eventfill(&Member1[5], 56);
    eventfill(&Member1[5], 57);
    eventfill(&Member1[5], 18);
    eventfill(&Member1[5], 19);
    eventfill(&Member1[5], 20);
    eventfill(&Member1[5], 21);
    eventfill(&Member1[5], 28);
    eventfill(&Member1[5], 29);
    eventfill(&Member1[5], 30);
    eventfill(&Member1[5], 31);
    eventfill(&Member1[5], 32);
    eventfill(&Member1[5], 33);
    eventfill(&Member1[5], 34);
    eventfill(&Member1[5], 35);
    eventfill(&Member1[5], 36);
    eventfill(&Member1[5], 37);
    eventfill(&Member1[5], 38);
    eventfill(&Member1[5], 39);
    eventfill(&Member1[5], 40);
    eventfill(&Member1[5], 41);
    eventfill(&Member1[5], 42);
    eventfill(&Member1[5], 43);

}

void AddfillEvent(TreeNode *Event, int Child)
{
    string Name;
    int price, stock, Parent;
    int i;
    for (int i = 1; i <= 499; i++)
    {
        if (!Member1[i].Name.empty())
            cout << Member1[i].Name << ", index: " << i << endl;
    }
    cout << "Parent : ";
    cin >> Parent;
    for (int i = 1; i <= 69; i++)
    {
        if (Member[i].Price > 0 && Member[i].Stock >= 0 && !Member[i].Name.empty())
            cout << Member[i].Name << ", index: " << i << endl;
    }
    cout << "Child Index (enter 0 to finish): ";
    while (true)
    {
        cout << "Input: ";
        cin >> Child;

        if (Child == 0)
        {
            break;
        }

        validInput = false;
        CheckValue1(Member1);
        if (currentmember > 499)
        {
            cout << "Full" << endl;
        }
        else
        {
            AddChild1(&Member1[Parent], currentmember, Member[Child].Name);
        }
        CheckValue1(Member1);
        for (int i = 1; i <= 499; i++)
        {
            if (!Member1[i].Name.empty() && currentmember == i)
            {
                if (Member[i].Price > 0 && Member[i].Stock >= 0 && !Member[i].Name.empty() && Child == i)
                {
                    validInput = true;
                    break;
                }
            }
        }

        if (!validInput)
        {
            cout << "Input Succeed" << endl;
            continue;
        }

        // Print the event category
        // cout << Member1[currentmember].Name << endl;

        // Print items under the event category
        TreeNode *currentChild = Event->LeftChild;
        while (currentChild != nullptr)
        {
            traverseTree1(currentChild, 1);
            currentChild = currentChild->RightSibling;
        }
    }
}

bool deleteNode1(TreeNode *Event, string &targetName)
{
    TreeNode *parent = nullptr;
    TreeNode *currentChild = Event->LeftChild;

    while (currentChild != nullptr && currentChild->Name != targetName)
    {
        parent = currentChild;
        currentChild = currentChild->RightSibling;
    }

    if (currentChild && currentChild->Name == targetName)
    {
        if (parent){
            parent->RightSibling = currentChild->RightSibling;
    }
        else
            // Deleting the root node
            Event->LeftChild = currentChild->RightSibling;

        // delete currentChild;
        return true;
    }

    return false;
}

// delete cat
bool deleteEvent(TreeNode *Event, string targetName)
{
    if (deleteNode1(Event, targetName))
    {
        cout << targetName << " Deleted" << endl;
        return true;
    }
    else
    {
        cout << "Category not found: " << targetName << endl;
        return false;
    }
}


// delete item
bool deleteEventItem(TreeNode *Event, string parentEvent, string itemName)
{
    TreeNode *parentNode = findNode1(Event, parentEvent);

    if (parentNode && parentNode->LeftChild)
    {
        if (deleteNode1(parentNode, itemName))
        {
            cout << itemName << " Deleted" << endl;
            return true;
        }
        else
        {
            cout << "Item not found, failed to delete" << endl;
            return false;
        }
    }
    else
    {
        cout << "Invalid parent category: " << parentEvent << endl;
        return false;
    }
}

int main()
{
    int Child, Parent;
    string S_Name_M, Name, targetName;
    int I_Parent_M, I_Price_M, I_Stock_M;

//====================TESTING============================================

    system("cls");
    /*
        root HARUS diinisiasi dalam main karena untuk traverse dibutuhkan root
    */

   //price dibuat -1 untuk mengetahui itu adalah category dan -2 untuk subcategory
    TreeNode* root = AddMember(0, "DataBase Menu", 0, 0);
    AddChild(root, 1, "Roti-dan-Kue", 0, -1);
    AddChild(root, 2, "Minuman", 0, -1);
    AddChild(root, 3, "Makanan-Utama", 0, -1);
    InsertAll();

    //=====TESTING ADD CATEGORY=====
    //AddCategory(root, "Traditional Food"); -> Kondisi array masih tersedia dan inputan sesuai persyaratan.
    //AddCategory(root, "Makanan-Utama"); -> Kondisi nama kategori sudah ada sebelumnya
    //AddCategory(root, ""); -> Kondisi jika inputan berupa string kosong
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 58"); ->Baris 1235-1247 digunakan untuk testing kondisi array penuh, dimana array hanya bisa diisi sampai indeks ke-69. 
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 59"); 
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 60");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 61");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 62");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 63");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 64");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 65");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 66");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 67");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 68");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 69");
    // AddCategory(root, "Testing Kategori Penuh - Isi Indeks 70");


    //=====TESTING EDIT CATEGORY=====
    //
    //EditCategory(root, "Roti-dan-Kue", "Bakery"); -> Kondisi jika kategori ada dan nama baru untuk kategori diinputkan secara sesuai
    //EditCategory(root, "Bakery", "RotiKu"); -> Kondisi jika nama kategori yang ingin diubah tidak ada dalam data menu
    //EditCategory(root, "Makanan-Utama", "Minuman"); -> Kondisi jika nama kategori baru yang ingin ditambahkan sudah dipakai di data menu

    //=====TESTING DELETE CATEGORY=====
    //deleteCategory(root, "Minuman"); -> Kondisi jika kategori yang ingin dihapus ada dan inputan benar
    //deleteCategory(root, "Makanan Utama"); -> Kondisi jika kategori yang ingin dihapus tidak ditemukan karena tidak sesuai )
    //deleteCategory(root, "") -> Kondisi jika inputan berupa string kosong
    //deleteCategory(root, "makanan-utama") -> Kondisi jika inputan tidak sama persis dengan nama kategori di menu
    

    //=====TESTING ADD SUBCATEGORY=====
    //AddSubCategory(root, 2, "Ice Blend"); -> Kondisi jika indeks kategori dimasukkan dengan benar dan subkategori yang ditambahkan valid/sesuai.
    //AddSubCategory(root, 2, "Bread"); -> Kondisi jika indeks kategori dimasukkan dengan benar tapi nama subkategori sudah ada dalam menu.
    //AddSubCategory(root, 2, ""); //-> Kondisi jika indeks kategori dimasukkan dengan benar tapi nama subkategori hanya string kosong
    // AddSubCategory(root, 2, "Pengisian indeks ke 58"); //-> Baris 1267-1279 dilakukan untuk kondisi jika array penuh. Pengisian indeks ke 70 ditolak.
    // AddSubCategory(root, 2, "Pengisian indeks ke 59");
    // AddSubCategory(root, 2, "Pengisian indeks sub ke 60");
    // AddSubCategory(root, 2, "Pengisian indeks ke 61");
    // AddSubCategory(root, 2, "Pengisian indeks ke 62");
    // AddSubCategory(root, 2, "Pengisian indeks ke 63");
    // AddSubCategory(root, 2, "Pengisian indeks ke 64");
    // AddSubCategory(root, 2, "Pengisian indeks ke 65");
    // AddSubCategory(root, 2, "Pengisian indeks ke 66");
    // AddSubCategory(root, 2, "Pengisian indeks ke 67");
    // AddSubCategory(root, 2, "Pengisian indeks ke 68");
    // AddSubCategory(root, 2, "Pengisian indeks ke 69");
    // AddSubCategory(root, 2, "Pengisian indeks ke 70");

    //=====TESTING EDIT SUBCATEGORY=====
    //EditSub(root, "Tea", "Teh"); -> Kondisi jika subkategori yang ingin diedit ada dan nama subkategori baru benar/sesuai.
    //EditSub(root, "Siomay", "Hotdog"); -> Kondisi jika subkategori yang ingin diedit tidak ada di menu. Siomay tidak ada di menu.
    //EditSub(root, "Bun", "Bread"); -> Kondisi jika subkategori yang ingin diedit valid tapi subkategori baru telah ada di data sebelumnya.
    //EditSub(root, "bun", "Bread"); -> Kondisi jika subkategori yang ingin diedit tidak valid (berbeda jenis karakter)
    //EditSub(root, "", ""); -> Kondisi jika inputan berupa string kosong

   //=====TESTING DELETE SUBCATEGORY=====
   //deleteSubCategory(root, 1, "Coffee"); -> Kondisi jika nama kategori bertipe data selain string, misalnya integer
   //deleteSubCategory(root, "Minuman", "Coffee"); -> Kondisi jika nama kategori dari subkategori yang ingin dihapus sesuai, semua inputan sesuai
   //deleteSubCategory(root, "Minuman", "Es Doger"); -> Kondisi jika nama kategori sudah benar namun subkategori yang ingin dihapus tidak ada di dalamnya
   //deleteSubCategory(root, "minuman", "Coffee"); -> Kondisi jika subkategori benar namun nama dari kategori tidak valid/tidak sesuai
   

   //=====TESTING ADD ITEM=====
   //AddNewItem(root, I_Parent_M, "Siomay", 20, 25000); -> Kondisi jika input indeks subkategori sesuai dan keterangan item (nama, stok dan harga) juga valid. Bisa juga untuk testing indeks subkategori tidak sesuai. 
   //AddNewItem(root, I_Parent_M, "Eclair", 20, 25000); -> Bisa untuk mengecek saat item yang dimasukkan sudah ada sebelumnya (inputan subkategori sama dan beda)
   //AddNewItem(root, I_Parent_M, 55, 20, 25000); ->Kondisi jika nama item berupa integer
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 58", 20, 25000); -> Baris 1299-1311 digunakan untuk mengecek bagaimana jika kondisi array sudah penuh tapi ingin memasukkan item baru
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 59", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks item ke 60", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 61", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 62", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 63", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 64", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 65", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 66", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 67", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 68", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 69", 20, 25000);
//    AddNewItem(root, I_Parent_M, "Pengisian indeks ke 70", 20, 25000);

//=====TESTING EDIT ITEM=====
//EditItem(root, "Burgerss", "Hamburger", 5, 10000); -> Kondisi ini untuk testing jika nama item yang ingin diedit tidak ada di menu
//EditItem(root, "Eclair", "Hamburger", "a", 10000); -> Kondisi ini untuk stok bertipe data selain int, misalnya char
//EditItem(root, "Eclair", "Hamburger", 10, 12.5); -> Kondisi ini untuk item sesuai, stok sesuai, tapi harga bertipe data float
//EditItem(root, "Eclair", "Hamburger", 10, 50000); -> Kondisi ini untuk pengubahan item dengan nama, stok, dan harga yang sesuai dan valid

//=====TESTING DELETE ITEM=====
//deleteItem(root, 1, "Tartlet"); -> Kondisi jika input subkategori diisi dengan tipe data lain selain string, misalnya integer
//deleteItem(root, "Bun", "Bagel"); -> Kondisi jika nama subkategori dan nama item sesuai
//deleteItem(root, "Bun", "bagel"); -> Kondisi jika nama subkategori yang ingin dihapus benar/sesuai tapi nama item tidak sesuai
//deleteItem(root, "sup", "Corn-Soup"); -> Kondisi jika nama subkategori yang ingin dihapus tidak sesuai tapi nama item sesuai

// traverseTree(root);
//ItemSearch(root, "Bun"); ->Testing search

//===============================================================================================//
//=====TESTING ADD PROMOTION=====
//KETERANGAN DI BAWAH UNTUK PARAMETER SAJA
//void AddPromotion (bool status, 
//                int startDate, int startMonth, int startYear,
//                int endDate, int endMonth, int endYear, 
//                int type, int paymenttype, int minimumpayment, string benefit, string product)
//bool status 'true' jika promosi aktif dan 'false' jika promosi tidak aktif
// paymenttype:
// const string PaymentMethod[4] = {"MoePay", "Debit", "Credit", "Cash"};   
// type = promotion type (discount = 1 or free item = 2)   

// AddPromotion(true, 29, 12, 2023, 1, 1, 2023, 1, 1, 80000, "Discount 10%", "isi Indeks ke-0"); //->Baris 1340-1348 digunakan untuk testing jika array sudah penuh
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 90000, "Discount 10%", "isi Indeks ke-1");
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 100000, "Discount 10%", "isi indeks ke-2");
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", "isi indeks ke-3");
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", ""); ->Kondisi jika array masih ada dan semua yang diinputkan benar/sesuai
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, 4, ""); -> Kondisi jika ada inputan yang tidak sesuai dengan tipe datanya
// AddPromotion(true, 1, 1, 2024, 26, 1, 2023, 1, 1, 80000, "Discount 10%", ""); -> Kondisi jika terjadi kesalahan penanggalan
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", ""); -> 2 Baris ini Kondisi ini untuk mengecek jika terdapat dua inputan promosi yang sama persis dan array masih tersedia
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", "");

//======TESTING EDIT PROMOTION=====
//EditPromotion(0, true, 11, 8, 2024, 31, 8, 2024, 2, 0, 50000, "Free item", "Bun"); -> Kondisi jika tidak ada data promosi tapi ingin mengedit suatu data promosi
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", ""); -> Baris 1326-1329 ini digunakan dalam kondisi ideal. Ada data promosi dan inputan yang dimasukkan-
// DisplayPromotions();                                                             dalam edit promosi juga benar dan sesuai.
// EditPromotion(1, true, 11, 8, 2024, 31, 8, 2024, 2, 0, 50000, "Free item", "Bun");
// DisplayPromotions();

// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", ""); -> 3 baris ini digunakan jika promosi ada tetapi selectedpromosi yang ada pada edit promosi tidak sesuai
// EditPromotion(2, true, 11, 8, 2024, 31, 8, 2024, 2, 0, 50000, "Free item", "Bun");
// DisplayPromotions();

// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", ""); -> Kondisi ini untuk data baru yang ingin diedit di promosi sama persis dengan data promosi sebelumnya
// EditPromotion(1,true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", "");
// //EditPromotion(2, true, 11, 8, 2024, 31, 8, 2024, 2, 0, 50000, "Free item", "Bun");
// DisplayPromotions();

//=====TESTING DELETE PROMOTIONS====
//ASUMSIKAN ADA DATA PROMOSI
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Discount 10%", ""); ->Baris 1368-1374 untuk kondisi ideal dimana terdapat data promosi dan inputan yang
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 80000, "Free item", "Bun");   dimasukkan dalam parameter Delete benar/sesuai.
// AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 150000, "Discount 40%", "");
// DisplayPromotions();
// DeletePromotion(1);
// cout << endl;
// DisplayPromotions();

// DeletePromotion(1); -> Kondisi ini dipakai jika data promosi kosong tapi ingin menghapus promosi
// DisplayPromotions();

//AddPromotion(true, 1, 1, 2024, 26, 1, 2024, 1, 1, 150000, "Discount 40%", "");
//DeletePromotion('a'); -> Kondisi ini jika data promosi ada tetapi inputan parameter tidak valid (bertipe data lain)
//DisplayPromotions();

//=====TESTING ADD EVENT====
// TreeNode *Event = AddMember1(0, "Event"); // -> Baris 1384-1388 digunakan untuk testing penambahan event secara ideal
// AddEvent(Event, "Breakfast");
// AddEvent(Event, "Brunch");
// AddEvent(Event, "Lunch");
// AddEvent(Event, "Morning Coffee/ Tea time/ Afternoon Coffee");
// AddEvent(Event, "Dinner");
//AddEvent(Event, 6, "Dinner"); // -> Kondisi jika terdapat event yang duplikat
// insertEvent();


//=====TESTING EDIT EVENT=====
    //
    // EditEvent(Event, "Brunch", "Brunch & Tea");
    // EditEvent(Event, "Breakfast", "Brunch & Tea");
    // EditEvent(Event, "Traditional Food", "Brunch & Tea");
    // EditEvent(Event, "Breakfast", "Sarapan Pagi");
    // traverseTree1(Event);

    //=====TESTING FILLING EVENT=====
    //
    //eventfill(&Member1[1], 42);
    //AddfillEvent(Event, Child);

    //=====TESTING DELETE EVENT=====
    //
    // deleteEvent(Event, "Brunch");
    // deleteEvent(Event, "Traditional Food");
    // deleteEvent(Event, "brunch");
    // deleteEvent(Event, "Brunch");
    // traverseTree1(Event);
    //insertEvent();

    //=====TESTING ADDFILL EVENT=====
    //
    // AddfillEvent(Event, Child);
    // traverseTree1(Event);
    
    //EditfillEvent(Event, "Latte", "LATTE");
    //deleteEvent(Event, "Brunch");
    //deleteEventItem(Event, "Breakfast", "Club-Sandwich");
// traverseTree1(Event);


    //DisplayPromotions();

    // DeletePromotion(promotions, numberOfPromotions, 1);

    // DisplayPromotions(promotions, numberOfPromotions);

    // ApplyPromotion("10 Februari", 100000, Promotion::FreeItem);

}