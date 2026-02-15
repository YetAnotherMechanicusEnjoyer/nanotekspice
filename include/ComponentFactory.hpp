/*
** EPITECH PROJECT, 2026
** COMPONENTFACTORY
** File description:
** nanotekspice
*/

#ifndef COMPONENTFACTORY
  #define COMPONENTFACTORY
  #include "IComponent.hpp"
  #include <functional>
  #include <map>
  #include <memory>

namespace nts {
class ComponentFactory {
public:
  ComponentFactory();
  std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

private:
  std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _builders;
};
}


#endif /* COMPONENTFACTORY */
