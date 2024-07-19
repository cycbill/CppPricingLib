cmake_minimum_required(VERSION 3.15.0)
project(PricingLib 
        VERSION 0.1.0 
        DESCRIPTION "Pricing Library in C++"
        LANGUAGES CXX)

include(CTest)
enable_testing()

# specify the C++ standard
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

# add libraries
add_subdirectory(PricingLib/StaticData)
add_subdirectory(PricingLib/MarketData)
add_subdirectory(PricingLib/Models)
add_subdirectory(PricingLib/ProductPricers)

# add packages
set(Boost_INCLUDE_DIRS "packages/boost/boost_1_85_0")
set(Boost_LIBRARY_DIRS "packages/boost/boost_1_85_0/libs")
find_package(Boost 1.85 COMPONENTS)

include_directories(${Boost_INCLUDE_DIRS}) 

# create executable
add_executable(PricingLibExe main.cpp)

# link libraries
target_link_libraries(PricingLibExe PUBLIC Models MarketData ${Boost_LIBRARY_DIRS} compiler_flags)

# add the binary tree to the search path for include files
# so that we will find header files
target_include_directories(PricingLibExe PUBLIC
                         "${PROJECT_BINARY_DIR}"
                         "${PROJECT_SOURCE_DIR}/PricingLib")