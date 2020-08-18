                                                    The Telephone Book
Content:
•	Description
•	Algorithms Used
•	User manual
1. Description

The program we have created revolves around the idea of a telephone book which contains records of people with their names, date of birth, address, email and finally phone number. These records are all stored together in an array of structures and are accessed by the functions we developed which include:
    1.	Load

This is the first function found in our program. It transfers the comma separated values found in the text file into the different variables found in the structure of a record, so that data could be used in the following functions.
    2.	Search

Records can be easily accessed individually by the search function we have developed which provides both options of either searching by last name or also by the multi-search option which allows for more accurate results.
    3.	Add

With the use of this function, one can add a new record to the telephone book. The user is prompted to insert all the data about the new record which are then added to the first free index in the array of structures.
    4.	Delete

In contrast to the previous function, this function allows the user to choose a record which is then deleted from the book. The user is asked to enter the first and last name of the record to be deleted and if there is a match to the names inserted by the user then that record shall be deleted.
    5.	Modify

If one wants to change the information in one of the records then this function Modify allows such changes to take place. The user chooses which of the records he/she wants to change and then all variables in that one record are prompted to the user to renter again.
    6.	Sort

This function gives the user the chance to sort the records found in the given file. Records could be sorted either by last name of each record or by the date of birth of each record. The records are then printed on the screen after being sorted.
    7.	Save
    
After all the actions the user has done on the records, when this function is called, all the changes the user did on the records whether modifying a record, deleting a record or even adding a new one are then written on the file so if the user decides to load the text file again then those changes will appear to be saved.
    8.	Quit

 When the user decides to quit the program this function is called and it gives a warning to remind the user to save the data before quitting as if the data wasn’t saved using function no.7 (Save) then all the changes wouldn’t be written on the text file.


2. Algorithms Used

    •	Bubble sort was used in function no.6 (Sort) where records are sorted either according to the last name or to the date of birth. Using the bubble sort, records are sorted in an ascending manner in both ways, so using sorting with last name Ahmed comes before Ziyad as well as a person born in 1980 comes before a person born in 1990.
   
    •	The function strtok() was used to tokenize strings in the text file. The file would be read line by line and in each iteration the line is separated into several tokens so each token could be stored in a variable in the array of structures.

3. User manual

When the user first runs the program he is presented with this main menu which includes multiple options to choose from.
Before the user starts dealing with the records, the text file should be first loaded so the data in it is then stored in the array of structures. Therefore when the user first runs the program, he is prompted to insert the number (1) so the file gets loaded before getting into the other functions. Then after getting finished with any of the functions the user returns back to the main menu and is prompted to insert the number of the function to be used next.
    1.	Load

Once this function is called all the records found in the text file are printed out on the running screen of the program.
    2.	Search

The user is given a choice whether to search with the last name of the person or using a multi search option. In the multi search, if the user doesn’t want to search using a certain field then he could just enter a blank space which the program translates as skipping that field when searching for the record.
    3.	Add

In this function the user adds a new record to the telephone book. The user is prompted to enter each field in the new record and validations are done to prevent mistakes in entries occurring.
    4.	Delete

When this is called the user is asked to insert the first and last name of the record to be deleted. If a match is found the user is asked whether it is this record that he wants to delete. If it is indeed the right record the user then enters (1) which then deletes the record from the array of structures.
    5.	Modify

If a record that already exists in the file needs to be modified then this function is called. It gives the user the chance to change every field in that particular record by asking for the information to be reentered by the user so if the user wants to change one or more of the fields then he is allowed to enter different data.
    6.	Sort

Records are naturally unsorted given that they are loaded directly as they are saved in the text file so if the user would like to have them sorted he is given the option either to be sorted by last name or by the date of birth, both in ascending order.
    7.	Save

All the changes the user has done would not be saved in the file if this function is not used. A message is displayed to show that the data has been saved. 
    8.	Quit
    
After all the changes have been done, this is used to terminate the program. A warning pops up to remind the user to save the changes before quitting the program. 
