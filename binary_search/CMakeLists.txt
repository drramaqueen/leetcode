

cmake_minimum_required(VERSION 3.10)

project(leetcode)

find_package(Boost 1.65 COMPONENTS system filesystem unit_test_framework REQUIRED)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_LIB solution.cpp)
add_library(solution STATIC ${SOURCE_LIB})	

add_executable(main main.cpp)
target_link_libraries(main solution)

	
set_target_properties(main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
add_executable(tests test.cpp)

target_link_libraries(tests
                      solution
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )
target_link_libraries(tests ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
add_test(tests tests)
