
project(family)

set(HEDEAR_FILES Family.h)
set(SOURCE_FILES Family.cpp)

add_library(libfamily STATIC ${SOURCE_FILES})
target_include_directories(libfamily PUBLIC .)

add_executable(family ${SOURCE_FILES} main.cpp)

target_link_libraries(family libfamily)