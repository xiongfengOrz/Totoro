PROJECT(Totoro)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_DEFINITIONS(-O3 -Wall -g)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/src
    #${PROJECT_SOURCE_DIR}/include
)

ADD_SUBDIRECTORY(src)

#ENABLE_TESTING()
#ADD_TEST(NAME test COMMAND test.run)
