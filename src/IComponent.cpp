#include "IComponent.hpp"

nts::Tristate operator!(const nts::Tristate a) {
  if (a == nts::Undefined)
    return nts::Undefined;
  return a == nts::True ? nts::False : nts::True;
}
