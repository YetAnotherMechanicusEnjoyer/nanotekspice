/*
** EPITECH PROJECT, 2026
** OUTPUTCOMPONENT
** File description:
** nanotekspice
*/

#ifndef OUTPUTCOMPONENT
  #define OUTPUTCOMPONENT
  #include "IComponent.hpp"
  #include "AComponent.hpp"

namespace nts {
class OutputComponent: public AComponent {
public:
  void simulate(std::size_t tick) override { (void)tick; }
  Tristate compute(std::size_t) override {
    return getPinValue(1);
  }
};
}

#endif /* OUTPUTCOMPONENT */
