cmake_minimum_required(VERSION 3.9)
project(ProjetSFML-Pacman)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProjetSFML-Pacman
        main.cpp
        Graphe/AElement.h Graphe/AElement.cpp Graphe/Arete.h Graphe/AStar.h Graphe/GElement.h Graphe/Graphe.h Graphe/InfoAStar.h Graphe/InfoAStar.cpp Graphe/PElement.h Graphe/Sommet.h Graphe/VSommet.h
        Screen/Animation.h Screen/backgroundRender.h Screen/FenetreSFML.h
        Persos/Pacman.h Persos/Fantome.h Persos/Personnage.h Persos/deplacement.h
        World/board.h World/Gom.h World/Thing.h
        Erreur.h
        Graphe/VArete.h)
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 COMPONENTS system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ProjetSFML-Pacman ${SFML_LIBRARIES})
endif()