/*
** EPATECH PROJECT, 2026
** ACOMPONENT
** File description:
** nanotekspice
*/

#ifndef ACOMPONENT
  #define ACOMPONENT
  #include "IComponent.hpp"
  #include <map>

namespace nts {
class AComponent: public IComponent {

protected:
  struct Link {
    nts::IComponent *component;
    std::size_t pin;
  };
  std::map<std::size_t, Link> _links;

public:
  AComponent() = default;
  virtual ~AComponent() = default;

  AComponent(const AComponent&) = delete;
  AComponent& operator=(const AComponent&) = delete;
  AComponent(AComponent&&) noexcept = default;
  AComponent& operator=(AComponent&&) noexcept = default;

  void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override {
    _links[pin] = {&other, otherPin};
  }
};
}

#endif /* ACOMPONENT */
