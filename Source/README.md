# Source Code – Inverted Search Index

## Overview
This folder contains the complete **source code implementation** of the Inverted Search Index project.  
The code is modularized to clearly separate **data structures**, **file processing**, and **index creation logic**, making the project easier to understand, debug, and extend.

The implementation is written in **C** and follows a structured, function-oriented design.

---

## Design Philosophy
- Clear separation of responsibilities
- Use of simple and efficient data structures
- Readability over unnecessary optimization
- Focus on correctness and scalability

Each source file handles **one specific task**, avoiding monolithic logic.

---

## Source Files Description

### `main.c`
- Entry point of the program
- Validates command-line arguments
- Initiates file list creation
- Triggers inverted index creation
- Displays the final indexed output

---

### `main.h`
- Contains all structure definitions
- Macro declarations
- Function prototypes
- Central header included across source files

---

### `char_to_int.c`
- Converts the first character of a word into a hash index
- Maps:
  - `A–Z` → indices `0–25`
  - Digits / special characters → index `26`
- Ensures uniform hashing logic across the project

---

### `int_to_char.c`
- Converts hash index back to readable character
- Used during display and debugging
- Improves output clarity

---

### `compare_sll.c`
- Creates and manages the **single linked list of input files**
- Prevents duplicate file entries
- Helps maintain a clean file list before indexing

---

### `remove_dup.c`
- Removes duplicate filenames from input
- Ensures the same file is not processed multiple times
- Improves indexing accuracy

---

### `create_main_node.c`
- Creates nodes for the **main linked list**
- Each node represents a **unique word**
- Stores:
  - Word
  - File count
  - Pointer to sub linked list

---

### `create_sub_node.c`
- Creates nodes for the **sub linked list**
- Each node represents:
  - File name
  - Word occurrence count in that file
- Attached to corresponding main node

---

### `insert_at_last.c`
- Generic utility function
- Inserts nodes at the end of linked lists
- Used for both main and sub linked lists where applicable

---

## Data Structure Summary
- **Hash Table (size 27)**
- **Main Linked List**
  - Stores unique words
- **Sub Linked List**
  - Stores file names and frequency counts

This layered structure enables efficient word-based searching across multiple files.

---

## Notes for Reviewers
- Code avoids global logic where possible
- All memory allocations are explicit
- Functions are designed to be reusable
- Suitable for demonstrating:
  - Hashing
  - Linked lists
  - File handling
  - Modular C programming

---

## Author
Vijay M

