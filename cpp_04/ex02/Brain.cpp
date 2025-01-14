#include "Brain.hpp"

Brain::Brain() {
  //   this->ideas = new std::string[MAX_IDEA];
  std::cout << "Brain Default Constructor called\n";
}

Brain::~Brain() {
  //   delete this->ideas;
  std::cout << "Brain Destructor called\n";
}

Brain::Brain(const Brain &other) {
  std::cout << "Brain Copy Constructor called\n";
  //   this->ideas = new std::string[MAX_IDEA];
  for (int i = 0; i < MAX_IDEA; i++) {
    this->ideas[i] = other.ideas[i];
  }
}

Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain Copy assignmnt operator called\n";
  if (this != &other) {
    for (int i = 0; i < MAX_IDEA; i++) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}

const std::string &Brain::getIdea(int i) const {
  static const std::string empty = "";
  if (i >= 0 && i < 100) return this->ideas[i];
  std::cout << "index error! idea index should >= 0 && < 100)\n";
  return empty;
}

void Brain::setIdea(int i, const std::string &str) {
  if (i >= 0 && i < 100) {
    this->ideas[i] = str;
  } else
    std::cout << "index error! idea index should >= 0 && < 100)\n";
}
