cmake_minimum_required(VERSION 3.24)

set(MAIN_SOURCES main.cpp button.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)



if(WIN32)
  message("Version Qt for Windows")
  set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
elseif(UNIX)
  message("Version Qt for Linux")
  set(CMAKE_PREFIX_PATH "/home/oktan/Qt/5.15.2/gcc_64/lib/cmake")
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

message("Looking for Qt...")

find_package(Qt5 COMPONENTS Core Widgets Multimedia MultimediaWidgets REQUIRED)

if(${Qt5_FOUND})
    message("Found Qt [${Qt5_VERSION}]")
else()
    message("Not Found Qt :(")
endif()

#qt5_generate_moc(main.cpp main.moc TARGET QtWeb)
qt5_wrap_cpp (MAIN_SOURCES ${MY_INCLUDE_DIR}/button.h)
#qt5_wrap_cpp (MAIN_SOURCES ${MY_INCLUDE_DIR}/database.h)
#------------------------------------------


add_executable(Sbutton ${MAIN_SOURCES})

target_link_libraries(Sbutton Qt5::Core Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
target_include_directories(Sbutton PUBLIC ${MY_INCLUDE_DIR})
