#ifndef EXAM_CLASSES
#define EXAM_CLASSES

#include <string>

using namespace std;

class person {
    bool alive, infected, immune;
    // int id;
  public:
    // static int person_count;
    // constructor
    person(bool a=true, bool i=false) {
      alive=a;
      infected=i;
      // person_count++;
      // id=person_count;
    }

    // copy constructor
    // person(const person& c) {alive=c.is_alive(); infected=c.is_infected();}


    // functions
    void kill_person() {alive = false;}
    void infect_person() {
      // if (!(is_immune())) {
        infected = true;
      // }
    }
    void cure_person() {infected = false; immune=true;}
    bool is_infected() {return infected;}
    bool is_alive() {return alive;}
    bool is_immune() {return immune;}
    //
    // person operator+(person p) {
    //   return new;
    // }

    // friends
    friend std::ostream& operator<<(std::ostream& os, const person p ) {
      std::string status = "dead";
      std::string infection = " and well";
      if (p.alive) {
        status = "alive";
      }
      if (p.infected) {
        infection = " but infected";
      }
      os << "person is " << status << infection;
      // << p.id
      return os;
    }
};


#endif
