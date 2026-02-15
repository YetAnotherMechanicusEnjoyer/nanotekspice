/*
** EPITECH PROJECT, 2026
** ERRORS
** File description:
** nanotekspice
*/

#ifndef ERRORS
  #define ERRORS
  #include <exception>
  #include <string>

class NTSError: public std::exception {
public:
  NTSError(std::string const &message) : _message(message) {}
  const char *what() const noexcept override { return _message.c_str(); }

private:
std::string _message;
};

#endif /* ERRORS */
