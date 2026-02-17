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

    _value = _updateValue ? _nextValue : _value;
    _updateValue = false;
    if (_value == True || _value == False) _value = static_cast<Tristate>(!_value);
    else _value = Undefined;
  }

  Tristate compute(std::size_t pin) override {
    if (pin != 1) return Undefined;
    return _value;
  }

  void setValue(Tristate val) override {
    _nextValue = static_cast<Tristate>(!val);
    _updateValue = true;
  }

private:
  bool _updateValue{false};
};
}

#endif /* CLOCKCOMPONENT */
