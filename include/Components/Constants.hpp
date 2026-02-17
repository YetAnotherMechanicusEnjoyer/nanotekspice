/*
** EPITECH PROJECT, 2026
** CONSTANTS
** File description:
** nanotekspice
*/

#ifndef CONSTANTS
  #define CONSTANTS
  #include "IComponent.hpp"
  #include "InputComponent.hpp"

namespace nts {
class ConstantComponent: public InputComponent {
public:
  ConstantComponent(Tristate val) : _value(val) {}
  void simulate(std::size_t tick) override { (void)tick; }
  nts::Tristate compute(std::size_t) override { return _value; }

protected:
  Tristate _value;
};
}

#endif /* CONSTANTS */
