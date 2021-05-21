
cmake_minimum_required(VERSION 3.18.1)


project("vaca")

#-----------------------------------------------------tommath
include_directories(${CMAKE_SOURCE_DIR}/tommath)
file(GLOB_RECURSE tommath_src ${CMAKE_SOURCE_DIR}/tommath/*.c)
add_library(tommath ${tommath_src})









#-----------------------------------------------------libpng
include_directories(${CMAKE_SOURCE_DIR}/libpng)
file(GLOB_RECURSE libpng_src ${CMAKE_SOURCE_DIR}/libpng/*.c)
add_library(libpng ${libpng_src})

#-----------------------------------------------------freetype
include_directories(${CMAKE_SOURCE_DIR}/freetype/include)
file(GLOB_RECURSE freetype_src ${CMAKE_SOURCE_DIR}/freetype/src/*.c)
add_library(freetype
        freetype/src/autofit/autofit.c
        freetype/src/base/basepic.c
        freetype/src/base/ftapi.c
        freetype/src/base/ftbase.c
        freetype/src/base/ftbbox.c
        freetype/src/base/ftbitmap.c
        freetype/src/base/ftdbgmem.c
        freetype/src/base/ftdebug.c
        freetype/src/base/ftglyph.c
        freetype/src/base/ftinit.c
        freetype/src/base/ftpic.c
        freetype/src/base/ftstroke.c
        freetype/src/base/ftsynth.c
        freetype/src/base/ftsystem.c
        freetype/src/cff/cff.c
        freetype/src/pshinter/pshinter.c
        freetype/src/psnames/psnames.c
        freetype/src/raster/raster.c
        freetype/src/sfnt/sfnt.c
        freetype/src/smooth/smooth.c
        freetype/src/truetype/truetype.c)
target_compile_definitions(freetype PRIVATE ANDROID_NDK FT2_BUILD_LIBRARY=1)





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




include(AndroidNdkModules)
android_ndk_import_module_cpufeatures()


#-----------------------------------------------------pixman
include_directories(${CMAKE_SOURCE_DIR}/pixman/pixman)
file(GLOB_RECURSE pixman_src ${CMAKE_SOURCE_DIR}/pixman/pixman/*.c)
add_library(pixman
        pixman/pixman/pixman-access.c
        pixman/pixman/pixman-access-accessors.c
        pixman/pixman/pixman-cpu.c
        pixman/pixman/pixman-gradient-walker.c
        pixman/pixman/pixman-region16.c
        pixman/pixman/pixman-region32.c
        pixman/pixman/pixman-image.c
        pixman/pixman/pixman-implementation.c
        pixman/pixman/pixman-general.c
        pixman/pixman/pixman.c
        pixman/pixman/pixman-fast-path.c
        pixman/pixman/pixman-solid-fill.c
        pixman/pixman/pixman-conical-gradient.c
        pixman/pixman/pixman-linear-gradient.c
        pixman/pixman/pixman-radial-gradient.c
        pixman/pixman/pixman-bits-image.c
        pixman/pixman/pixman-utils.c
        pixman/pixman/pixman-edge.c
        pixman/pixman/pixman-edge-accessors.c
        pixman/pixman/pixman-trap.c
        pixman/pixman/pixman-timer.c
        pixman/pixman/pixman-matrix.c
        pixman/pixman/pixman-noop.c

        pixman/pixman/pixman-combine32.c
        pixman/pixman/pixman-combine64.c
        )
target_compile_definitions(pixman PRIVATE _USE_MATH_DEFINES PIXMAN_NO_TLS PACKAGE="android-cairo" )



#-----------------------------------------------------cairo   需要pixman, freetype, libpng
include_directories(${CMAKE_SOURCE_DIR}/cairo/src)
file(GLOB_RECURSE cairo_src ${CMAKE_SOURCE_DIR}/cairo/src/*.c)
add_library(cairo

        cairo/src/cairo-analysis-surface.c
        cairo/src/cairo-arc.c
        cairo/src/cairo-array.c
        cairo/src/cairo-atomic.c
        cairo/src/cairo-base64-stream.c
        cairo/src/cairo-base85-stream.c
        cairo/src/cairo-bentley-ottmann-rectangular.c
        cairo/src/cairo-bentley-ottmann-rectilinear.c
        cairo/src/cairo-bentley-ottmann.c
        cairo/src/cairo-botor-scan-converter.c
        cairo/src/cairo-boxes-intersect.c
        cairo/src/cairo-boxes.c
        cairo/src/cairo.c
        cairo/src/cairo-cache.c
        cairo/src/cairo-cff-subset.c
        cairo/src/cairo-clip-boxes.c
        cairo/src/cairo-clip-polygon.c
        cairo/src/cairo-clip-region.c
        cairo/src/cairo-clip-surface.c
        cairo/src/cairo-clip-tor-scan-converter.c
        cairo/src/cairo-clip.c
        cairo/src/cairo-color.c
        cairo/src/cairo-composite-rectangles.c
        cairo/src/cairo-compositor.c
        cairo/src/cairo-contour.c
        cairo/src/cairo-damage.c
        cairo/src/cairo-debug.c
        cairo/src/cairo-default-context.c
        cairo/src/cairo-deflate-stream.c
        cairo/src/cairo-device.c
        cairo/src/cairo-error.c
        cairo/src/cairo-fallback-compositor.c
        cairo/src/cairo-fixed.c
        cairo/src/cairo-font-face-twin-data.c
        cairo/src/cairo-font-face-twin.c
        cairo/src/cairo-font-face.c
        cairo/src/cairo-font-options.c
        cairo/src/cairo-freed-pool.c
        cairo/src/cairo-freelist.c
        cairo/src/cairo-gstate.c
        cairo/src/cairo-hash.c
        cairo/src/cairo-hull.c
        cairo/src/cairo-image-compositor.c
        cairo/src/cairo-image-info.c
        cairo/src/cairo-image-source.c
        cairo/src/cairo-image-surface.c
        cairo/src/cairo-lzw.c
        cairo/src/cairo-mask-compositor.c
        cairo/src/cairo-matrix.c
        cairo/src/cairo-mesh-pattern-rasterizer.c
        cairo/src/cairo-misc.c
        cairo/src/cairo-mono-scan-converter.c
        cairo/src/cairo-mutex.c
        cairo/src/cairo-no-compositor.c
        cairo/src/cairo-observer.c
        cairo/src/cairo-output-stream.c
        cairo/src/cairo-paginated-surface.c
        cairo/src/cairo-path-bounds.c
        cairo/src/cairo-path-fill.c
        cairo/src/cairo-path-fixed.c
        cairo/src/cairo-path-in-fill.c
        cairo/src/cairo-path-stroke-boxes.c
        cairo/src/cairo-path-stroke-polygon.c
        cairo/src/cairo-path-stroke-tristrip.c
        cairo/src/cairo-path-stroke.c
        cairo/src/cairo-path.c
        cairo/src/cairo-pattern.c
        cairo/src/cairo-pen.c
        cairo/src/cairo-polygon-intersect.c
        cairo/src/cairo-polygon-reduce.c
        cairo/src/cairo-polygon.c
        cairo/src/cairo-raster-source-pattern.c
        cairo/src/cairo-recording-surface.c
        cairo/src/cairo-rectangle.c
        cairo/src/cairo-rectangular-scan-converter.c
        cairo/src/cairo-region.c
        cairo/src/cairo-rtree.c
        cairo/src/cairo-scaled-font-subsets.c
        cairo/src/cairo-scaled-font.c
        cairo/src/cairo-shape-mask-compositor.c
        cairo/src/cairo-slope.c
        cairo/src/cairo-spans-compositor.c
        cairo/src/cairo-spans.c
        cairo/src/cairo-spline.c
        cairo/src/cairo-stroke-dash.c
        cairo/src/cairo-stroke-style.c
        cairo/src/cairo-surface-clipper.c
        cairo/src/cairo-surface-fallback.c
        cairo/src/cairo-surface-observer.c
        cairo/src/cairo-surface-offset.c
        cairo/src/cairo-surface-snapshot.c
        cairo/src/cairo-surface-subsurface.c
        cairo/src/cairo-surface-wrapper.c
        cairo/src/cairo-surface.c
        cairo/src/cairo-tee-surface.c
        cairo/src/cairo-time.c
        cairo/src/cairo-tor-scan-converter.c
        cairo/src/cairo-tor22-scan-converter.c
        cairo/src/cairo-toy-font-face.c
        cairo/src/cairo-traps-compositor.c
        cairo/src/cairo-traps.c
        cairo/src/cairo-tristrip.c
        cairo/src/cairo-truetype-subset.c
        cairo/src/cairo-type1-fallback.c
        cairo/src/cairo-type1-glyph-names.c
        cairo/src/cairo-type1-subset.c
        cairo/src/cairo-type3-glyph-surface.c
        cairo/src/cairo-unicode.c
        cairo/src/cairo-user-font.c
        cairo/src/cairo-version.c
        cairo/src/cairo-wideint.c
        cairo/src/cairo-png.c
        cairo/src/cairo-ft-font.c
        )
target_compile_definitions(cairo PRIVATE HAVE_STDINT_H HAVE_UINT64_T PACKAGE_VERSION="android-cairo" PACKAGE_BUGREPORT="http://github.com/anoek/android-cairo" CAIRO_NO_MUTEX=1)


add_library(
        vaca-lib
        SHARED
        vaca.cpp
)


find_library(
        log-lib


        log)


target_link_libraries(
        vaca-lib
        tommath
        giac
#        cairo

#        libpng
#        pixman
#        freetype

        ${log-lib}
#        cpufeatures
      )