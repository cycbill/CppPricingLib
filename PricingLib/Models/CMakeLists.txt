# create the Models library
add_library(Models equity/blackscholes.cpp)

# link Models to compiler_flags
target_link_libraries(Models PUBLIC compiler_flags)