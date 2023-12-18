#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;
const int MAX_ORDER_DETAILS = 10;

class DoubleLinkeList
{
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
        NewOrder orderDetails[MAX_ORDER_DETAILS];
        int numOfReceipt = 0;
        int numOfOrder = 0;
        long double total = 0;
        node *next;
        node *prev;
    };
    node *head = NULL;
    int orderCounter = 1;

    void sleep(int seconds);
    void printReceipt(node *order);
    void TakeOrder(node *order);
    void displayOrders();

    void insertOrderAtBeginning();
    void insertOrderAtPosition();
    void insertOrderAtEnd();

    void deleteOrderAtBeginning();
    void deleteOrderByNumOfReceipt();
    void deleteOrderByPosition();
    void deleteOrderAtEnd();

    void getOrderCount();
    void searchOrder();
    void checkEmpty();
    void eraseOrders();
    bool isEmpty();
    void back();
    void dashboard();
    void dashboardRest();

public:
    void
    startLibrarySystem();
};

void DoubleLinkeList::sleep(int seconds)
{
    this_thread::sleep_for(chrono::seconds(seconds));
}

void DoubleLinkeList::printReceipt(node *temp)
{
    cout << "Print Receipt ."; // ** v0.3
    for (int i = 0; i < 8; i++)
    {
        sleep(1);
        cout << ".";
    }
    cout << endl;

    cout << "Thank You, GoodBye <3" << endl;
    string number_of_receipt;
    ifstream read_num_of_rec("./History/counter_of_receipt.txt");
    read_num_of_rec >> number_of_receipt;
    read_num_of_rec.close();

    ofstream rewrite_num_of_rec("./History/counter_of_receipt.txt");
    rewrite_num_of_rec << atoi(number_of_receipt.c_str()) + 1; // convert string to int or atoi();
    rewrite_num_of_rec.close();

    string filename_rec = "./History/receipt" + number_of_receipt + ".txt";
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

    string command = "notepad  .\\History\\receipt" + number_of_receipt + ".txt";
    system(command.c_str());
}

