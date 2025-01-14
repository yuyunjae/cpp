#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define MAX_IDEA 100

class Brain {
 private:
  std::string ideas[MAX_IDEA];

 public:
  Brain();
  virtual ~Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);

  const std::string &getIdea(int i) const;
  void setIdea(int i, const std::string &str);
};

#endif
