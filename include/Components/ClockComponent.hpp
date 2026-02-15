/*
** EPITECH PROJECT, 2026
** CLOCKCOMPONENT
** File description:
** nanotekspice
*/

#ifndef CLOCKCOMPONENT
  #define CLOCKCOMPONENT
  #include "IComponent.hpp"
#include "InputComponent.hpp"

namespace nts {
class ClockComponent: public InputComponent {
public:
  void simulate(std::size_t tick) override {
    if (tick <= _currentTick) return;
    _currentTick = tick;

    if (_nextValue != nts::Undefined) {
      _value = _nextValue;
      _nextValue = nts::Undefined;
    } else {
      if (_value == nts::True) _value = nts::False;
      else if (_value == nts::False) _value = nts::True;
    }
  }

  nts::Tristate compute(std::size_t pin) override {
    return _value;
  }
};
}

#endif /* CLOCKCOMPONENT */
