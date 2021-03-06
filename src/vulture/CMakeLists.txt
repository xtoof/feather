SET(CMAKE_INCLUDE_CURRENT_DIR ON)

PROJECT(vulture)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
SET(CMAKE_CXX_LINK_FLAGS "-lvulkan")
SET(CMAKE_CXX_LINK_FLAGS "-lassimp")
SET(CMAKE_CXX_LINK_FLAGS "-lxcb")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_XCB_KHR")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNOMINMAX -DVK_PROTOTYPES -D_USE_MATH_DEFINES")

ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
#ADD_DEFINITIONS(-std=c++11)
#ADD_DEFINITIONS(-std=c++0x)

SET(vulture_SRCS
 main.cpp
)

SET(QT_USE_QTOPENGL TRUE)

INCLUDE_DIRECTORIES(${feather_core_SOURCE_DIR}
    ${feather_vulkan_SOURCE_DIR}
)

LINK_DIRECTORIES(${feather_core_BINARY_DIR}
    ${feather_vulkan_BINARY_DIR}
)

LINK_LIBRARIES(feather_core feather_vulkan)

ADD_EXECUTABLE(vulture ${vulture_SRCS})

TARGET_LINK_LIBRARIES(vulture "-lvulkan" ${PTHREAD})

SET_TARGET_PROPERTIES(vulture
    PROPERTIES
    CMAKE_CXX_STANDARD 14
    CMAKE_CXX_STANDARD_REQUIRED ON
)

# INSTALL
INSTALL( TARGETS vulture
    RUNTIME DESTINATION /usr/local/vulture)
