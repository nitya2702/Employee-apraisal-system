#include <iostream>
#include<string>
using namespace std;
 

class Employee{
    private:
        int ID, experience, project_completed, total_project, rating, N;
        string empName;
        double current_sal;

    public: 

    friend class HR;

    Employee(){}; //constructor 

    Employee(int ID,string empName,int project_completed,int total_project, double current_sal,int experience,int rating)
        {    
           cout<<"CONSTRUCTOR CALLED"<<endl;

           this->ID=ID;
           this->empName=empName;
           this->project_completed=project_completed;
           this->total_project=total_project;
           this->current_sal=current_sal;
           this->experience=experience;
           this->rating=rating;
           }

    ~Employee(){}; //Destructor 

    void setData() //data is taken by user
    {
        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cout<<"WELCOME TO EMPLOYEE MANAGEMENT SYSTEM"<<endl;

        cout<<"Enter the total number of Employees"<<endl;
        cin>>N;

        for(int i=1;i<=N;i++)
      {
        cout<<"Enter the name of the Employee"<<endl;
        cin>>empName;
        cout<<"Enter the id of the Employee"<<endl;
        cin>>ID;
        cout<<"Enter number of project completed"<<endl;
        cin>>project_completed;
        cout<<"Enter total number of projects alloted"<<endl;
        cin>>total_project;
        cout<<"Enter the current salary"<<endl;
        cin>>current_sal;
        cout<<"Enter the total years of experience"<<endl;
        cin>>experience;
        cout<<"Enter the rating for the Employee out of 10"<<endl;
        cin>>rating;

        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
      }
    }

    void appraisalEmployee() //calculation of appraisal score
    {  
        double appraisalScore;

        for(int i=1;i<=N;i++)
      {
        appraisalScore = (project_completed*100)/total_project;
        cout<<"\nThe employee name: "<<empName<<endl;
        cout<<"The appraisal score for current month is: "<<appraisalScore<<endl; //printing score
        }
    }
};
 
class GeneralManager : public Employee //inheritance
{
    private:
     string name;
    int IDGM, project_completedGM, total_projectGM, experienceGM, ratingGM;
    double appraisalScoreGM, current_salGM;

    public:
    void det()
    {
        cout<<"Enter the name of the General Manager"<<endl;
        cin>>name;
        cout<<"Enter the id of the General Manager"<<endl;
        cin>>IDGM;
        cout<<"Enter number of project completed"<<endl;
        cin>>project_completedGM;
        cout<<"Enter total number of projects alloted"<<endl;
        cin>>total_projectGM;
        cout<<"Enter the current salary"<<endl;
        cin>>current_salGM;
        cout<<"Enter the total years of experience"<<endl;
        cin>>experienceGM;
        cout<<"Enter the rating for the General Manager out of 10"<<endl;
        cin>>ratingGM;
    }

        void appraisalGM() //calculation of appraisal score
    {  
        double appraisalScoreGM;

        appraisalScoreGM = (project_completedGM*100)/total_projectGM;
        cout<<"\nThe General Manager name: "<<name<<endl;
        cout<<"The appraisal score for current month is: "<<appraisalScoreGM<<endl; //printing score
       }
};
 
class HR_Manager:public Employee
{
     public:
        string department="HR Department";
        string nameHR;
        double salaryHR;
        int experienceHR;
        HR_Manager()
        {
            cout<<"Enter employee name who is accessing the system"<<endl;
            cin>>nameHR;
            this->nameHR=nameHR;
            cout<<"Enter employee salary"<<endl;
            cin>>salaryHR;
            this->salaryHR=salaryHR;
            cout<<"Enter employee experience"<<endl;
            cin>>experienceHR;
            this->experienceHR=experienceHR;
        }

        string hrID="HR123";

        ~HR_Manager(){};

        void showEmployeeData()
        {
            hrID="HR123 "+this->nameHR;
            cout<<"Employee name is: "<<this->nameHR<<endl;
            cout<<"Employee salary is: "<<this->salaryHR<<endl;
            cout<<"Employee experience is: "<<this->experienceHR<<endl;
            cout<<"HR Department: "<<endl;
            cout<<"Employee id is "<<hrID<<endl;
        }
};
 
template< class T , int numOfData >
class Holder{
private:
    T object;
    int count;
public:
    Holder(){
        count = numOfData;
    }
    void inputItems(){
        cout << "You will be asked to enter " << count << "items" << endl;
        object.inputItems();
    }
};
 
class Employee1{
private:
    int EmployeeID;
    double EmployeeSalary;
public:
    Employee1(){
        EmployeeID = 0;
        EmployeeSalary = 0.00;
    }
    Employee1( int theEmployeeID , double theEmployeeSalary ){
        EmployeeID = theEmployeeID;
        EmployeeSalary = theEmployeeSalary;
    }
};
 
class Projectmanager{
private:
    int numOfDataElements;
public:
    Projectmanager(){
        numOfDataElements = 0;
    }
    Projectmanager( int numOfData ){
        numOfDataElements = numOfData;
    }
};
 
int main()
{
   Employee EE;
   EE.setData();
   EE.appraisalEmployee();

   GeneralManager GG;
   GG.det();
   GG.appraisalGM();

   HR_Manager h;
   h.~HR_Manager();
   h.showEmployeeData();

    Holder <Employee1 , 2> h11;
    Holder <Projectmanager , 12> h22;
 
    system( "pause" );
}