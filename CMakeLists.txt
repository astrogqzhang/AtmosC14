cmake_minimum_required (VERSION 3.0)
project(Geant4) 

# include file
include(${Geant4_USE_FILE})

# Locate sources and headers for this project
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${Geant4_INCLUDE_DIR})
#include_directories(/home/gqzhang/software/Geant/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include(/*.hh))


add_executable(Demo test.cc ${sources} ${headers})
target_link_libraries(Demo ${Geant4_LIBRARIES} ${AIDA_LIBRARIES})
