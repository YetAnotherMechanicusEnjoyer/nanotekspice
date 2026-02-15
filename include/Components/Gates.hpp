/*
** EPITECH PROJECT, 2026
** GATES
** File description:
** nanotekspice
*/

#ifndef GATES
  #define GATES
  #include "AComponent.hpp"
  #include "IComponent.hpp"
  #include <functional>

namespace nts {
class GateComponent: public AComponent {
public:
  using LogicOp = std::function<nts::Tristate(nts::Tristate, nts::Tristate)>;

  GateComponent(LogicOp op) : _op(std::move(op)) {}
  virtual ~GateComponent() = default;

  nts::Tristate compute(std::size_t pin) override {
    if (pin != 3) return getPinValue(pin);

    if (_cache.contains(pin) && _cache[pin].first == _currentTick)
      return _cache[pin].second;

    nts::Tristate res = _op(getPinValue(1), getPinValue(2));
    _cache[pin] = { _currentTick, res };
    return res;
  }

  void simulate(std::size_t tick) override { _currentTick = tick; }

private:
  std::function<nts::Tristate(nts::Tristate, nts::Tristate)> _op;
};

struct Operators {
  static nts::Tristate ntsAnd(nts::Tristate a, nts::Tristate b) {
    if (a == False || b == False) return False;
    if (a == True && b == True) return True;
    return Undefined;
  }
  static nts::Tristate ntsOr(nts::Tristate a, nts::Tristate b) {
    if (a == True || b == True) return True;
    if (a == False || b == False) return False;
    return Undefined;
  }
  static nts::Tristate ntsXor(nts::Tristate a, nts::Tristate b) {
    if (a == Undefined || b == Undefined) return Undefined;
    return (a == b) ? False : True;
  }
  static nts::Tristate ntsNor(nts::Tristate a, nts::Tristate b) {
    if (a == Undefined || b == Undefined) return Undefined;
    return (a == False && b == False) ? True : False;
  }
};
}

#endif /* GATES */
