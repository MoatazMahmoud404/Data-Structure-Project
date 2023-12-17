#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

class DoubleLinkeList
{
public:
    int counter = 1;
    void sleep(int seconds);
    void clearScreen();
    void main();

    void insertnode_beg();
    void insertnode_pos();
    void insertnode_end();

    void deletenode_beg();
    void deletenode_pos();
    void deletenode_end();
    void deletenode_by_numOfReceipt();

    void display();
    void back();
    void dashboard();
    void dashboard_rest();

    void getsize();
    void eraseList();
    void isEmpty();
    bool Empty();
    void search();

private:
    struct node
    {
        struct NewOrder
        {
            string order;
            int count;
            double price;
            double total_price;
        };
        NewOrder orderDetails[10];
        int numOfReceipt;
        int numOfOrder;
        long double total = 0;
        node *next;
        node *prev;
    };
    void print_Receipt(node *temp);
    void TakeOrder(node *newNode);
    node *head = NULL;
};

void DoubleLinkeList::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void DoubleLinkeList::sleep(int seconds)
{
    this_thread::sleep_for(chrono::seconds(seconds));
}

void DoubleLinkeList::back()
{
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << setw(05) << "Do you want back to dashboard or exit ?" << endl;
    cout << setw(05) << "00 - Exit" << endl;
    cout << setw(05) << "01 - Back To Dashboard" << endl;

    cout << "\n";
    bool flag = true;
    int choice02;
    while (flag)
    {
        cout << ">> Enter your choice : ";
        cin >> choice02;
        cout << "\n";
        switch (choice02)
        {
        case 0:
            cout << setw(45) << "\aExiting the program ..." << setw(45) << endl;
            exit(0);
            break;
        case 1:
            cout << setw(61) << "Back To Dashboard ..." << setw(61) << endl;
            flag = false;
            break;
        default:
            cout << "\n";
            cout << setw(05) << "\aError" << endl;
            cout << setw(05) << "Please enter a valid choice.\n\n";
            break;
        }
    }
    sleep(1);
    clearScreen();
    dashboard();
}

void DoubleLinkeList::insertnode_beg()
{
    clearScreen();
    dashboard_rest();
    node *newNode = new node;
    TakeOrder(newNode);
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        back();
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    back();
}

void DoubleLinkeList::insertnode_end()
{
    clearScreen();
    dashboard_rest();
    node *newNode = new node;
    TakeOrder(newNode);

    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    back();
}

void DoubleLinkeList::insertnode_pos()
{
    clearScreen();
    dashboard_rest();
    node *newNode = new node;
    TakeOrder(newNode);
    newNode->next = NULL;
    newNode->prev = NULL;

    int pos;
    cout << "=======================================================" << endl;
    display();
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "Enter Position To Put This Order:\n>> ";
    cin >> pos;

    if (pos < 0)
    {
        cout << "Invalid position. Please enter a non-negative position." << endl;
        back();
    }
    else if (pos == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        back();
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < pos && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            newNode->prev = temp->prev;
            if (temp->prev != NULL)
            {
                temp->prev->next = newNode;
            }
            temp->prev = newNode;
            newNode->next = temp;
        }
        else
        {
            cout << "Not Found" << endl;
            delete newNode;
            back();
        }
        back();
    }
}

void DoubleLinkeList::display()
{
    cout << "Orders List --> " << endl;
    if (head == NULL)
    {
        cout << "Orders List is empty." << endl;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << "Number of order : " << temp->numOfReceipt << endl;
        cout << setw(10) << "Order" << setw(16) << "Count" << setw(10) << "Price" << setw(15) << "Total Price" << endl;
        for (int i = 0; i < temp->numOfOrder; i++)
        {
            cout << setw(10) << temp->orderDetails[i].order << setw(14) << temp->orderDetails[i].count << setw(12) << temp->orderDetails[i].price << setw(12) << temp->orderDetails[i].total_price << endl;
        }
        cout << setw(10) << "Total Receipt :" << setw(33) << temp->total << endl;
        cout << endl;

        temp = temp->next;
    }
}

void DoubleLinkeList::getsize()
{
    int count = 1;
    node *temp = head;
    if (head == NULL)
    {
        cout << "Orders List is empty." << endl;
        back();
    }

    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Count of orders : " << count << endl;
    back();
}

