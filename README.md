# Banking-Record-in-C++

#Program description
This is a simple banking record system project in C++. 
File handling is used in this project to store the records.

#features of this program
#Add Record:
For this feature void read_data() function has been used to add banking record into the file. 
It asks for account number, first name, last name, and balance to be entered by the user.

#Show Data:
The void show_data() function show the record corresponding to a particular account number, first name, last name and the current balance.

#Search Record:
The can shearch a record the by the record ID using.
When the function for this feature is first executed, it shows the total records in the file, and the user can then search by record ID. 
If the record searched for is not found, the error message  will be displayed – “Error in opening! File Not Found!!”

#Edit Record:
This works in similar manner to the Search feature. 
When the function for Edit Record is first executed, it shows the total records in the file, and the user can edit the information by providing record ID. 
Then, this project shows all the data in that record, and the user can enter any data to modify. 
If the record to be edited for is not found, it displays the error message – “Error in opening! File Not Found!!”

#Delete Record:
First, when the function of this feature is executed, it shows all the records in the file, and the user can enter the record ID to delete. 
If the record was not found, this  system  displays the error message – “Error in opening! File Not Found!!”

