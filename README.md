# Inverted Search Index (C)

## Overview
This project implements an **Inverted Search Index** in **C**, designed to efficiently search words across multiple text files.  
Instead of scanning files repeatedly, the program preprocesses the data and builds an index that maps:

**Word → File names → Occurrence count**

This technique is widely used in search engines and document indexing systems.

---

## Real-World Analogy
Similar to the index section at the back of a textbook:
- You search for a word
- The index tells you where it appears
- Along with how frequently it occurs

This project follows the same concept, but across multiple text files.

---

## Technical Description
- Uses a **Hash Table** of size 27
  - Index `0–25` → Words starting with `A–Z`
  - Index `26` → Digits and special characters
- Each hash index contains a **main linked list** for unique words
- Each main node contains a **sub linked list** storing:
  - File name
  - Word occurrence count in that file

---

## Data Structure Representation
Hash Table (27)

Index 0 → word → file1 (count) → file2 (count)
Index 1 → NULL
...
Index 26 → word → file3 (count)

---

## Program Flow
1. Validate input files
2. Remove duplicate file names
3. Ignore empty files
4. Read words from each file
5. Generate hash index using first character
6. Insert or update word and file count
7. Display the inverted index

---

## File Structure
| File | Description |
|-----|------------|
| main.c | Main program logic |
| main.h | Structure definitions |
| create_main_node.c | Creates main linked list nodes |
| create_sub_node.c | Creates sub linked list nodes |
| remove_dup.c | Removes duplicate file names |
| compare_sll.c | Builds single linked list of files |
| insert_at_last.c | Inserts nodes at the end |
| char_to_int.c | Hash index calculation |
| int_to_char.c | Reverse mapping |
| Makefile | Build automation |

---

## Hash Function Logic
- Words starting with alphabets → `A–Z`
- Words starting with digits or symbols → index `26`
- Case-insensitive processing

---

## Compilation
Use the following command to compile the project:

make

---

## Execution
Run the program with input text files:

./inverted_search filename1.txt filename2.txt filename3.txt

---

## Features
- Efficient word searching using inverted indexing
- Supports multiple input text files
- Avoids duplicate file processing
- Counts word occurrences per file
- Case-insensitive indexing

---

## Limitations
- Supports only text files
- Exact word matching only
- Fixed-size hash table