void DoubleLinkeList::search()
{
    int numOfReceipt, index = 0;
    bool flag = false; // !! Initialize flag to false
    cout << "Enter Num Of Receipt :\n>> ";
    cin >> numOfReceipt;
    node *temp = head;
    while (temp != NULL) // !! Fix the loop condition
    {
        if (temp->numOfReceipt == numOfReceipt)
        {
            flag = true;
            break;
        }
        temp = temp->next;
        index++;
    }
    if (flag)
    {
        cout << "Found in index " << index << endl;
    }
    else
    {
        cout << "Not Found !!" << endl;
    }
    back();
}

void DoubleLinkeList::deletenode_pos()
{
    int pos;
    cout << "=======================================================" << endl;
    display();
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "ُEnter Position To Delete This Order :\n>> ";
    cin >> pos;

    if (pos < 0)
    {
        cout << "\aError !!" << endl;
        cout << "Invalid position. Please enter a non-negative position." << endl;
        back();
    }
    if (head == NULL)
    {
        cout << "Orders List is empty. Cannot delete." << endl;
        back();
    }

    node *temp = head;

    if (pos == 0)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        print_Receipt(temp);
        delete temp;
        back();
    }
    for (int i = 0; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Not Found !!" << endl;
        back();
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        print_Receipt(temp);
        delete temp;
        back();
    }
}

void DoubleLinkeList::deletenode_by_numOfReceipt()
{
    int numOfReceipt;

    cout << "=======================================================" << endl;
    display();
    cout << "=======================================================" << endl;
    cout << endl;

    cout << "Enter Num Of Receipt :\n>> ";
    cin >> numOfReceipt;
    if (head == NULL)
    {
        cout << "Orders List is empty. Cannot delete." << endl;
        back();
    }

    node *temp = head;
    if (temp->numOfReceipt == numOfReceipt)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        print_Receipt(temp);
        delete temp;
        back();
    }
    while (temp != NULL && temp->numOfReceipt != numOfReceipt)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Not Found !!" << endl;
        back();
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    print_Receipt(temp);
    delete temp;
    back();
}

void DoubleLinkeList::deletenode_end()
{
    if (head == NULL)
    {
        cout << "Orders List is empty. Cannot delete." << endl;
        back();
    }
    node *temp = head;
    node *prev = NULL;
    if (temp->next == NULL)
    {
        print_Receipt(head);
        delete head;
        head = NULL;
        cout << "Last Order deleted. List is now empty." << endl;
        back();
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    cout << "Last Order deleted." << endl;
    print_Receipt(temp);
    delete temp;
    back();
}

void DoubleLinkeList::deletenode_beg()
{
    if (head == NULL)
    {
        cout << "Orders List is empty. Cannot delete." << endl;
        back();
    }
    node *temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
        cout << "Done !!" << endl;
        print_Receipt(temp);
        delete temp;
        back();
    }
    head = head->next;
    head->prev = NULL;
    cout << "Done !!" << endl;
    print_Receipt(temp);
    delete temp;
    back();
}

