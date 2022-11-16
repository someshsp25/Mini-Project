import java.io.*;
import java.util.*;

// class student 
class student implements Serializable{
    private String name;
    private int roll_no;
    private float marks_maths; // marks in maths
    private float marks_physics; // marks in physics
    private float marks_chemistry; // marks in physics
    private float total_marks; // total marks out of 300
    private float percent; // percentage
    public void get_data()
    {
        System.out.println("Enter Name:");
        Scanner in = new Scanner(System.in);
        name = in.nextLine();
        System.out.println("Enter roll number:");
        roll_no = in.nextInt();
        System.out.println("Enter marks of physics:");
        marks_physics = in.nextFloat();
        System.out.println("Enter marks of chemistry:");
        marks_chemistry = in.nextFloat();
        System.out.println("Enter marks of maths:");
        marks_maths = in.nextFloat();
    }
    public void put_data()
    {
        System.out.println("Name:"+name);
        System.out.println("Roll Number:"+roll_no);
        System.out.println("Physics:"+marks_physics);
        System.out.println("Chemistry:"+marks_chemistry);
        System.out.println("Maths:"+marks_maths);
    }
    public void result()
    {
        System.out.println("Name:"+name);
        total_marks=marks_maths+marks_physics+marks_chemistry;
        percent=total_marks/3;
        System.out.println("Roll Number:"+roll_no);
        System.out.println("Physics:"+marks_physics);
        System.out.println("Chemistry:"+marks_chemistry);
        System.out.println("Maths:"+marks_maths);
        System.out.println("Percentage:"+percent);
    }
    public boolean check_rollno(int num)
    {
        if(num==roll_no)
        {
            return true;
        }
        else return false;
    }
}
class Student_Report{
    public static void write_data() throws Exception
    {
        // student object s
        student s = new student();
        
        // object to open file and write data
        File data =new File("Student_Report.dat");

        // input data in object s
        s.get_data();

        //writing data into file
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(data));
        oos.writeObject(s);

        // closing file
        oos.close();

    }

    public static void show_data() throws Exception
    {
        File data = new File("Student_Report.dat");

        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(data));

        boolean cond = true;

        while(cond)
        {
            student s = (student)ois.readObject();
            if(s!=null)
            {
                s.put_data();
            }
            else{
                cond=false;
            }
        }
        ois.close();

    }

    public static void show_result (int roll_no) throws Exception
    {
        File data = new File("Student_Report.dat");

        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(data));

        boolean cond = true;

        while(cond)
        {
            student s = (student)ois.readObject();
            if(s!=null)
            {
                if(s.check_rollno(roll_no))
                {
                    s.result();
                    break;
                }
            }
            else{
                cond=false;
            }
        }
        ois.close();

    }
    public static void screen()
    {
        System.out.println("\033[2J\033[1;1H");
        System.out.println("Student Report System");
        System.out.println("Select any option:");
        System.out.println("1.Add Student Details");
        System.out.println("2.Check Result");
        System.out.println("3.Show all Students details");
        System.out.println("4.Exit");
        int option;
        Scanner input = new Scanner(System.in);
        while(true)
        {
            option = input.nextInt();
        switch(option)
        {
            case 1:
            {
                System.out.println("\033[2J\033[1;1H");
                System.out.println("Add Student details:");
                write_data();
            }
            break;

            case 2:
            {
                System.out.println("\033[2J\033[1;1H");
                System.out.println("Check Result:");
                System.out.println("Enter roll number:");
                int r_no;
                Scanner in = new Scanner(System.in);
                r_no = in.nextInt();
                show_result(r_no);
            }
            break;

            case 3:
            {
                System.out.println("\033[2J\033[1;1H");
                System.out.println("Show all students results:");
                show_data(); 
            }
            break;

            case 4:
            {
                break;
            }
            break;

            default:
            {
                System.out.println("Invalid Input");

            }
            break;
            
        }
        }

    }

    public static void main(String args[])
    {
        screen();
    }
}