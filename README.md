# Phone Directory using Trie (C++)

A console-based phone directory application built in C++ to practice the Trie data structure in a practical setting. The application allows users to add, search, delete, and display contacts while storing them in a text file so the data persists across program runs.
  
## Project Preview

![Project Preview](Screenshot%202026-06-30%20164133.png)

## Why this project

I wanted to build something where a Trie solves a real problem instead of implementing it as an isolated data structure. A phone directory is a natural use case because prefix-based searching is exactly what a Trie is designed for, making lookups more efficient than repeatedly scanning a list of contacts.

## Features

- Add a new contact (name + phone number)
- Search contacts by name (prefix search — type part of a name and it shows all matches)
- Search by exact phone number
- Display all saved contacts
- Delete a contact
- Data is saved to `sample_data.txt` so contacts persist between runs

## How it works

Each contact's name gets inserted into the Trie character by character (lowercase, with a separate slot for spaces so full names work too). Every node points to its children, and the last character of a name is marked as the end of a word, where the phone number is actually stored.

When you search by prefix, it walks down the tree following the characters you typed, then does a DFS from that point to collect every name branching off from there — so searching "ra" would show every contact starting with "ra".

Phone number search is done separately by scanning the data file directly since the Trie here is built on names, not numbers.

## Files

- `main.cpp` – entry point, loads existing contacts and starts the menu
- `PhoneDirectory.h / .cpp` – handles the menu, file loading, and phone search
- `Trie.h / .cpp` – the actual Trie logic (insert, search, delete, display)
- `Contact.h` – defines the Contact structure used in the project.
- `sample_data.txt` – stores contacts as name/phone pairs, one per line

Compile:

```bash
g++ main.cpp PhoneDirectory.cpp Trie.cpp -o phonedir
```

Run (Windows):

```bash
.\phonedir.exe
```

Run (Linux/macOS):

```bash
./phonedir
```

`sample_data.txt` needs to be in the same folder. It is used to load and save contacts.

## Things I'd improve if I had more time

- Add an option to update an existing contact.
- Improve the delete operation so unused Trie nodes are removed from memory.
- Make phone number search faster instead of checking the file line by line.
- Build a graphical (GUI) version of the application.

## What I learned

Building this project helped me understand how Tries work beyond textbook implementations. It also gave me hands-on experience with file handling, organizing a multi-file C++ project, and applying object-oriented programming to a complete application.
