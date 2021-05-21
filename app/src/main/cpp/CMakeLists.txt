
cmake_minimum_required(VERSION 3.18.1)


project("vaca")

#-----------------------------------------------------tommath
include_directories(${CMAKE_SOURCE_DIR}/tommath)
file(GLOB_RECURSE tommath_src ${CMAKE_SOURCE_DIR}/tommath/*.c)
add_library(tommath ${tommath_src})




#-----------------------------------------------------giac
include_directories(${CMAKE_SOURCE_DIR}/giac)

add_library(giac
        giac/input_lexer.cc
        giac/sym2poly.cc
        giac/gausspol.cc
        giac/threaded.cc
        giac/moyal.cc
        giac/maple.cc
        giac/ti89.cc
        giac/mathml.cc
        giac/misc.cc
        giac/permu.cc
        giac/quater.cc
        giac/desolve.cc
        giac/input_parser.cc
        giac/symbolic.cc
        giac/index.cc
        giac/modpoly.cc
        giac/modfactor.cc
        giac/ezgcd.cc
        giac/derive.cc
        giac/solve.cc
        giac/intg.cc
        giac/intgab.cc
        giac/risch.cc
        giac/lin.cc
        giac/series.cc
        giac/subst.cc
        giac/vecteur.cc
        giac/csturm.cc
        giac/tex.cc
        giac/global.cc
        giac/ifactor.cc
        giac/alg_ext.cc
        giac/gauss.cc
        giac/isom.cc
        giac/help.cc
        giac/plot.cc
        giac/plot3d.cc
        giac/rpn.cc
        giac/prog.cc
        giac/pari.cc
        giac/cocoa.cc
        giac/usual.cc
        giac/identificateur.cc
        giac/gen.cc
        giac/unary.cc
        giac/tinymt32.cc
        giac/first.cc
        giac/sparse.cc)

target_compile_definitions(giac PRIVATE PIC __ANDROID__ HAVE_CONFIG_H GIAC_GENERIC_CONSTANTS FIR_ANDROID)




add_library(
        vaca-lib
        SHARED
        vaca.cpp
)
target_compile_definitions(vaca-lib PUBLIC  __ANDROID__ -DHAVE_CONFIG_H GIAC_GENERIC_CONSTANTS IN_GIAC)


find_library(
        log-lib


        log)

target_link_libraries(
        giac
        tommath
)


target_link_libraries(
        vaca-lib
        giac


        ${log-lib}

      )