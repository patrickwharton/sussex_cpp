#ifndef SUSSEX_PERSON
#define SUSSEX_PERSON

#include <iostream>
#include <vector>
#include <string>
// doesnt actually work without Class.h

class MITPerson {
  static int person_count;
  protected:
    int id;
    std::string name;
    std::string address;
  public:
    MITPerson(int id, std::string name, std::string address);

    // overridden function uses virtual
    virtual void displayProfile();
    void changeAddress(std::string newAddress);
    static int getCount() {
      // can be accessed even if no people have been created
      return person_count;
    }
};

class Student : public MITPerson {
  int course;
  int year;
  // 1 = freshman, 2 = sophomore, etc
  std::vector<Class*> classesTaken;
  public:
    Student(int id, std::string name, std::string address,
    int course, int year);
    // override the method to display course & classes
    void displayProfile();
    void addClassTaken(Class* newClass);
    void changeCourse(int newCourse);
};

// might need some /this -> id = id\ etc etc

void MITPerson::displayProfile() {
 // definition in MITPerson
  std::cout << "-----------------------------\n";
  std::cout << "Name: " << name << " ID: " << id << " Address: " << address << "\n";
  std::cout << "-----------------------------\n";
}

void Student::displayProfile(){
 // definition in Student
  std::cout << "-----------------------------\n";
  std::cout << "Name: " << name << " ID: " << id << " Address: " << address << "\n";
  std::cout << "Course: " << course << "\n";
  std::vector<Class*>::iterator it;
  std::cout << "Classes taken:\n";
  for (it = classesTaken.begin(); it != classesTaken.end(); it++) {
      Class* c = *it;
      std::cout << c->getName() << "\n";
   }
 std::cout << "-----------------------------\n";
}
#endif
