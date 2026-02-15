/*
** EPITECH PROJECT, 2026
** CONSTANTS
** File description:
** nanotekspice
*/

#ifndef CONSTANTS
  #define CONSTANTS
  #include "AComponent.hpp"
  #include "IComponent.hpp"

namespace nts {
class ConstantComponent: public AComponent {
public:
  ConstantComponent(nts::Tristate val) : _value(val) {}
  void simulate(std::size_t tick) override { (void)tick; }
  nts::Tristate compute(std::size_t pin) override { return _value; }

private:
  nts::Tristate _value;
};
}

#endif /* CONSTANTS */
