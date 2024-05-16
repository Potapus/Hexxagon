cmake_minimum_required(VERSION 3.28)
project(Hexxagon)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)
FetchContent_MakeAvailable(
        fmt
        SFML
)


add_executable(Hexxagon main.cpp
        src/Board.cpp
        include/Board.h
        src/Button.cpp
        include/Button.h
        include/State.h
        src/GameState.cpp
        include/Graphics.h
        include/GameState.h
        src/LoadingState.cpp
        include/LoadingState.h
        src/MenuState.cpp
        include/MenuState.h
        src/ModeState.cpp
        include/ModeState.h
        src/EndState.cpp
        include/EndState.h
        src/Game.cpp
        include/Game.h
        include/Side.h
        src/Player.cpp
        include/Player.h
        src/HexxagonPawn.cpp
        include/HexxagonPawn.h
        Util.cpp
)
target_link_libraries(Hexxagon fmt
        sfml-graphics sfml-system
        sfml-window sfml-main)