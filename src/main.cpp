#include <iostream>
#include "Core.hpp"

static unsigned int handle_args(int argc, const char *argv[])
{
  if (argc == 1)
    return SUCCESS;
  if (argc > 2 || !argv || !argv[1])
    return FAIL;
  std::string flag(argv[1]);
  if (flag == "--help" || flag == "-h") {
    std::cout <<
      "usage: nanotekspice [options]\noptions:\n-h, --help Show this help\n";
    return HELP;
  }
  return SUCCESS;
}

int main(int argc, const char *argv[]) {
  switch (handle_args(argc, argv)) {
    case HELP:
      return SUCCESS;
    case ERROR:
      return ERROR;
    case FAIL:
      return FAIL;
    default:
      return SUCCESS;
  }
}
