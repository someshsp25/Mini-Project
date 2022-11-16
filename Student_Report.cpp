#include<iostream>
#include<fstream>
using namespace std;




// class of student
class student{
    int roll_no; //roll number of student
    string name; // name of the student
    float marks_maths; // marks in maths
    float marks_physics; // marks in physics
    float marks_chemistry; // marks in physics
    float total_marks; // total marks out of 300
    float percent; // percentage
public:
    void get_data();
    void put_data();
    void result();
    bool check_rollno(int);
};

//class funtion to input details of the students
void student :: get_data()
{
    cout<<"Enter name:";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter roll number:";
    cin>>roll_no;
    cout<<"Enter maths marks:";
    cin>>marks_maths;
    cout<<"Enter physics:";
    cin>>marks_physics;
    cout<<"Enter chemistry marks:";
    cin>>marks_chemistry;
}

void student :: put_data()
{
    cout<<"NAME:"<<name<<endl;
    cout<<"Roll Number:"<<roll_no<<endl;
    cout<<"MATHS:"<<marks_maths<<endl;
    cout<<"PHYSICS:"<<marks_physics<<endl;
    cout<<"CHEMISTRY:"<<marks_chemistry<<endl;
}

void student :: result()
{
    total_marks=marks_maths+marks_physics+marks_chemistry;
    percent=total_marks/3;
    cout<<"NAME:"<<name<<endl;
    cout<<"Roll Number:"<<roll_no<<endl;
    cout<<"MATHS:"<<marks_maths<<endl;
    cout<<"PHYSICS:"<<marks_physics<<endl;
    cout<<"CHEMISTRY:"<<marks_chemistry<<endl;
    cout<<"The pertage is:"<<percent;
}

//to check the roll number
bool student :: check_rollno(int num)
{
        if(num==roll_no)
        {
            return true;
        }
        else return false;
}

// function to input details to the file
void write_data()
{
    // student object 
    student s;

    fstream data;
    // opening file
    data.open("/home/jarvis/Mini Project/Student_Report.dat" , ios::app | ios:: binary);

    //taking values of student
    s.get_data();

    //writing data to file
    data.write((char*)&s , sizeof(s));

    //closing files 
    data.close();
}

void show_data()
{
    //student object
    student s;

    fstream data;
    // opening file
    data.open("/home/jarvis/Mini Project/Student_Report.dat",ios::in | ios:: binary);

    if(!data)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

    //pointer to start
    data.seekg(0);

    //reading data
    data.read((char*)&s , sizeof(s));

    // all the things in file
    while (!data.eof()) {
        s.put_data();
        data.read((char*)&s , sizeof(s));
    }

    //close file
    data.close();
}

void show_result(int roll_no)
{
    //student object
    student s;

    fstream data;
    // opening file
    data.open("/home/jarvis/Mini Project/Student_Report.dat",ios::in | ios::binary);

    if(!data)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

    //pointer to start
    data.seekg(0);

    //reading data
    data.read((char*)&s , sizeof(s));

    while(!data.eof())
    {
        if(s.check_rollno(roll_no))
        {
            s.result();
            break;
        }
        data.read((char*)&s , sizeof(s));
    }
}

// This is the interface of the program
void Interface()
{
    cout << "\033[2J\033[1;1H";
    cout<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"*             Student Report System           *"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl<<endl;
    cout<<"      Please enter any key to continue......"<<endl;
    cin.ignore();
    int exit=1;
    do
    {
    cout << "\033[2J\033[1;1H";
    cout<<"SELECT OPTIONS:"<<endl;
    cout<<"1.Add Student Details"<<endl;
    cout<<"2.Check Result"<<endl;
    cout<<"3.Show all Students details"<<endl;
    cout<<"4.EXIT"<<endl;
    cout<<"Select any option........."<<endl;
    cout<<">>";
    int option;
    cin>>option;
    switch(option)
    {
        case 1:
        {
            cout << "\033[2J\033[1;1H";
            cout<<"Add Student Details"<<endl;
            write_data();
            cout<<"DATA added successfully"<<endl;
            cin.ignore();
		    cin.get();
        }
        break;

        case 2:
        {
            cout << "\033[2J\033[1;1H";
            cout<<"Check Result"<<endl;
            cout<<"Enter Roll Number:"<<endl;
            int r_no;
            cin>>r_no;
            show_result(r_no);
            cin.ignore();
		    cin.get();
        }
        break;

        case 3:
        {
            cout << "\033[2J\033[1;1H";
            cout<<"ALL STUDENTS DETAILS....."<<endl;
            show_data();
            cin.ignore();
		    cin.get();
        }
        break;


        case 4:
        {
            exit=0;
        }
        break;

        default:
        {
            cout << "\033[2J\033[1;1H";
            cout<<"Invalid Input!!!"<<endl;
            cin.ignore();
		    cin.get();
        }
        break;
    }
    } while (exit);
    
}

int main()
{
    Interface();
}