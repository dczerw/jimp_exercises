
project(points)

set(HEDEAR_FILES Points.h)
set(SOURCE_FILES Points.cpp)

add_library(libpoints STATIC ${SOURCE_FILES})
target_include_directories(libpoints PUBLIC .)

add_executable(points ${SOURCE_FILES} main.cpp)

target_link_libraries(points libpoints)
