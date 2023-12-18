# Data-Structure-Project

## Development Team


We are a team of students studying at Ahram Canadian University in the College of Computer Science & AI. Our collaborative efforts are dedicated to the development of the Library Management System.

Here's an overview of our team:


| Role                | Name                       | Student ID | Group |
|---------------------|----------------------------|-------------|-------|
| Team Leader         | Abdelrahman Ahmed           | 42210259    | A1    |
| Team Member         | Khaled Ashraf Fitoh         | 42210103    | A1    |
| Team Member         | Ahmed Haytham Ragab         | 42210126    | A1    |
| Team Member         | Moataz Mahmoud Mohamed      | 42210055    | A1    |

**Instructor:**
- **Eng. Dina Ehab**

## Library Management System

This C++ code implements a robust Library Management System (LMS) utilizing a double linked list data structure.

The program offers a user-friendly, menu-driven interface for efficiently managing a list of orders, each uniquely identified by a receipt number.

## Key Operations for Users:

1. Adding orders at the beginning of the list
2. Adding orders at the middle of the list
3. Adding orders at the end of the list
4. Deleting orders at the beginning of the list
5. Deleting orders by position of the list
6. Deleting orders by receipt number of the list
7. Deleting orders at the end of the list
8. Displaying the entire list of orders with their details.
9. Searching for a specific order by its receipt number.
10. Checking if the list is empty
11. Clearing the entire list.
12. Calculating the total number of orders and the total price of all orders.

## Description  
This implementation employs a structured approach by using a `struct` to encapsulate order details, including receipt number, order name, quantity, price per unit, and total price. The code also integrates functions for printing order details and supports viewing corresponding PDF lecture materials associated with specific order choices.

Users can seamlessly add orders to the linked list, make choices regarding order quantities, and optionally preview associated lecture materials in PDF format. Order details and total prices are efficiently stored in the linked list, allowing for the addition of multiple orders before finalization.

The code also incorporates a function to generate and print a receipt for a completed order. The system optimally utilizes a double linked list to facilitate various operations on the list of orders.

## Folder Structure:

**Source_File Folder:**
Contains lecture materials in PDF format, each associated with specific order choices in the program.

For instance: "Lec01.pdf", "Lec02.pdf", ...

When a user selects a particular order linked to a lecture, the program seamlessly opens the corresponding PDF file. This integration enhances the user experience, providing access to relevant educational content associated with their order choices.

**History Folder:**
Stores historical data pertaining to orders and receipts.

- `counter_of_receipt.txt:` Maintains a count of issued receipts, incrementing with each printed receipt.
- `receiptX.txt:` Individual text files storing details of each receipt. The 'X' denotes the receipt number, and files are sequentially created and named. Each receipt file comprehensively includes order details, counts, prices, and the total receipt amount. Open these files using the default text editor (e.g., Notepad) for review.


**Code Structure Diagram:**
For a visual representation of the code structure, please refer to the PDF document available in the `Source_File` folder. The document, named "Code_Structure_Diagram.pdf," provides insightful diagrams illustrating the architecture and organization of the code.

[View Code Structure Diagram (PDF)]((LMS)_Diagram.pdf)

![View Code Structure Diagram (Photo)]((LMS)_Diagram.png)

## **Screenshots :**
Here is a screenshot of the Library Management System in action:

1. **Dashboard:**
   ![Dashboard](Final_Project_04/ScreenShots/Screenshot_(1).png)

2. **Menu of Books:**

   ![Menu of Books](Final_Project_04/ScreenShots/Screenshot_(2).png)

3. **Orders List:**
   ![Orders List](Final_Project_04/ScreenShots/Screenshot_(3).png)

4. **Check out order and print receipt:**
   ![Check out order and print receipt](Final_Project_04/ScreenShots/Screenshot_(4).png)

5. **Show receipt:**
   ![Show receipt](Final_Project_04/ScreenShots/Screenshot_(5).png)

6. **Done Check out:**
   ![Done Check out](Final_Project_04/ScreenShots/Screenshot_(6).png)


**@0xMoataz  
Version 02  
12/14/2023**


## Update to v0.3

### Error Handling with Color Change

This part of version 0.3, is designed for robust error handling in a console application. It features the following components:

- Prints an error message in red with an accompanying alert sound.
- Introduces a 3-second pause for better user attention.
- Displays an additional error message to provide context.
- Resets the text color to its default state.

## Screenshots

![Error](Final_Project_04/ScreenShots/Screenshot_(7).png)

## Code Review

```cpp
cout << setw(5) << "\aError !! ";
system("color 04");
sleep(3);
cout << setw(05) << "\nPlease enter a valid choice.\n\n";
system("color 07");
```


**@0xMoataz  
Version 03  
12/17/2023**
