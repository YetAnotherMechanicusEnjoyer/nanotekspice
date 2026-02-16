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
  InputComponent() : _nextValue(Undefined), _value(Undefined) {}

  void simulate(std::size_t tick) override {
    if (tick <= _currentTick) return;
    _currentTick = tick;
    _value = _nextValue;
  }

  Tristate compute(std::size_t) override { return _value; }

  void setValue(Tristate val) { _nextValue = val; }

protected:
  Tristate _nextValue;
  Tristate _value;
};
}

#endif /* INPUTCOMPONENT */
