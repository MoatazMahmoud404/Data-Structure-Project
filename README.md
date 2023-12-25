# Data-Structure-Project

## Table of Contents
- [Development Team](#development-team)
- [Library Management System](#library-management-system)
- [Key Operations for Users](#key-operations-for-users)
- [Description](#description)
- [Folder Structure](#folder-structure)
- [Code Structure Diagram](#code-structure-diagram)
- [Screenshots](#screenshots)
- [Update to v0.3](#update-to-v03)
- [Code Improvements](#code-improvements)
  - [General Improvements](#general-improvements)
    1. [Use Constants for Magic Numbers](#1-use-constants-for-magic-numbers)
    2. [Removal of clearScreen() Function](#2-removal-of-clearscreen-function)
    3. [Private Member Functions](#3-private-member-functions)
    4. [Function Declarations](#4-function-declarations)
    5. [Naming Conventions](#5-naming-conventions)
    6. [Error Handling](#6-error-handling)
    7. [Reorganizing Code Hierarchy](#7-reorganizing-code-hierarchy)
  - [Additional Improvements](#additional-improvements)
  
    8. [Limiting the Number of Orders](#8-limiting-the-number-of-orders)

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
- **Dr.Ali Hamza**

**Instructor:**
- **Eng. Dina Ehab**

## Library Management System

This C++ code implements a robust Library Management System (LMS) utilizing a double linked list data structure.

The program offers a user-friendly, menu-driven interface for efficiently managing a list of orders, each uniquely identified by a receipt number.

## Key Operations for Users

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

## Folder Structure

**Source_File Folder:**
Contains lecture materials in PDF format, each associated with specific order choices in the program.

For instance: "Lec01.pdf", "Lec02.pdf", ...

When a user selects a particular order linked to a lecture, the program seamlessly opens the corresponding PDF file. This integration enhances the user experience, providing access to relevant educational content associated with their order choices.

**History Folder:**
Stores historical data pertaining to orders and receipts.

- `counter_of_receipt.txt:` Maintains a count of issued receipts, incrementing with each printed receipt.
- `receiptX.txt:` Individual text files storing details of each receipt. The 'X' denotes the receipt number, and files are sequentially created and named. Each receipt file comprehensively includes order details, counts, prices, and the total receipt amount. Open these files using the default text editor (e.g., Notepad) for review.

## Code Structure Diagram

**Code Structure Diagram:**
For a visual representation of the code structure, please refer to the PDF document available in the `Source_File` folder. The document, named "Code_Structure_Diagram.pdf," provides insightful diagrams illustrating the architecture and organization of the code.

[View Code Structure Diagram (PDF)]((LMS)_Diagram.pdf)

![View Code Structure Diagram (Photo)]((LMS)_Diagram.png)

## Screenshots

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

## Screenshot

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


# Code Review and Enhancement

## ChatGPT 3.5 and Bard Feedback

We conducted a code review with both ChatGPT 3.5 and Bard, seeking feedback and suggestions for improvement. Here is a summary of their insights:

### Initial Ratings:
- ChatGPT 3.5: 7/10
- Bard: 8/10

### Feedback:
1. **Error Handling Enhancement:**
   - Both ChatGPT 3.5 and Bard suggested enhancing error handling.
   - ChatGPT 3.5 recommended using a distinctive color for error messages and introducing a 3-second pause to capture user attention.
   - Bard emphasized the importance of clear error messages for better user understanding.

2. **Code Structure and Readability:**
   - Bard provided feedback on improving code structure and readability.
   - Suggestions included adding comments for complex sections, breaking down long functions into smaller ones, and organizing code in a modular fashion.

### Updated Ratings:
- ChatGPT 3.5: 8/10 after initial edits
- Bard: 10/10 after initial edits

## Code Edits and Enhancements:

### Error Handling with Color Change:

In response to the feedback received, we implemented an enhanced error-handling mechanism. The key improvements include:

- **Red Color and Alert Sound:** Changed text color to red and added an alert sound to draw attention.
- **3-Second Pause:** Introduced a 3-second pause to allow users to focus on the error message.
- **Additional Context:** Displayed an additional error message to provide context.
- **Color Reset:** Reset the text color to its default state after displaying the error.

### Code Review and Refactoring:

Following Bard's advice, we conducted a thorough code review and implemented several enhancements:

- **Commenting:** Added comments to complex sections for better understanding.
- **Function Modularity:** Broke down long functions into smaller, more modular ones.
- **Organized Structure:** Improved the overall organization of the code for better readability.


## Update to v0.3

## Code Improvements

### General Improvements:

1. [Use Constants for Magic Numbers](#1-use-constants-for-magic-numbers)
2. [Removal of `clearScreen()` Function](#2-removal-of-clearscreen-function)
3. [Private Member Functions](#3-private-member-functions)
4. [Function Declarations](#4-function-declarations)
5. [Naming Conventions](#5-naming-conventions)
6. [Error Handling](#6-error-handling)
7. [Reorganizing Code Hierarchy](#7-reorganizing-code-hierarchy)

1. **Use Constants for Magic Numbers:**
   - Introduced a constant `MAX_ORDER_DETAILS` to replace magic numbers and improve code readability.
   - Example: `const int MAX_ORDER_DETAILS = 100;`

2. **Removal of `clearScreen()` Function:**
   - Removed the `clearScreen()` function due to portability concerns and to encourage the use of more portable methods.

3. **Private Member Functions:**
   - Utilized private member functions for improved encapsulation, modularity, and readability.
   - Private functions handle specific tasks related to managing library orders, maintaining a concise and focused public interface.

4. **Function Declarations:**
   - Declared member functions in the class and defined them outside the class for better organization and readability.

5. **Naming Conventions:**
   - Re-wrote all function names using camelCase coding style conventions for consistency and cleanliness.

6. **Error Handling:**
   - Enhanced error handling and input validation.
   - Added checks for the input stream's state to handle invalid inputs more gracefully.

7. **Reorganizing Code Hierarchy:**
   - Reorganized the hierarchical structure of the code for better flow and organization.

### Additional Improvements:

8. **Limiting the Number of Orders:**
   - Added a check in the `TakeOrder` function to limit the number of orders to `MAX_ORDER_DETAILS`.
   - Users will be informed when attempting to exceed the maximum number of allowed orders.

These improvements collectively contribute to cleaner code, better organization, and enhanced user experience. If further refinements or adjustments are needed, feel free to iterate on these improvements.

### Feedback Screenshots

1. **ChatGPT Feedback:**
   ![ChatGPT Feedback](/Documentation/ChatGPT_Screenshot.png)
   [here](https://chat.openai.com/share/55464afb-1c86-4ee0-8975-60986e9ea335).


2. **Bard Feedback:**
   ![Bard Feedback](/Documentation/Bard_Screenshot.png)
[View Code Review PDF](/Documentation/Code_Review_Summary_Bard.pdf)
### Updated Ratings After Edits:

- ChatGPT 3.5: 8/10
- Bard: 10/10

We appreciate the valuable feedback from ChatGPT 3.5 and Bard, which has contributed to the overall improvement of our code. If there are any additional suggestions or areas for further enhancement, we are open to feedback from the community and collaborators.

**@0xMoataz  
Version 04  
12/18/2023**
