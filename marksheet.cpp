//SGPA RESULT PROGRAM

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
using namespace std;
#define N 10

// student class for student detail
class student
{
  char s_name[25], f_name[25], m_name[25], dob[20];
  char enroll[10], course[5], sess[8], roll_no[4], sem[2];

public:
  void sget() // get detail of student
  {
    cout << "Enter detail of student\n\n";
    cout << "Name :";
    gets(s_name);
    cout << "Father's name :";
    gets(f_name);
    cout << "Mother's name :";
    gets(m_name);
    cout << "DOB (dd/mm/yy)\n";
    cin >> dob;
    cout << "Enrollment no :";
    cin >> enroll;
    cout << "Roll no :";
    cin >> roll_no;
    cout << "Semester :";
    cin >> sem;
    cout << "Course :";
    cin >> course;
    cout << "Session :";
    cin >> sess;
  }

  void show() //display detail of student
  {
    cout << "ENROLLMENT NO :" << enroll << "\t\t";
    cout << "ROLL NO :" << roll_no << "\t"
         << "SEMESTER :" << sem << endl;
    cout << "NAME OF STUDENT :" << setw(23) << left << s_name << "DOB :" << dob << endl;
    cout << "FATHER's NAME :" << setw(23) << f_name << "\n"
         << "MOTHER's NAME :" << setw(23) << m_name << "COURSE :" << course;
    cout << "\tSESSION :" << sess;
  }
};

// subject class for subject detail 
class subject : public student
{
public:
  int no_subject;
  char su[N][25];
  int m[N], c[N], cp[N], tc, tcp, gp[N];
  void get_subject();
  void get_marks();
};

// get subject name
void subject::get_subject()
{
  cout << "How many subject in Your Semester :";
  cin >> no_subject;
  while(cin.fail()){
    cin.clear();
    cin.ignore(256,'\n');
    system("cls");
    cout<<"Enter valid input\n"<<"How many subject in Your Semester :";
    cin >> no_subject;
  }
  fflush(stdin);
  for (int i = 0; i < no_subject; i++)
  {
    cout << i + 1 << " subject Name :";
    gets(su[i]);
  }
}

// get subjects marks & credits

void subject ::get_marks() 
{
  int i;
  tc = 0;
  cout << "enter marks & credit of subject >>\n\n";
  for (i = 0; i < no_subject; i++)
  {
    cout << su[i] << endl;
    cout << "marks -";
    cin >> m[i];
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter valid Marks\n";
      cin >> m[i];
    }
    cout << "credit -";
    cin >> c[i];
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter valid Credit\n";
      cin >> c[i];
    }
    tc = tc + c[i];
    if (m[i] < 0 || m[i] > 100)
    {
      cout << "\nenter marks out of 100\n";
      tc = tc - c[i];
      i--;
    }
  }
}

class calculation : public subject
{
public:
  float sgpa();

  // get marks and return grade
  char *grade(int n)
  {
    if (n >= 90)
      return ("O");
    else if (n >= 80)
      return ("A+");
    else if (n >= 70)
      return ("A");
    else if (n >= 60)
      return ("B+");
    else if (n >= 50)
      return ("B");
    else if (n >= 40)
      return ("C");
    else if (n >= 35)
      return ("P");
    else
      return ("F");
  }
};

// sgpa calculation
float calculation::sgpa() 
{
  float sg;
  tcp = 0;
  for (int i = 0; i < no_subject; i++)
  {
    if (m[i] >= 90)
    {
      gp[i] = 10;
      cp[i] = 10 * c[i];
      tcp = tcp + cp[i];
    }
    else if (m[i] >= 80)
    {
      gp[i] = 9;
      cp[i] = 9 * c[i];
      tcp = tcp + cp[i];
    }
    else if (m[i] >= 70)
    {
      gp[i] = 8;
      cp[i] = 8 * c[i];
      tcp = tcp + cp[i];
    }
    else if (m[i] >= 60)
    {
      gp[i] = 7;
      cp[i] = 7 * c[i];
      tcp = tcp + cp[i];
    }
    else if (m[i] >= 50)
    {
      gp[i] = 6;
      cp[i] = 6 * c[i];
      tcp = tcp + cp[i];
    }
    else if (m[i] >= 40)
    {
      gp[i] = 5;
      cp[i] = 5 * c[i];
      tcp = tcp + cp[i];
    }
    else if (m[i] >= 35)
    {
      gp[i] = 4;
      cp[i] = 4 * c[i];
      tcp = tcp + cp[i];
    }
    else
    {
      gp[i] = 0;
      cp[i] = 0 * c[i];
      tcp = tcp + cp[i];
    }
  }
  sg = float(tcp) / tc; // calculate Sgpa
  return (sg);
}


// Display marksheet with all detail
class marksheet : public calculation
{
public:
  void design()
  {
    for (int i = 0; i <= 35; i++)
    {
      cout << "--";
    }
    cout << endl;
  }
  void result()
  {
    system("cls");
    design();
    cout << "                         Devi Ahilya Vishwavidyalaya\n";
    cout << "               Takshashila Campus, Khandwa Road, Indore (M.P)\n";
    cout << "                  School of Computer Science and IT (UTD)\n";
    design();
    show();
    cout << "\n";
    design();
    cout << setw(30) << left << "SUBJECT"
         << "CREDITS\t"
         << "GRADE\t"
         << "GRADE\t"
         << "CREDIT\n";
    cout << setw(53) << right << "POINT" << setw(9) << "POINT\n";
    design();
    float s = sgpa();
    for (int i = 0; i < no_subject; i++)
    {
      char *p = grade(m[i]);
      cout << setw(30) << left << su[i];         //SUBJECT
      cout << setw(4) << right << c[i] << "\t "; //CREDIT
      cout << setw(4) << left << p << "\t";      //GRADE
      cout << setw(4) << right << gp[i] << "\t"; //GRADE POINT  
      cout << setw(4) << right << cp[i] << endl; //CREDIT POINT
    }
    design();
    cout << "TOTAL" << setw(29) << tc << setw(26) << tcp << endl;
    design();
    cout << "SGPA" << setw(56) << setprecision(3) << s << endl;
    design();
  }
};

int main()
{
  system("cls");
  marksheet obj;
  obj.sget();
  system("cls");
  obj.get_subject();
  system("cls");
  obj.get_marks();
  obj.result();
  getch();
  return (0);
}