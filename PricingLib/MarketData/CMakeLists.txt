# create the Models library
add_library(MarketData interest_curve.cpp)

# link Models to compiler_flags
target_link_libraries(MarketData PUBLIC compiler_flags)