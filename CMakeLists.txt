cmake_minimum_required(VERSION 3.17)
project(TPCommerce)

set(CMAKE_CXX_STANDARD 14)

add_executable(TPCommerce main.cpp Produit.cpp Produit.h Magasin.cpp Magasin.h Livre.cpp Livre.h Cd.cpp Cd.h)