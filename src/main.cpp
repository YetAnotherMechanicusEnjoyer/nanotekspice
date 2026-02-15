#include <iostream>
#include "Core.hpp"
#include "Errors.hpp"

static unsigned int handle_args(int argc, const char *argv[]) {
  if (argc != 2 || !argv || !argv[1]) {
    std::cerr <<
      "Usage:\n\tnanotekspice [options] <file>\nOptions:\n\t-h, --help Show this help" <<
      std::endl;
    return ERROR;
  }

  std::string flag(argv[1]);
  if (flag == "--help" || flag == "-h") {
    std::cout <<
      "Usage:\n\tnanotekspice [options] <file>\nOptions:\n\t-h, --help Show this help" <<
      std::endl;
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
    default:
      try {
        nts::Core engine;
        engine.setup(argv[1]);
        engine.run();
        return SUCCESS;
      } catch (const NTSError &err) {
        std::cerr << "Error: " << err.what() << std::endl;
        return ERROR;
      } catch (...) {
        std::cerr << "Uncaught Error." << std::endl;
        return ERROR;
      }
  }
}
