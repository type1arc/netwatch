
cmake_minimum_required(VERSION 3.14)
project(netwatch)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define external path to FTXUI
set(FTXUI_DIR "/home/type/ftxui")

# 👇 Add it to your build, even if it's outside project
add_subdirectory(${FTXUI_DIR} ${CMAKE_BINARY_DIR}/ftxui_build)

# 🔨 Your executable
add_executable(netwatch main.cpp netwatch.cpp)

# file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)    to fix later :|
# add_executable(netwatch ${SOURCES})


# 🔗 Link FTXUI targets
target_link_libraries(netwatch
  PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)
