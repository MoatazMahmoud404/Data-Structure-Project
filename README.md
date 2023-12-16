# Data-Structure-Project
## Library Management System

This C++ code implements a Library Management System (LMS) using a double linked list data structure.

The program provides a menu-driven interface for managing a list of orders, each associated with a receipt number.

## Users can perform operations such as :

01. Adding orders at the beginning of the list

02. Adding orders at the middle of the list

03. Adding orders at the end of the list

04. Deleting orders at the beginning of the list

05. Deleting orders by position of the list

06. Deleting orders by receipt number of the list

07. Deleting orders at the end of the list

08. Displaying the entire list of orders with their details.

09. Searching for a specific order by its receipt number.

10. Checking if the list is empty

11. Clearing the entire list.

12. Calculating the total number of orders and the total price of all orders.

## Description  
This implementation uses a struct to store the order details, including the number of the receipt, the order name, the quantity, the price per unit, and the total price. The code also includes functions for printing the receipt information for a specific node.

Users take orders and add them to a linked list. They choose an order, or quantity, and can optionally view a PDF before adding. Order details and total price are stored in the list. Multiple orders can be added before finishing.

The code also includes a function to print a receipt for a completed order.
The system utilizes a double linked list to efficiently handle various operations on the list of orders.

## About Folders : 

// Source_File folder: Contains lecture materials in PDF format.
// Lecture materials are associated with specific order choices in the program.
// When a user selects a lecture order, the program opens the corresponding PDF file.
// Example: "Lec01.pdf", "Lec02.pdf", ...

// history folder: Stores historical data related to orders and receipts.// - counter_of_receipt.txt: Keeps track of the number of receipts issued.
//   This counter is incremented each time a receipt is printed.
// - receiptX.txt: Individual text files storing details of each receipt.
//   The X represents the receipt number, and files are created and named sequentially.
//   Each receipt file includes order details, counts, prices, and total receipt amount.
//   The files can be opened using the default text editor (notepad) for review.

@0xMoataz
Version 01
12/15/2023
