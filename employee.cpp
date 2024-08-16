#include<iostream>
#include<string>
// Object Oriented Programming in C++
// 4 pillars of OOP: Abstraction, Inheritance, Encapsolation, and Polymorphism
// within Encapsolation are access modifiers, Public, Private and Protected

// include the input output stream library as well as string because both are not in regular C++
// for consistency just put the libraries at the top of the code

using namespace std;
// Without using namespace std or namespaces in general-
// -you would need to prefix std:: to every line of code that uses something from std-
// -like std::cout for example
// tldr using namespace just makes it easier to use std stuff
// every line of code must end in a semicolon, ;


// abstraction: is basically just hiding all the complicated stuff in other classes
// for example Abstract_Employee's canbePromoted code is being hidden inside of the class Employee 
class Abstract_Employee{
    virtual void canbePromoted()=0;
    // virtual checks whether this function has been implemented in other classes
    // The =0 syntax is used to declare a pure virtual function.
    // A pure virtual function does not provide an implementation in the base class and must be overridde-
    // -in any derived class.
    // virtual and =0 makes it mandatory to make code for the code inside of an abstract class
};


// classes are complex data structures that contain many properties(variables such as string, ints and chars)
// this is a parent class which is used for inheritance, meaning that this code can be used by children classes
// children classes use the same code from their parents and add on traits that are unique to children
// Employee is also a child of Abstract_Employee, the ": class" indicates that it is-
// -inheriting info from another class
// each class has a method and property
// A method is an action that the object can take (Function).
// A property is a data value that you can read or change (Variable).
class Employee: Abstract_Employee{
    // Encapsolation has access modifiers, 3 types of access modifiers
    // public: everything in the class can be accessed anywhere
    // private: everything is hidden and cant be used except within that class
    // protected: is like private but can be accessed by children via inheritance
protected:
    // properties 
    string Name;
    string Role;
    int Age;
public:

    // constructor, is a special method that is automatically called when an object of a class is created.
    // its what u use to call a class in main or in other functions
    // basically the usage, like Employee Jashlei similar to int Age
    // the constructor must be the same as the name of the class and must not have a data type
    // the constructor must take in variables that are the same as the properties-
    // -tho the only difference is the name which can have minor differences like capitalization
    // if you do not declare your own constructor, there will be a default constructor but it is better if u create one urself
    Employee(int age, string name, string role){
        Age = age;
        Name = name;
        Role = role;
    }

    // setters and getters are used in Encapsolation
    // setters are used to update a property
    // ex: Employee1.setName(Jashlei);
    void setName(string name){
        Name = name;
    }
    // getters allow you to access the properties that have been hidden in private or protected
    // Employee1.getName() is going to give you the name of that Employee
    string getName() {
        return Name;
    }
    void setRole(string role){
        Role = role;
    }
    string getRole() {
        return Role;
    }
    void setAge(int age){
        Age = age;
    }
    int getAge() {
        return Age;
    }

    // class methods(functions)
    void introduce() {
        // cout displays data into the terminal
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Role: " << Role << endl << endl;
    }
    
    void canbePromoted() {
        // conditional
        if (Age >= 20){
            cout << "Congratulations " << Name << " you are promoted!" << endl;
        }
        else {
            cout << "Boohoo so sad, no promotion for you" << endl;
        }
    }
    // Polymorphism (many form method)
    // the method may do different things despite having the same name
    // different function depending if it was called in a parent or a child class
    // example: this Work method is also present in child classes, Programmer and Artist
    // virtual could be added to Work as it checks if this method is present in other child
    // classes and uses those instead of the parent's
     void Work(){
        cout << getName() << " is working" << endl;
    }
};
// derived class / child
class Programmer: public Employee{ // inheritance
public:
    // declare the unique property or method in the child class
    string Fav_programming_language;
    // constructor in children
    // add the new property of the child into this new constructor which takes in the same as the parent
    // in this case Programmer still has age, name and role like Employee but unlike employee it has a fav_programming_language
    Programmer(int age, string name, string role, string fav_programming_language)
        :Employee(age, name, role)
    {
        Fav_programming_language = fav_programming_language;
    }
    // child specific method
    // this is something only the child can do and the parent cannot
    void make_program(){
        cout << getName() << " is making a program" << endl;
    }
    // Polymorphism, also present in the parent Employee and child Artist
    void Work(){
        cout << getName() << " is working on a program" << endl;
    }
    void Programming_language(){
        cout << getName() << " is coding in " << Fav_programming_language << endl;
    }
};

class Artist: public Employee{
public:
    // child Artist is the same as Programmer in the sense that is has something unique about it
    // an Artist has a favourite brush while a Programmer does not and vise versa
    string Favourite_brush;

    Artist(int age, string name, string role, string favourite_brush)
        :Employee(age, name, role)
    {
        Favourite_brush = favourite_brush;
    }
    // child specific method
    void draw(){
        cout << getName() << " is drawing" << endl;
    }
    // Polymorphism, also present in the parent Employee and child Programmer
    void Work(){
        cout << getName() << " is working on his painting" << endl;
    }

    void Brush(){
        cout << getName() << " is using the " << Favourite_brush << " brush" << endl;
    }

};

int main (void)
{
    // child class artist and programmer, but both are employees because they share the same parent-
    // -thus have similar traits
    Artist Omar = Artist(19, "Omar", "Artist", "Round");
        Omar.introduce();
    Programmer Jash = Programmer(18, "Jash", "Programmer", "C++");
        Jash.introduce();
        
    Employee French = Employee(19, "French", "Photographer");
        // update omar's age
        Omar.setAge(20);

        cout << Omar.getName() << " is " << Omar.getAge() << " years old" << endl;

        // canbePromoted is a parent method thus it can called by both children
        Omar.canbePromoted();
        Jash.canbePromoted();
        // make_program and draw are derived/child methods that are unique to each children
        Jash.make_program();
        Omar.draw();

        // same with Brush and Programming_language
        Omar.Brush();
        Jash.Programming_language();

        // class pointers that point to their children
        // pointers are variables that point to a specific address that contains a value
        // a pointer is defined by "variable* name" and an address is defined by "&variable_name"
        Employee* n1 =&Omar;
        Employee* n2 =&Jash;

        // example of polymorphism, Work is present in employee, programmer and artist
        // Work will normally output the children's method because of polymorphism
        Omar.Work();
        Jash.Work();
        French.Work();

        // n1-> and n2-> are pointers that point to their respective addresses and they use the method-
        // -within the parent class instead of their children
        n1->Work();
        n2->Work();
        // return 0 means the program worked successfully
        return 0;

}