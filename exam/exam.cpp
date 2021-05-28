#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include "exam_classes.h"

using namespace std;

// set initial constants
const int M = 50000;
const float infect_chance = 0.5;
const float death_chance = 0.01;
const float recover_chance = 0.12;
const int initial_population = 200000;
const int initial_infected = 100;
// int current_population = initial_population;

double rnd(void) {
  // returns a random double between 0 and 1, uniformally distributed
  double number = rand() / (double)RAND_MAX;
  return number;
}

int random_int(int max_int) {
  // returns an int between 0 and max_int
  int new_int = rnd() * max_int;
  return new_int;
}

void setup(std::vector<person>& vect) {
  // create people
  for (int i = 0; i < initial_population; i++) {
    vect.push_back(person());
  }

  // initial infections
  for (int i = 0; i < initial_infected; i++) {
    int rand = random_int(initial_population);
    person current_person = vect.at(rand);
    current_person.infect_person();
    // std::cout << i << " " << current_person << '\n';

  }
}

void run_day(std::vector<person>& vect) {
  // std::vector<int> to_remove;
  // int count = 0;
  for (int i = 0; i < initial_population; i++) {
    // int rand = random_int(current_population);

    person current_person = vect.at(i);
    if (current_person.is_alive()) {
      if (current_person.is_infected()) {
        float prob = rnd();
        if (prob < 0.12) {
          current_person.cure_person();
        }
        if (prob > 0.99) {
          current_person.kill_person();
          // count++;
          // to_remove.push_back(i);
        }
      }
    }


    // std::cout << i << " " << current_person << '\n';

  }
  // for (int i = 0; i < count; i++) {
  //   vect.erase(to_remove.at(i));
  // }
}

void run_meetings(std::vector<person>& vect) {
  for (int i = 0; i < M; i++){
    int rand1;
    person person1;
    int rand2;
    person person2;
    do {
      rand1 = random_int(initial_population);
      person1 = vect.at(rand1);
    } while (!person1.is_alive());

    do {
      rand2 = random_int(initial_population);
      person2 = vect.at(rand2);
    } while (!person2.is_alive() & (rand1 != rand2));

  if ((person1.is_infected()) | (person2.is_infected())) {
    float rand = rnd();
    if (rand < 0.5) {
      if ((person1.is_infected()) & (!person2.is_immune())) {
        person2.infect_person();
      }
      if ((person2.is_infected()) & (!person1.is_immune())) {
        person1.infect_person();
      }
    }

  }
  }






}

int get_healthy(std::vector<person>& vect) {
  int healthy_count = 0;

  for (int i = 0; i < initial_population; i++) {
    person person_current = vect.at(i);
    if ((person_current.is_alive()) & (!person_current.is_infected())) {
      healthy_count++;
    }

  }

  return healthy_count;
}

int get_infected(std::vector<person>& vect) {
  int infected_count = 0;

  for (int i = 0; i < initial_population; i++) {
    person person_current = vect.at(i);
    if ((person_current.is_alive()) & (person_current.is_infected())) {
      infected_count++;
    }

  }

  return infected_count;
}

int get_immune(std::vector<person>& vect) {
  int immune_count = 0;

  for (int i = 0; i < initial_population; i++) {
    person person_current = vect.at(i);
    if ((person_current.is_alive()) & (person_current.is_immune())) {
      immune_count++;
    }

  }

  return immune_count;
}

int main(int argc, char const *argv[]) {
  // set random seed
  srand(time(NULL));

  // initialise vector
  std::vector<person> vect;
  std::vector<person>::iterator pos;

  setup(vect);
  // set day number
  int day;
  int dead = 0;



  freopen("results.txt", "w", stdout);
  for (day = 0; day < 366; day++) {
    run_meetings(vect);
    run_day(vect);
    int healthy = get_healthy(vect);
    int infected = get_infected(vect);
    int immune = get_immune(vect);
    int dead = initial_population - healthy - infected - immune;
    std::cout << day << ", " << healthy << ", " << infected << ", "  << immune << ", "  << dead << '\n';
  }



  return 0;
}
