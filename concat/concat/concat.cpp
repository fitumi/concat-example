#include "concat.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

static bool
print_file(const std::string& file_path, bool enumerate, size_t& line_number) {
  std::ifstream is(file_path);
  if (!is.is_open()) {
    std::cerr << "Cannot open file " << file_path << "\n";
    return false;
  }

  std::string line;
  while (std::getline(is, line)) {
    if (enumerate) {
      std::cout << std::setw(4) << line_number << "  ";
    }
    std::cout << line << "\n";
    ++line_number;
  }

  return true;
}

bool concat(const std::vector<std::string>& input_file_paths, bool enumerate) {
  size_t start_line_number = 1;
  auto success = true;
  for (const auto& input_file_path : input_file_paths) {
    if (!print_file(input_file_path, enumerate, start_line_number)) {
      success = false;
    }
  }
  return success;
}
