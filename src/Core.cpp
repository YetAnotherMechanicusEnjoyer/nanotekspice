#include "Core.hpp"
#include "Components/InputComponent.hpp"
#include "Components/OutputComponent.hpp"
#include "Errors.hpp"
#include "IComponent.hpp"
#include "Parser.hpp"
#include <iostream>
#include <csignal>
#include <memory>

namespace nts {
std::atomic<bool> Core::_stopLoop(false);

Core::Core() : _tick(0) {}

void Core::signalHandler(int signum) {
  (void)signum;
  _stopLoop = true;
}

void Core::setup(const std::string &filepath) {
  Parser parser;
  _components = parser.parseFile(filepath);

  for (auto const& [name, component] : _components) {
    IComponent *comp = component.get();
    if (dynamic_cast<InputComponent*>(comp)) {
      _inputs[name] = comp;
    }

    if (dynamic_cast<OutputComponent*>(comp)) {
      _outputs[name] = comp;
    }
  }
}

void Core::simulate() {
  _tick++;
  for (auto &it : _components) {
    it.second->simulate(_tick);
  }
}

void Core::display() const {
  std::cout << "tick: " << _tick << std::endl;

  std::cout << "input(s):" << std::endl;
  for (auto const& [name, comp] : _inputs) {
    Tristate val = comp->compute(1);
    std::string s = (val == Undefined) ? "U" : std::to_string(val);
    std::cout << "  " << name << ": " << s << std::endl;
  }

  std::cout << "output(s):" << std::endl;
  for (auto const& [name, comp] : _outputs) {
    Tristate val = comp->compute(1);
    std::string strVal = (val == Undefined) ? "U" : std::to_string(val);
    std::cout << "  " << name << ": " << strVal << std::endl;
  }
}

void Core::loop() {
  _stopLoop = false;
  std::signal(SIGINT, Core::signalHandler);
  while (!_stopLoop) {
    simulate();
    display();
  }
  std::signal(SIGINT, SIG_DFL);
}

void Core::setInputValue(const std::string &name, Tristate value) {
  if (!_inputs.contains(name))
    throw NTSError("Unknown input: " + name);

  InputComponent *in = dynamic_cast<InputComponent*>(_inputs[name]);
  if (in) in->setValue(value);
}

void Core::run() {
  std::string line;
  std::cout << "> ";
  while (std::getline(std::cin, line)) {
    if (line == "exit") break;
    if (line == "display") display();
    if (line == "simulate") simulate();
    if (line == "loop") loop();

    std::size_t pos = line.find('=');
    if (pos != std::string::npos) {
      std::string name = line.substr(0, pos);
      std::string valStr = line.substr(pos + 1);
      if (valStr == "0") setInputValue(name, False);
      else if (valStr == "1") setInputValue(name, True);
      else if (valStr == "U") setInputValue(name, Undefined);
    }
    std::cout << "> ";
  }
}
}
