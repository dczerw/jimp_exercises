
project(sphere)

set(HEDEAR_FILES Kolo.h Kula.h)
set(SOURCE_FILES Kolo.cpp Kula.cpp)

add_library(libsphere STATIC ${SOURCE_FILES})
target_include_directories(libsphere PUBLIC .)

add_executable(sphere ${SOURCE_FILES} main.cpp)

target_link_libraries(sphere libsphere)