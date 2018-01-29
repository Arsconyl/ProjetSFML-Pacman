cmake_minimum_required(VERSION 3.9)
project(ProjetSFML-Pacman)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProjetSFML-Pacman
        main.cpp
        Graphe/AElement.h
        Graphe/Arete.h
        Graphe/GElement.h
        Graphe/Graphe.h
        Graphe/Sommet.h
        Graphe/PElement.h
        Erreur.h
        Graphe/AElement.cpp
        Graphe/FenetreSFML.h
        Persos/Pacman.h
        Persos/Fantome.h
        Persos/Personnage.h
        World/Thing.h
        World/Gom.h)
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 COMPONENTS system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ProjetSFML-Pacman ${SFML_LIBRARIES})
endif()