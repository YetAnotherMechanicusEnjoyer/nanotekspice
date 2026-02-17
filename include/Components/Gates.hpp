/*
** EPITECH PROJECT, 2026
** GATES
** File description:
** nanotekspice
*/

#ifndef GATES
  #define GATES
  #define DEFAULT_OUTPUT 3
  #define SINGLE_OUTPUT 2
  #include "AComponent.hpp"
  #include "IComponent.hpp"
  #include <functional>

namespace nts {
class GateComponent: public AComponent {
public:
  using LogicOp = std::function<Tristate(Tristate, Tristate)>;

  GateComponent(LogicOp op, std::size_t outputPin = DEFAULT_OUTPUT) : _op(std::move(op)), _outputPin(outputPin) {}
  virtual ~GateComponent() = default;

  Tristate compute(std::size_t pin) override {
    if (pin != _outputPin) return Undefined;

    if (_cache.contains(pin) && _cache[pin].first == _currentTick)
      return _cache[pin].second;

    Tristate v1 = getPinValue(1);
    Tristate v2 = (_outputPin == SINGLE_OUTPUT) ? Undefined : getPinValue(2);

    Tristate res = _op(v1, v2);
    _cache[pin] = { _currentTick, res };
    return res;
  }

  void simulate(std::size_t tick) override { _currentTick = tick; }

private:
  std::function<Tristate(Tristate, Tristate)> _op;
  std::size_t _outputPin;
};

struct Operators {
  static Tristate ntsAnd(Tristate a, Tristate b) {
    if (a == Undefined || b == Undefined) return Undefined;
    return (a == True && b == True) ? True : False;
  }
  static Tristate ntsOr(Tristate a, Tristate b) {
    if (a == Undefined || b == Undefined) return Undefined;
    return (a == True || b == True) ? True : False;
  }
  static Tristate ntsXor(Tristate a, Tristate b) {
    if (a == Undefined || b == Undefined) return Undefined;
    return (a == b) ? False : True;
  }
  static Tristate ntsNot(Tristate a, Tristate) {
    if (a == Undefined) return Undefined;
    return a == True ? False : True;
  }
  static Tristate ntsNor(Tristate a, Tristate b) {
    if (a == Undefined || b == Undefined) return Undefined;
    return (a == False && b == False) ? True : False;
  }
};
}

#endif /* GATES */