void DoubleLinkeList::TakeOrder(node *newNode)
{
    int choice_order = 0, count = 0, new_order = 0;
    double total = 0;
    bool flag = true;

    // Check if the maximum number of orders has been reached
    if (newNode->numOfOrder >= MAX_ORDER_DETAILS)
    {
        cout << "Maximum number of orders reached (10 orders). Cannot add more orders." << endl;
        return;
    }

    while (flag)
    {
        bool flag2 = true;
        int choice_order2 = 0;
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
                else if (choice_order2 != 2)
                {
                    cout << setw(05) << "\aError !! ";
                    system("color 04");
                    cout << setw(05) << "\nInvalid choice.\n\n";
                    sleep(3);
                    system("pause");
                    cout << endl;
                    system("color 07");
                }

                newNode->orderDetails[new_order].order = "Lec 01";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 2.99;
                newNode->orderDetails[new_order].total_price = 2.99 * count;

                break;
            case 2:
                cout << "[1] Show And Add Direct " << endl;
                cout << "[2] Add Direct " << endl;
                cout << ">> ";
                cin >> choice_order2;
                if (choice_order2 == 1)
                {
                    system("start \"Foxit PDF Editor\" \".\\Source_File\\Lec02.pdf\"");
                }
                else if (choice_order2 != 2)
                {
                    cout << setw(05) << "\aError !! ";
                    system("color 04");
                    cout << setw(05) << "\nInvalid choice.\n\n";
                    sleep(3);
                    system("pause");
                    cout << endl;
                    system("color 07");
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
                else if (choice_order2 != 2)
                {
                    cout << setw(05) << "\aError !! ";
                    system("color 04");
                    cout << setw(05) << "\nInvalid choice.\n\n";
                    sleep(3);
                    system("pause");
                    cout << endl;
                    system("color 07");
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
                else if (choice_order2 != 2)
                {
                    cout << setw(05) << "\aError !! ";
                    system("color 04");
                    cout << setw(05) << "\nInvalid choice.\n\n";
                    sleep(3);
                    system("pause");
                    cout << endl;
                    system("color 07");
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
                else if (choice_order2 != 2)
                {
                    cout << setw(05) << "\aError !! ";
                    system("color 04");
                    cout << setw(05) << "\nInvalid choice.\n\n";
                    sleep(3);
                    system("pause");
                    cout << endl;
                    system("color 07");
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
                else if (choice_order2 != 2)
                {
                    cout << setw(05) << "\aError !! ";
                    system("color 04");
                    cout << setw(05) << "\nInvalid choice.\n\n";
                    sleep(3);
                    system("pause");
                    cout << endl;
                    system("color 07");
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
                else if (choice_order2 != 2)
                {
                    cout << setw(05) << "\aError !! ";
                    system("color 04");
                    cout << setw(05) << "\nInvalid choice.\n\n";
                    sleep(3);
                    system("pause");
                    cout << endl;
                    system("color 07");
                }
                newNode->orderDetails[new_order].order = "Lec 07";
                newNode->orderDetails[new_order].count = count;
                newNode->orderDetails[new_order].price = 10.99;
                newNode->orderDetails[new_order].total_price = 10.99 * count;
                break;
            default:
                cout << setw(05) << "\aError !! ";
                system("color 04");
                cout << setw(05) << "\nInvalid choice.\n\n";
                sleep(3);
                system("pause");
                cout << endl;
                system("color 07");
                flag2 = true;
            }

            newNode->total += newNode->orderDetails[new_order].total_price;
            char addAnother;
            cout << "Do you want to add another order ? (y/n) : ";
            cin >> addAnother;

            if (addAnother == 'y' || addAnother == 'Y' || addAnother == '1')
            {
                // Check if the maximum number of orders has been reached
                if (new_order >= MAX_ORDER_DETAILS - 1)
                {
                    cout << "Maximum number of orders reached (10 orders). Cannot add more orders." << endl;
                    flag = false;
                }
                else
                {
                    flag = true;
                }
            }
            else if (addAnother == 'n' || addAnother == 'N' || addAnother == '0')
            {
                flag = false;
            }
            else
            {
                cout << setw(05) << "\aError !! ";
                system("color 04");
                cout << setw(05) << "\nInvalid choice.\n\n";
                sleep(3);
                system("pause");
                cout << endl;
                system("color 07");
                flag = false;
            }
            new_order++;
            newNode->numOfOrder = new_order;
        }
    }
    newNode->numOfReceipt = orderCounter;
    orderCounter++;
}

void DoubleLinkeList::displayOrders()
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

void DoubleLinkeList::insertOrderAtBeginning()
{
    system("cls");
    dashboardRest();
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

void DoubleLinkeList::insertOrderAtPosition()
{
    system("cls");
    dashboardRest();
    node *newNode = new node;
    TakeOrder(newNode);
    newNode->next = NULL;
    newNode->prev = NULL;

    int pos;
    cout << "=======================================================" << endl;
    displayOrders();
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "Enter Position To Put This Order:\n>> ";
    cin >> pos;

    if (pos < 0)
    {
        cout << setw(05) << "\aError !! ";
        system("color 04");
        cout << "\nInvalid position. Please enter a non-negative position." << endl;
        sleep(3);
        system("pause");
        cout << endl;
        system("color 07");
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

void DoubleLinkeList::insertOrderAtEnd()
{
    system("cls");
    dashboardRest();
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

void DoubleLinkeList::deleteOrderAtBeginning()
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
        printReceipt(temp);
        delete temp;
        back();
    }
    head = head->next;
    head->prev = NULL;
    cout << "Done !!" << endl;
    printReceipt(temp);
    delete temp;
    back();
}

void DoubleLinkeList::deleteOrderByNumOfReceipt()
{
    int numOfReceipt;

    cout << "=======================================================" << endl;
    displayOrders();
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
        printReceipt(temp);
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
    printReceipt(temp);
    delete temp;
    back();
}

void DoubleLinkeList::deleteOrderByPosition()
{
    int pos;
    cout << "=======================================================" << endl;
    displayOrders();
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "ُEnter Position To Delete This Order :\n>> ";
    cin >> pos;

    if (pos < 0)
    {
        cout << setw(05) << "\aError !! ";
        system("color 04");
        cout << "\nInvalid position. Please enter a non-negative position." << endl;
        sleep(3);
        system("pause");
        cout << endl;
        system("color 07");
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
        printReceipt(temp);
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
        printReceipt(temp);
        delete temp;
        back();
    }
}

void DoubleLinkeList::deleteOrderAtEnd()
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
        printReceipt(head);
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
    printReceipt(temp);
    delete temp;
    back();
}

void DoubleLinkeList::getOrderCount()
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

void DoubleLinkeList::searchOrder()
{
    int numOfReceipt, index = 0;
    bool flag = false;
    cout << "Enter Num Of Receipt :\n>> ";
    cin >> numOfReceipt;
    node *temp = head;
    while (temp != NULL)
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

void DoubleLinkeList::checkEmpty()
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

void DoubleLinkeList::eraseOrders()
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

bool DoubleLinkeList::isEmpty()
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

void DoubleLinkeList::startLibrarySystem()
{
    cout << "\n\n\n";
    cout << setw(60) << "Welcome To Main Page" << setw(60) << endl;
    cout << setw(76) << "Library Mangement System (LMS) Using Double Linked List" << setw(76) << endl;
    dashboard();
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
            cout << setw(05) << "\aError !! ";
            system("color 04");
            cout << setw(05) << "\nPlease enter a valid choice.\n\n";
            sleep(3);
            system("pause");
            cout << endl;
            system("color 07");
            break;
        }
    }
    sleep(1);
    system("cls");
    dashboard();
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
            displayOrders();
            back();
            break;
        case 2:
            insertOrderAtBeginning();
            break;
        case 3:
            insertOrderAtPosition();
            break;
        case 4:
            insertOrderAtEnd();
            break;
        case 5:
            deleteOrderAtBeginning();
            break;
        case 6:
            deleteOrderByNumOfReceipt();
            break;
        case 7:
            deleteOrderByPosition();
            break;
        case 8:
            deleteOrderAtEnd();
            break;
        case 9:
            getOrderCount();
            break;
        case 10:
            searchOrder();
            break;
        case 11:
            checkEmpty();
            break;
        case 12:
            eraseOrders();
            break;
        default:
            cout << setw(05) << "\aError !! ";
            system("color 04");
            cout << setw(05) << "\nPlease enter a valid choice.\n\n";
            sleep(3);
            system("pause");
            cout << endl;
            system("color 07");
            break;
        }
    }
}

void DoubleLinkeList::dashboardRest()
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
    DoubleLinkeList librarySystem;
    librarySystem.startLibrarySystem();

    return 0;
}
