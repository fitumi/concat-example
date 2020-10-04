#include "concat.hpp"

#include <llvm/Support/CommandLine.h>

#include <iostream>
#include <string>

namespace {

llvm::cl::OptionCategory concat_category("Concat options");

llvm::cl::list<std::string> input_file_paths(
    llvm::cl::Positional,
    llvm::cl::desc("input files"),
    llvm::cl::OneOrMore,
    llvm::cl::cat(concat_category));

llvm::cl::opt<bool> number(
    "number",
    llvm::cl::desc("Enumerate lines"),
    llvm::cl::cat(concat_category));
llvm::cl::alias number_alias("n", llvm::cl::aliasopt(number));

}  // namespace

int main(int argc, char** argv) {
  llvm::cl::HideUnrelatedOptions(concat_category);
  llvm::cl::ParseCommandLineOptions(argc, argv);

  const auto success = concat(input_file_paths, number);
  return success ? 0 : 1;
}