void DoubleLinkeList::eraseList()
{
    node *temp = head;
    node *nextNode;

    while (temp != NULL)
    {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
    cout << "Done !!" << endl;
    back();
}

bool DoubleLinkeList::Empty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DoubleLinkeList::isEmpty() // !! TTTTTTTTTrace
{
    if (head == NULL)
    {
        cout << "Order list is empty." << endl;
        back();
    }
    else
    {
        cout << "Order list is not empty." << endl;
        back();
    }
}

void DoubleLinkeList::dashboard()
{
    int choice_fun;
    bool flag;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << setw(60) << "------> Dashboard <------" << setw(60) << endl;
    cout << setw(05) << "01 - Display All Books In Cart" << endl;
    cout << setw(05) << "02 - Insert Book At Beginning" << endl;                //** Insert at beginning
    cout << setw(05) << "03 - Insert Book At Position" << endl;                 //** Insert at position
    cout << setw(05) << "04 - Insert Book At End             [Append]" << endl; //** Insert at end
    cout << setw(05) << "05 - Delete Book At Beginning" << endl;
    cout << setw(05) << "06 - Delete Book At Middle By Num Of Receipt" << endl; // !! Back
    cout << setw(05) << "07 - Delete Book At Middle By Position" << endl;
    cout << setw(05) << "08 - Delete Book At End" << endl;
    cout << setw(05) << "09 - Count Of Books" << endl;
    cout << setw(05) << "10 - Search About Book" << endl;
    cout << setw(05) << "11 - Check Empty" << endl;
    cout << setw(05) << "12 - Delete All Books" << endl;
    cout << setw(05) << "00 - Exit" << endl;
    flag = true;

    while (flag)
    {
        cout << "\n>> Enter your choice : ";
        cin >> choice_fun;
        cout << "-----------------------------------------------------------------------------------------------" << endl;
        switch (choice_fun)
        {
        case 0:
            cout << setw(62) << "\aExiting the program ..." << setw(62) << endl;
            exit(0);
            break;
        case 1:
            display();
            back();
            break;
        case 2:
            insertnode_beg();
            break;
        case 3:
            insertnode_pos();
            break;
        case 4:
            insertnode_end();
            break;
        case 5:
            deletenode_beg();
            break;
        case 6:
            deletenode_by_numOfReceipt();
            break;
        case 7:
            deletenode_pos();
            break;
        case 8:
            deletenode_end();
            break;
        case 9:
            getsize();
            break;
        case 10:
            search();
            break;
        case 11:
            isEmpty();
            break;
        case 12:
            eraseList();
            break;
        default:
            cout << setw(05) << "\aError" << endl;
            cout << setw(05) << "Please enter a valid choice.\n\n";
            break;
        }
    }
}

void DoubleLinkeList::TakeOrder(node *newNode)
{
    int choice_order = 0, count = 0, new_order = 0;
    int choice_order2 = 0;
    double total = 0;
    bool flag = true;
    while (flag)
    {
        bool flag2 = true;
        while (flag2)
        {
            flag2 = false;
            cout << "Enter Your Order\n>> ";
            cin >> choice_order;
            cout << "Enter Count\n>> ";
            cin >> count;
            switch (choice_order)
            {
            case 1:

                cout << "[1] Show And Add Direct " << endl;
                cout << "[2] Add Direct " << endl;
                cout << ">> ";
                cin >> choice_order2;
                if (choice_order2 == 1)
                {
                    system("start \"Foxit PDF Editor\" \".\\Source_File\\Lec01.pdf\"");
                }
                else if (choice_order2 != 1 || choice_order2 != 2)
                {
                    cout << "This choice is not valid" << endl;
                }

                newNode->orderDetails[new_order].order = "Lec 01";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 2.99;
                newNode->orderDetails[new_order].total_price = 2.99 * count;

                break;
            case 2:
            {
                cout << "[1] Show And Add Direct " << endl;
                cout << "[2] Add Direct " << endl;
                cout << ">> ";
                cin >> choice_order2;
                if (choice_order2 == 1)
                {
                    system("start \"Foxit PDF Editor\" \".\\Source_File\\Lec02.pdf\"");
                }
                else if (choice_order2 != 1 || choice_order2 != 2)
                {
                    cout << "This choice is not valid" << endl;
                }
                newNode->orderDetails[new_order].order = "Lec 02";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 6.49;
                newNode->orderDetails[new_order].total_price = 6.49 * count;
                break;

            case 3:
                cout << "[1] Show And Add Direct " << endl;
                cout << "[2] Add Direct " << endl;
                cout << ">> ";
                cin >> choice_order2;
                if (choice_order2 == 1)
                {
                    system("start \"Foxit PDF Editor\" \".\\Source_File\\Lec03.pdf\"");
                }
                else if (choice_order2 != 1 || choice_order2 != 2)
                {
                    cout << "This choice is not valid" << endl;
                }
                newNode->orderDetails[new_order].order = "Lec 03";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 8.99;
                newNode->orderDetails[new_order].total_price = 8.99 * count;
                break;

            case 4:
                cout << "[1] Show And Add Direct " << endl;
                cout << "[2] Add Direct " << endl;
                cout << ">> ";
                cin >> choice_order2;
                if (choice_order2 == 1)
                {
                    system("start \"Foxit PDF Editor\" \".\\Source_File\\Lec04.pdf\"");
                }
                else if (choice_order2 != 1 || choice_order2 != 2)
                {
                    cout << "This choice is not valid" << endl;
                }
                newNode->orderDetails[new_order].order = "Lec 04";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 10.99;
                newNode->orderDetails[new_order].total_price = 10.99 * count;
                break;

            case 5:
                cout << "[1] Show And Add Direct " << endl;
                cout << "[2] Add Direct " << endl;
                cout << ">> ";
                cin >> choice_order2;
                if (choice_order2 == 1)
                {
                    system("start \"Foxit PDF Editor\" \".\\Source_File\\Lec05.pdf\"");
                }
                else if (choice_order2 != 1 || choice_order2 != 2)
                {
                    cout << "This choice is not valid" << endl;
                }
                newNode->orderDetails[new_order].order = "Lec 05";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 7.99;
                newNode->orderDetails[new_order].total_price = 7.99 * count;
                break;

            case 6:
                cout << "[1] Show And Add Direct " << endl;
                cout << "[2] Add Direct " << endl;
                cout << ">> ";
                cin >> choice_order2;
                if (choice_order2 == 1)
                {
                    system("start \"Foxit PDF Editor\" \".\\Source_File\\Lec06.pdf\"");
                }
                else if (choice_order2 != 1 || choice_order2 != 2)
                {
                    cout << "This choice is not valid" << endl;
                }
                newNode->orderDetails[new_order].order = "Lec 06";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 8.99;
                newNode->orderDetails[new_order].total_price = 8.99 * count;
                break;

            case 7:
                cout << "[1] Show And Add Direct " << endl;
                cout << "[2] Add Direct " << endl;
                cout << ">> ";
                cin >> choice_order2;
                if (choice_order2 == 1)
                {
                    system("start \"Foxit PDF Editor\" \".\\Source_File\\Lec07.pdf\"");
                }
                else if (choice_order2 != 1 || choice_order2 != 2)
                {
                    cout << "This choice is not valid" << endl;
                }
                newNode->orderDetails[new_order].order = "Lec 07";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 10.99;
                newNode->orderDetails[new_order].total_price = 10.99 * count;
                break;
            default:
                cout << "This choice is not valid" << endl;
                flag2 = true;
            }
            }

            newNode->total += newNode->orderDetails[new_order].total_price;
            char addAnother;
            cout << "Do you want to add another order ? (y/n) : ";
            cin >> addAnother;
            if (addAnother == 'y' || addAnother == 'Y')
            {
                flag = true;
            }
            else if (addAnother != 'n' || addAnother != 'N')
            {
                flag = false;
            }
            else
            {
                cout << "\aError" << endl;
                back();
            }
            new_order++;
            newNode->numOfOrder = new_order;
        }
    }
    newNode->numOfReceipt = counter;
    counter++;
}

void DoubleLinkeList::print_Receipt(node *temp)
{
    cout << "Print Receipt .";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << "." << endl;
    cout << "Thank You, GoodBye <3" << endl;
    string number_of_receipt;
    ifstream read_num_of_rec("./history/counter_of_receipt.txt");
    read_num_of_rec >> number_of_receipt;
    read_num_of_rec.close();

    ofstream rewrite_num_of_rec("./history/counter_of_receipt.txt");
    rewrite_num_of_rec << atoi(number_of_receipt.c_str()) + 1; // convert string to int
    rewrite_num_of_rec.close();

    string filename_rec = "./history/receipt" + number_of_receipt + ".txt";
    ofstream out_stream(filename_rec);

    // print receipt

    out_stream << "Number of order : " << temp->numOfReceipt << endl;
    out_stream << setw(10) << "Order" << setw(16) << "Count" << setw(10) << "Price" << setw(15) << "Total Price" << endl;
    for (int i = 0; i < temp->numOfOrder; i++)
    {
        out_stream << setw(10) << temp->orderDetails[i].order << setw(14) << temp->orderDetails[i].count << setw(12) << temp->orderDetails[i].price << setw(12) << temp->orderDetails[i].total_price << endl;
    }
    out_stream << setw(10) << "Total Receipt :" << setw(33) << temp->total << endl;
    out_stream << endl;

    out_stream.close();

    string command = "notepad  .\\history\\receipt" + number_of_receipt + ".txt";
    system(command.c_str());
}

void DoubleLinkeList::main()
{
    cout << "\n\n\n";
    cout << setw(60) << "Welcome To Main Page" << setw(60) << endl;
    cout << setw(70) << "Library Mangement System (LMS) Using Double Linked List" << setw(70) << endl;
    dashboard();
}

void DoubleLinkeList::dashboard_rest()
{
    cout << setw(25) << "Menu" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "01 >> Lec 01 " << setw(20) << "Data Structure " << setw(20) << "Price: $2.99" << endl;
    cout << "02 >> Lec 02 " << setw(20) << "Data Structure " << setw(20) << "Price: $6.49" << endl;
    cout << "03 >> Lec 03 " << setw(20) << "Data Structure " << setw(20) << "Price: $8.99" << endl;
    cout << "04 >> Lec 04 " << setw(20) << "Data Structure " << setw(21) << "Price: $10.99" << endl;
    cout << "05 >> Lec 05 " << setw(20) << "Data Structure " << setw(20) << "Price: $7.99" << endl;
    cout << "06 >> Lec 06 " << setw(20) << "Data Structure " << setw(20) << "Price: $8.99" << endl;
    cout << "07 >> Lec 07 " << setw(20) << "Data Structure " << setw(21) << "Price: $10.99" << endl;
    cout << "--------------------------------------------------------" << endl;
}

int main()
{
    DoubleLinkeList test01;
    test01.main();
    return 0;
}