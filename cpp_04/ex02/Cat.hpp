#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain *brain;

 public:
  Cat();
  virtual ~Cat();
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);

  virtual void makeSound() const;
  const Brain &getBrain() const;
  void setBrain(const Brain &brain);
};

#endif
