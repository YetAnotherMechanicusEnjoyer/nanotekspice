/*
** EPITECH PROJECT, 2026
** PARSER
** File description:
** nanotekspice
*/

#ifndef PARSER
  #define PARSER
  #include "IComponent.hpp"
  #include "ComponentFactory.hpp"
  #include <string>
  #include <map>
  #include <memory>

namespace nts {
class Parser {
public:
  Parser();
  ~Parser() = default;

  Parser(const Parser&) = delete;
  Parser& operator=(const Parser&) = delete;

  std::map<std::string, std::unique_ptr<nts::IComponent>> parseFile(const std::string &filepath);

private:
  void parseLine(const std::string &line);
  void processChipset(const std::string &line);
  void processLink(const std::string &line);
  std::string trim(const std::string &str) const;

  enum class Section {
    NONE,
    CHIPSETS,
    LINKS
  };

  Section _currentSection = Section::NONE;

  ComponentFactory _factory;
  std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
};
}

#endif /* PARSER */
