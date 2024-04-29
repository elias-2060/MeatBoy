cmake_minimum_required(VERSION 3.13)
project(meatBoy)

set(CMAKE_CXX_STANDARD 14)

# Set the path to the SFML directory relative to your project directory
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/cmake/SFML")

find_package(SFML COMPONENTS graphics window system)

add_executable(meatBoy main.cpp GameRepresentation/PlayerView.h GameRepresentation/PlayerView.cpp GameRepresentation/WallView.h GameRepresentation/WallView.cpp GameRepresentation/Game.h GameRepresentation/Game.cpp LogicLibrary/PlayerModel.h LogicLibrary/PlayerModel.cpp LogicLibrary/WallModel.h LogicLibrary/WallModel.cpp LogicLibrary/World.h LogicLibrary/World.cpp GameRepresentation/ConcreteFactory.h GameRepresentation/ConcreteFactory.cpp LogicLibrary/AbstractFactory.h LogicLibrary/EntityModel.h LogicLibrary/EntityModel.cpp LogicLibrary/AbstractWindow.h GameRepresentation/ConcreteWindow.h GameRepresentation/ConcreteWindow.cpp LogicLibrary/Subject.h LogicLibrary/Observer.h LogicLibrary/Observer.cpp LogicLibrary/Subject.cpp GameRepresentation/EntityView.h GameRepresentation/EntityView.cpp LogicLibrary/Camera.h LogicLibrary/Camera.cpp LogicLibrary/Stopwatch.h LogicLibrary/Stopwatch.cpp GameRepresentation/State.h GameRepresentation/StateManager.h GameRepresentation/StateManager.cpp GameRepresentation/MenuState.h GameRepresentation/MenuState.cpp GameRepresentation/LevelState.h GameRepresentation/LevelState.cpp LogicLibrary/GoalModel.h LogicLibrary/GoalModel.cpp GameRepresentation/GoalView.h GameRepresentation/GoalView.cpp parser/tinystr.h parser/tinystr.cpp parser/tinyxml.h parser/tinyxml.cpp parser/tinyxmlerror.cpp parser/tinyxmlparser.cpp GameRepresentation/MenuLevelState.h GameRepresentation/MenuLevelState.cpp)

# Copy SFML DLLs to the output directory
add_custom_command(TARGET meatBoy POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/SFML/bin/"
        $<TARGET_FILE_DIR:meatBoy>)

target_link_libraries(meatBoy sfml-graphics sfml-window sfml-system)
