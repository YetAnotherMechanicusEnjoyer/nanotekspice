/*
** EPITECH PROJECT, 2026
** COMPONENT4081
** File description:
** nanotekspice
*/

#ifndef COMPONENT4081
  #define COMPONENT4081
  #include "AComponent.hpp"
  #include "Gates.hpp"
  #include "IComponent.hpp"
  #include <memory>
  #include <vector>

namespace nts {
class C4081: public AComponent {
public:
  C4081() {
    for (int i = 0; i < 4; ++i)
      _subGates.push_back(std::make_unique<GateComponent>(Operators::ntsAnd));
  }

  void simulate(std::size_t tick) override {
    for (std::unique_ptr<IComponent> &gate : _subGates) gate->simulate(tick);
  }

  void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override {
    switch (pin) {
      case 1:
        _subGates[0]->setLink(1, other, otherPin);
        break;
      case 2:
        _subGates[0]->setLink(2, other, otherPin);
        break;
      case 5:
        _subGates[1]->setLink(1, other, otherPin);
        break;
      case 6:
        _subGates[1]->setLink(2, other, otherPin);
        break;
      case 8:
        _subGates[2]->setLink(1, other, otherPin);
        break;
      case 9:
        _subGates[2]->setLink(2, other, otherPin);
        break;
      case 12:
        _subGates[3]->setLink(1, other, otherPin);
        break;
      case 13:
        _subGates[3]->setLink(2, other, otherPin);
        break;
    }
  }

  nts::Tristate compute(std::size_t pin) override {
    switch (pin) {
      case 3:
        return _subGates[0]->compute(3);
      case 4:
        return _subGates[1]->compute(3);
      case 10:
        return _subGates[2]->compute(3);
      case 11:
        return _subGates[3]->compute(3);
      default:
        return Undefined;
    }
  }

private:
  std::vector<std::unique_ptr<IComponent>> _subGates;
};
}

#endif /* COMPONENT4081 */
