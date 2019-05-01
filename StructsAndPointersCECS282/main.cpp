//Nikki Nguyen
//CECS 282
//Prog 3 - Structs and Pointers
//March 14, 2017
//
#include "myDate.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

struct student{
    int ID;
    char name[30];
    char letterGrade[2];
    int grade;
    char home[30];
    myDate Bday;
    
    
    
};

int main() {
    student myClass[10] = {{1007, "Sterling Archer", "F", 54,"Danger Zone", myDate(5,23,1995)},
                            {2608, "Lana Kane", "C", 72,"Berkeley", myDate(9,18,1995)},
                            {3645, "Cyril Figgis","B", 87, "Figgis Agency", myDate(2,5,1996)},
                            {4283, "Cheryl Tunt","A", 92, "Tunt Manor", myDate(7,20,1997)},
                            {5350, "Raymond Gillette","A", 98, "West Virginia", myDate(1,8,1995)},
                            {6404, "Algernop Krieger","A", 91, "Germany", myDate(8,18,1995)},
                            {7032, "Pamela Poovey","F", 56, "Poovey Farms", myDate(6,6,1996)},
                            {8965, "Malory Archer","C", 70, "Manhattan", myDate(1,31,1998)},
                            {9062, "Barry Dylan","B", 89, "Space Station", myDate(5,1,1997)},
                            {1182, "William Woodhouse","D", 63, "Tangier", myDate(5,20,1999)}};
    student *ptrOriginal[10];
    student *ptrID[10];
    student *ptrName[10];
    student *ptrLetterGrade[10];
    student *ptrGrade[10];
    student *ptrHome[10];
    student *ptrBday[10];
    void display(student* ptr[]);
    void bubbleID(student*ptr[]);
    void bubbleName(student*ptr[]);
    void bubbleLetterGrade(student*ptr[]);
    void bubbleGrade(student*ptr[]);
    void bubbleHome(student*ptr[]);
    void bubbleAge(student*ptr[]);
    
    //point to next thing
    for (int i = 0; i < 10; i++){
        ptrOriginal[i] = &(myClass[i]);
        ptrID[i] = &(myClass[i]);
        ptrName[i] = &(myClass[i]);
        ptrLetterGrade[i] =&(myClass[i]);
        ptrGrade[i] = &(myClass[i]);
        ptrHome[i] = &(myClass[i]);
        ptrBday[i] = &(myClass[i]);
        
        //ptr[i] = &(student[i])
        //ptr++=student++
        
    }
    
    
    
    display(ptrOriginal);
    bubbleName(ptrName);
    bubbleLetterGrade(ptrLetterGrade);
    bubbleGrade(ptrGrade);
    bubbleAge(ptrBday);
    bubbleID(ptrID);
    bubbleHome(ptrHome);
    
    
    int menuLoop = true;
    while(menuLoop){
        cout<<"\n\n";
        cout<<"Student List\n";
        cout<<
            "1) Display original list\n"
            "2) Display list sorted by Student ID\n"
            "3) Display list sorted by Name\n"
            "4) Display list sorted by Grade\n"
            "5) Display list sorted by Home Town\n"
            "6) Display list sorted by Student Age\n"
            "7) Exit\n";
        int menuChoice;
        cin>>menuChoice;
        switch(menuChoice){
            case 1:{
                cout<<"\n\n";
                cout<<"Original List";
                cout<<"\n\n";
                display(ptrOriginal);
                break;
            }
            case 2:{
                cout<<"\n\n";
                cout<<"List by ID";
                cout<<"\n\n";
                display(ptrID);
                break;
            }
            case 3:{
                cout<<"\n\n";
                cout<<"List by Name";
                cout<<"\n\n";
                display(ptrName);
                break;
            }
            case 4:{
                cout<<"\n\n";
                cout<<"List by Grade";
                cout<<"\n\n";
                //display(ptrLetterGrade);
                display(ptrGrade);
                break;
            }
            case 5:{
                cout<<"\n\n";
                cout<<"List by Home Town";
                cout<<"\n\n";
                display(ptrHome);
                break;
            }
            case 6:{
                cout<<"\n\n";
                cout<<"List by Birthdate";
                cout<<"\n\n";
                display(ptrBday);
                break;
            }
            case 7:{
                cout<<"";
                cout<<"Goodbye!\n";
                menuLoop = false;
                break;
            }
        }
    }
    return 0;

}

void display(student*ptr[]){
    cout<<left<<setw(31)<<"Student ID";
    cout<<setw(24)<<"Name";
    cout<<setw(21)<<"Grade";
    cout<<setw(24)<<"Home Town";
    cout<<setw(15)<<"Birthday";
    cout<<"\n";
    cout<<left<<setw(31)<<"-------------";
    cout<<setw(24)<<"-------";
    cout<<setw(21)<<"--------";
    cout<<setw(24)<<"------------";
    cout<<setw(15)<<"-----------";
    cout<<"\n";
    for(int i = 0; i < 10; i++){
        cout<<left<<setw(31)<<ptr[i]->ID<<setw(24)<<ptr[i]->name<<ptr[i]->letterGrade<<" "<<setw(19)<<ptr[i]->grade<<setw(24)<<ptr[i]->home;
        ptr[i]->Bday.display();
        cout<<"\n\n";
    }
}

void bubbleID(student*ptr[]){
    student *temp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <10; j++){
            if(ptr[i]->ID < ptr[j]->ID){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    
}

void bubbleName(student*ptr[]){
    student *temp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <10; j++){
            //compare string
            if(strcmp(ptr[i]->name, ptr[j]-> name) < 0){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}
void bubbleLetterGrade(student*ptr[]){
    student *temp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <10; j++){
            if(strcmp(ptr[i]->letterGrade, ptr[j]-> letterGrade) < 0){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}
void bubbleGrade(student*ptr[]){
    student *temp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <10; j++){
            if(ptr[i]->grade > ptr[j]->grade){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
    
}

void bubbleHome(student*ptr[]){
    student *temp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <10; j++){
            if(strcmp(ptr[i]->home, ptr[j]-> home) < 0){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}


void bubbleAge(student*ptr[]){
    student *temp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <10; j++){
            if(ptr[i]->Bday.compareTo(ptr[j]->Bday) > 0){
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}


