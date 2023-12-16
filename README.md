# Data-Structure-Project
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
Contains lecture materials in PDF format, each associated with specific order choices in the program. For instance: "Lec01.pdf", "Lec02.pdf", ...

When a user selects a particular order linked to a lecture, the program seamlessly opens the corresponding PDF file. This integration enhances the user experience, providing access to relevant educational content associated with their order choices.

**History Folder:**
Stores historical data pertaining to orders and receipts.

- `counter_of_receipt.txt:` Maintains a count of issued receipts, incrementing with each printed receipt.
- `receiptX.txt:` Individual text files storing details of each receipt. The 'X' denotes the receipt number, and files are sequentially created and named. Each receipt file comprehensively includes order details, counts, prices, and the total receipt amount. Open these files using the default text editor (e.g., Notepad) for review.


**Code Structure Diagram:**
For a visual representation of the code structure, please refer to the PDF document available in the `Source_File` folder. The document, named "Code_Structure_Diagram.pdf," provides insightful diagrams illustrating the architecture and organization of the code.

[View Code Structure Diagram (PDF)](Data-Structure-Project/(LMS)_Diagram.pdf)

**@0xMoataz  
Version 01  
12/15/2023**
