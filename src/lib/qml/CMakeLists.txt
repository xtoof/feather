project(feather_qml)

SET(CMAKE_AUTOMOC ON)

#SET(CMAKE_AUTOMOC_RELAX_MODE ON)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Qml REQUIRED)
FIND_PACKAGE(Qt5Quick REQUIRED)
#FIND_PACKAGE(Qt53DQuick REQUIRED)
#FIND_PACKAGE(Qt5OpenGL REQUIRED)

SET(QT_USE_QTOPENGL TRUE)

SET(feather_qml_SRCS
    commands.cpp
    curves.cpp
    field_model.cpp
    layer_model.cpp
    tree_model.cpp
    sg_editor.cpp
    #gl_scene.cpp
    #viewport.cpp
    #viewportthread.cpp
    #viewport2.cpp
    #viewport3.cpp
    qml.cpp
)

SET_SOURCE_FILES_PROPERTIES(${feather_qml_SRCS}
 PROPERTIES
 COMPILE_FLAGS ${CMAKE_CXX_FLAGS} )


INCLUDE_DIRECTORIES(${feather_core_SOURCE_DIR}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Qml_INCLUDE_DIRS}
    ${Qt5Quick_INCLUDE_DIRS}
    #${Qt53DQuick_INCLUDE_DIRS}
    #${QtOpenGL_INCLUDE_DIRS}
    #${Qt3DCore_INCLUDE_DIRS}
    #${Qt3DRender_INCLUDE_DIRS}
    #${Qt3DInput_INCLUDE_DIRS}
    "/usr/include/qt/QtGui/5.3.0"
    "/usr/include/qt/QtGui/5.3.0/QtGui"
    "/usr/include/qt/QtCore/5.3.0"
    "/usr/include/qt/QtCore/5.3.0/QtCore"
)

LINK_DIRECTORIES(${feather_core_BINARY_DIR}
)

LINK_LIBRARIES(feather_core)

ADD_DEFINITIONS(${Qt5Widgets_DEFINITIONS}
    ${Qt5Qml_DEFINITIONS}
    ${Qt5Quick_DEFINITIONS}
    #${Qt53DQuick_DEFINITIONS}
    #${Qt5OpenGL_DEFINITIONS}
    #${Qt3DCore_DEFINITIONS}
    #${Qt3DRender_DEFINITIONS}
    #${Qt3DInput_DEFINITIONS}
)

SET(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
SET(CMAKE_CXX_FLAGS "${Qt5Qml_EXECUTABLE_COMPILE_FLAGS}")
SET(CMAKE_CXX_FLAGS "${Qt5Quick_EXECUTABLE_COMPILE_FLAGS}")
#SET(CMAKE_CXX_FLAGS "${Qt53DQuick_EXECUTABLE_COMPILE_FLAGS}")
#SET(CMAKE_CXX_FLAGS "${Qt5OpenGL_EXECUTABLE_COMPILE_FLAGS}")
#SET(CMAKE_CXX_FLAGS "${Qt3DCore_EXECUTABLE_COMPILE_FLAGS}")
#SET(CMAKE_CXX_FLAGS "${Qt3DRender_EXECUTABLE_COMPILE_FLAGS}")
#SET(CMAKE_CXX_FLAGS "${Qt3DInput_EXECUTABLE_COMPILE_FLAGS}")

ADD_LIBRARY(feather_qml SHARED ${feather_qml_SRCS})

#QT5_USE_MODULES(feather_qml Widgets Qml Quick 3DQuick OpenGL 3DCore 3DRender 3DInput)
QT5_USE_MODULES(feather_qml Widgets Qml Quick)

SET(feather_qml_LIBS
 ${BOOST_LIBRARIES}
 ${OPENGL_LIBRARIES}
 ${QT5Widgets_LIBRARIES}
 ${QT5Qml_LIBRARIES}
 ${QT5Quick_LIBRARIES}
 #${QT53DQuick_LIBRARIES}
 #${QT5OpenGL_LIBRARIES}
 #${QT3DCore_LIBRARIES}
 #${QT3DRender_LIBRARIES}
 #${QT3DInput_LIBRARIES}
)

TARGET_LINK_LIBRARIES(feather_qml ${feather_qml_LIBS} ${CMAKE_DL_LIBS})

SET(CMAKE_CXX_FLAGS "-I/usr/include/boost")

SET_TARGET_PROPERTIES(feather_qml
    PROPERTIES
    CMAKE_CXX_STANDARD 14
    CMAKE_CXX_STANDARD_REQUIRED ON
)

SET_TARGET_PROPERTIES(feather_qml
    PROPERTIES
    VERSION 0.01
    SOVERSION 1
)

INSTALL(TARGETS feather_qml
    LIBRARY DESTINATION /usr/lib64/feather)

#FILE(GLOB GLSL_FILES "*.vert" "*.frag" "*.glsl")

#INSTALL(FILES ${GLSL_FILES} DESTINATION /usr/local/feather)

add_subdirectory(shaders)
