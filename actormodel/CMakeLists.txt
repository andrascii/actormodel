if(WIN32)
    cmake_minimum_required(VERSION 3.15)
else()
    cmake_minimum_required(VERSION 3.13)
endif()

set(CMAKE_CXX_STANDARD 17)

include(add_msvc_precompiled_header)
include(configure_msvc_runtime)

set(PROJECT_NAME ActorModel)

project(${PROJECT_NAME} C CXX)

set(ACTOR_MODEL_INCLUDE_DIR include)
set(ACTOR_MODEL_RPOXY_SOURCE_DIR src)
set(SERVICES_DIR ../services)

aux_source_directory(${SERVICES_DIR} SERVICES_SOURCE_LIST)
file(GLOB_RECURSE SERVICES_HEADER_LIST "../services/*.h")

aux_source_directory(${ACTOR_MODEL_RPOXY_SOURCE_DIR} ACTOR_MODEL_SOURCE_LIST)
file(GLOB_RECURSE ACTOR_MODEL_HEADER_LIST "include/*.h")

qt5_wrap_cpp(ACTOR_MODEL_MOC_HEADER_LIST ${ACTOR_MODEL_HEADER_LIST})

list(APPEND ACTOR_MODEL_SOURCE_LIST ${ACTOR_MODEL_MOC_HEADER_LIST})
list(APPEND ACTOR_MODEL_SOURCE_LIST ${SERVICES_SOURCE_LIST})
list(APPEND ACTOR_MODEL_HEADER_LIST ${SERVICES_HEADER_LIST})

list(REMOVE_ITEM ACTOR_MODEL_SOURCE_LIST src/stdafx.cpp)
add_msvc_precompiled_header("stdafx.h" "src/stdafx.cpp" ACTOR_MODEL_SOURCE_LIST)

configure_msvc_runtime()

source_group("Precompiled Headers" FILES include/stdafx.h src/stdafx.cpp)
source_group("Services Headers" FILES ${SERVICES_HEADER_LIST})
source_group("Services Sources" FILES ${SERVICES_SOURCE_LIST})

add_definitions(${QT_DEFINITIONS})

add_executable(
    ${PROJECT_NAME}
    ${ACTOR_MODEL_SOURCE_LIST}
    ${ACTOR_MODEL_HEADER_LIST}
)

if(MSVC)
    add_definitions(
        /EHsc
        /MP
        /permissive-
        /std:c++latest
        /Zi
        /W4
        /WX
        -D_WINSOCK_DEPRECATED_NO_WARNINGS
    )

    set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES COMPILE_FLAGS "/FI\"stdafx.h\""
        LINK_FLAGS /DEBUG
    )

    set_target_properties(
        ${PROJECT_NAME} 
        PROPERTIES WIN32_EXECUTABLE YES
        LINK_FLAGS "/DEBUG /ENTRY:mainCRTStartup /MAP"
    )
endif()

message("
    ActorModel: 
    Sources: ${ACTOR_MODEL_SOURCE_LIST}
    Headers: ${ACTOR_MODEL_HEADER_LIST}
")

include_directories(
    ${ACTOR_MODEL_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${SERVICES_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    Qt5::Core
    Qt5::Network
    Qt5::Xml
)

if(NOT WIN32)
    include(cotire)
    set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "include/stdafx.h")
    cotire(${PROJECT_NAME})
endif()
