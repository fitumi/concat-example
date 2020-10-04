add_executable(concat)

target_sources(
  concat
 
  PRIVATE
    concat/concat.cpp
    concat/concat.hpp
    concat/main.cpp
)

find_package(LLVM 10 REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

target_include_directories(
  concat
  SYSTEM
  PRIVATE
    ${LLVM_INCLUDE_DIRS}
)

llvm_map_components_to_libnames(llvm_libs support)

target_link_libraries(concat ${llvm_libs} clang-10)
