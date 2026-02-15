/*
** EPITECH PROJECT, 2026
** INPUTCOMPONENT
** File description:
** nanotekspice
*/

#ifndef INPUTCOMPONENT
  #define INPUTCOMPONENT
  #include "IComponent.hpp"
  #include "AComponent.hpp"

namespace nts {
class InputComponent: public AComponent {
public:
  InputComponent() : _nextValue(nts::Undefined), _value(nts::Undefined) {}

  void simulate(std::size_t tick) override {
    if (tick <= _currentTick) return;
    _currentTick = tick;
    _value = _nextValue;
  }

  nts::Tristate compute(std::size_t pin) override { return _value; }

  void setValue(nts::Tristate val) { _nextValue = val; }

protected:
  nts::Tristate _nextValue;
  nts::Tristate _value;
};
}

#endif /* INPUTCOMPONENT */
