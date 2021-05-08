# Directory_Management

## How to Compile

To compile the code run the command "make a" int your terminal.

If you do not have make installed then you will have to install it by using "sudo apt install make".

## Commands

- Add
- Move
- Alias
- Teleport
- Find
- Find All
- List
- Relative Directory
- Help

### Add

To add a file in the current directory - $add fi \<File Name>

To add a folder in the current directory - $add fo \<Folder Name>

_Note: File and Folder names should not have spaces_

### Move

To move to a directory, give the complete path name to that directory - $move \<Complete Path Name>

### Alias

You can add an alias to a directory in the following way - $alias \<Alias Name> \<Complete Path Name>

### Teleport

Used to move instantly to a directory which has an alias - $teleport \<Alias Name>

### Find 

To Find through all the files and folders in a directory - $find \<String To Find>

### List 

To print all the files and folders in the current directory - $ls

### Relative Directory

To change the directory using the relative path to the new directory - $rd \<Path Name>

_Note: '..' refers to the parent directory and '.' refers to the current directory path_

### Find All

To Find through all the files and folders in a directory which have any substring of theirs matching the string used to search it - $findall \<String To Find>

_Note: Strings cannot have spaces in them_


### Help

shows a manual which shows how to use each and every function - $man
