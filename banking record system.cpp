//Banking Record system 

#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int record_ID = 0;
class account_query{
	private:
	    char account_number[20];
	    char firstName[15];
	    char lastName[15];
	    float total_Balance;
	public:
		account_query();
	    void read_data();
	    void show_data();
	    void writeRecord();
	    void readRecord();
	    void searchRecord();
	    void editRecord();
	    void deleteRecord();
};

account_query :: account_query(){
	account_number[20] = '*';
	firstName[15]= '*';
	lastName[15] = '*';
	total_Balance = 0;
}
void account_query::read_data()
{
	system("color 0c");
    cout<<"\nEnter Account Number: ";
    cin>>account_number;
    cout<<"Enter First Name: ";
    cin>>firstName;
    cout<<"Enter Last Name: ";
    cin>>lastName;
    cout<<"Enter Balance: ";
    cin>>total_Balance;
    cout<<endl;
}

void account_query::show_data()
{
	system("color 0a");
	cout << "[" << ++record_ID << "] ";
    cout<<"Account Number:\t"<< account_number <<endl;
    cout<<"    First Name:\t\t"<< firstName <<endl;
    cout<<"    Last Name:\t\t"<< lastName <<endl;
    cout<<"    Current Balance:\tR "<< total_Balance <<endl;
    cout<<"_________________________________________"<<endl;
}

void account_query::writeRecord()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}

void account_query::readRecord()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    
    if(!infile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    
    cout << "*****************************************" << endl;
	cout << "\t\tData from file" << endl;
	cout << "*****************************************" << endl;
	
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this)) > 0)
        {
            show_data();
        }
        else{
        	cout << "No Records found.\n" << endl;
		}
    }
    infile.close();
}

void account_query:: searchRecord()
{
    int recordNumber;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening!. Record Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    
    if(count == 0){
    	cout << "File empty.\n" << endl;
	}
	else{
	    cout<<"\nThere are "<< count <<" record in the file";
	    cout<<"\nEnter Record Number to Search: ";
	    cin>>recordNumber;
	    cout<<"_________________________________________"<<endl;
	    infile.seekg((recordNumber-1)*sizeof(*this));
	    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
	    show_data();
	}
}

void account_query::editRecord()
{
    int recordNumber;
    fstream iofile;
    iofile.open("record.bank", ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"\nError in opening!. Record Not Found!!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    if(count == 0){
    	cout << "No record to edit. File is empty.\n" << endl;
	}
	else{
	    cout<<"\nThere are "<< count <<" record in the file";
	    cout<<"\nEnter Record Number to edit: ";
	    cin>>recordNumber;
	    iofile.seekg((recordNumber-1)*sizeof(*this));
	    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
	    
	    cout<<"Record "<< recordNumber <<" has following data"<<endl;
	    cout<<"_________________________________________"<<endl;
	    show_data();
	    iofile.close();
	    iofile.open("record.bank", ios::out|ios::in|ios::binary);
	    iofile.seekp((recordNumber-1)*sizeof(*this));
	    
	    cout<<"\nEnter data to Modify "<<endl;
	    cout<<"*****************************************"<<endl;
	    read_data();
	    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
	}
}

void account_query::deleteRecord()
{
    int recordNumber;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening!. Record Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    
    if(count == 0){
    	cout << "No record to delete. File empty.\n" << endl;
	}
	else{
	    cout<<"\nThere are "<< count <<" record in the file";
	    cout<<"\nEnter Record Number to Delete: ";
	    cin>>recordNumber;
	    
	    fstream tmpfile;
	    tmpfile.open("tmpfile.bank", ios::out|ios::binary);
	    infile.seekg(0);
	    for(int i = 0; i < count; i++)
	    {
	        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
	        if(i == (recordNumber-1))
	            continue;
	        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
	    }
	    
	    infile.close();
	    tmpfile.close();
	    remove("record.bank");
	    rename("tmpfile.bank", "record.bank");
	    
	    cout << "Record " << recordNumber << " successfully is deleted." << endl;
	}
}

int main()
{
    account_query A;
    int choice;
    
    while(true)
    {
    	record_ID = 0;		//Reset record_ID 
    	system("cls");
    	system("color 0f");
    	cout<<"\n\n\n\t\t\t\t************************************************"<<endl;
	    cout<<"\t\t\t\t\tAcount Information System"<<endl;
	    cout<<"\t\t\t\t************************************************"<<endl;
        cout<<"\t\t\t\t\tSelect one option below " << endl;
        cout<<"\n\t\t\t\t\t1. Add record to file";
        cout<<"\n\t\t\t\t\t2. Show record from file";
        cout<<"\n\t\t\t\t\t3. Search Record from file";
        cout<<"\n\t\t\t\t\t4. Update Record";
        cout<<"\n\t\t\t\t\t5. Delete Record";
        cout<<"\n\t\t\t\t\t6. Quit";
        cout<<"\n\n\t\t\t\t\tEnter your choice: ";
        cin>>choice;
        
        system("cls");
        
        switch(choice)
        {
        	
        case 1:
            A.writeRecord();
            break;
        case 2:
            A.readRecord();
            system("pause");
            break;
        case 3:
            A.searchRecord();
            system("pause");
            break;
        case 4:
            A.editRecord();
            system("pause");
            break;
        case 5:
            A.deleteRecord();
            system("pause");
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nInput error. Please choose the correct option.";
            exit(0);
        }
    }
    
    system("pause");
    return 0;
}
