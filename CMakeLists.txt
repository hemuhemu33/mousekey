cmake_minimum_required(VERSION 2.8)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(./src)
include_directories(./src/testsrc)

#add_executable(PathTest ./src/Path.cpp ./testsrc/PathTest.cpp)

ADD_DEFINITIONS("-std=c++11 -g")

# add_executable(../keymouse ./src/testsrc/TestMain.cpp ./src/ControllMouse.cpp)
# add_executable(../uinputTest ./src/testsrc/UinputTest.cpp ./src/Uinput.cpp)
# add_executable(../SearchDevEventTest ./src/testsrc/SearchDevEventTester.cpp ./src/SearchDevEvent.cpp)

#add_executable(../exec/MouseEventTester ./src/testsrc/main.cpp ./src/MouseEvent.cpp)
#add_executable(../exec/HyperKeyEventTest ./src/testsrc/HyperKeyEventTest.cpp  ./src/MouseEvent.cpp ./src/HyperKeyEvent.cpp ./src/GoLeftEvent.cpp)
#add_executable(../exec/KeyboardMapTester ./src/testsrc/KeyboardMapTester.cpp ./src/KeyboardMap.cpp ./src/GoLeftEvent.cpp)
#add_executable(../exec/MouseEventListTester ./src/testsrc/MouseEventListTester.cpp ./src/MouseEventList.cpp ./src/ReadConfig.cpp ./src/HyperKeyEvent.cpp ./src/GoUpEvent.cpp ./src/MouseEvent.cpp ./src/Uinput.cpp ./src/KeyboardMap.cpp ./src/GoLeftEvent.cpp)
add_executable(../exec/mousekey ./src/testsrc/main.cpp ./src/MouseEventList.cpp ./src/ReadConfig.cpp ./src/HyperKeyEvent.cpp ./src/GoUpEvent.cpp ./src/GoLeftEvent.cpp ./src/MouseEvent.cpp ./src/Uinput.cpp ./src/KeyboardMap.cpp ./src/SearchDevEvent.cpp ./src/Keyboard.cpp ./src/GoRightEvent.cpp ./src/GoDownEvent.cpp ./src/RightKeyEvent.cpp ./src/LeftKeyEvent.cpp ./src/MiddleKeyEvent.cpp ./src/WheelUpEvent.cpp ./src/WheelDownEvent.cpp ./src/QuitEvent.cpp ./src/SpeedUpEvent.cpp ./src/SpeedDownEvent.cpp ./src/BrowserBackEvent.cpp ./src/BrowserNextEvent.cpp)
#add_executable(../exec/mousekey ./src/testsrc/mousekey.cpp ./src/MouseEventList.cpp ./src/ReadConfig.cpp ./src/HyperKeyEvent.cpp ./src/GoUpEvent.cpp ./src/MouseEvent.cpp ./src/Uinput.cpp ./src/KeyboardMap.cpp ./src/SearchDevEvent.cpp ./src/Keyboard.cpp)

