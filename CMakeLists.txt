# Project's Details
set(PROJECT_NAME "MySDLApp")

#########

# cmake -S . -B build // Generates a build system from your platform
# cmake --build build // Use the generated build system.


####################


cmake_minimum_required(VERSION 3.16)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

function(add_thirdparty TARGET NAME ROOT_DIR)
    # Paths
    set(INCLUDE_DIR "${ROOT_DIR}/include")
    set(LIB_DIR "${ROOT_DIR}/lib/x64")  # adjust for x86 if needed

    # ---------- Add include directory ----------
    if(NOT EXISTS "${INCLUDE_DIR}")
        message(FATAL_ERROR "Include folder not found for ${NAME}: ${INCLUDE_DIR}")
    endif()
    target_include_directories(${TARGET} PRIVATE "${INCLUDE_DIR}")

    # ---------- Link library ----------
    target_link_directories(${TARGET} PRIVATE "${LIB_DIR}")
    target_link_libraries(${TARGET} PRIVATE ${NAME})

    # ---------- Link NAMEmain if exists (SDL2main) ----------
    if(EXISTS "${LIB_DIR}/${NAME}main.lib")
        target_link_libraries(${TARGET} PRIVATE ${NAME}main)
    endif()

    # ---------- Copy DLLs ----------
    file(GLOB DLLS "${LIB_DIR}/*.dll")
    foreach(DLL ${DLLS})
        add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${DLL}"
                $<TARGET_FILE_DIR:${TARGET}>
        )
    endforeach()
endfunction()

# ---------- Add executable ----------
add_executable(${PROJECT_NAME} src/main.cpp)

# ---------- Add libraries ----------
add_thirdparty(${PROJECT_NAME} SDL2 "${CMAKE_SOURCE_DIR}/thirdparty/SDL2-devel-2.30.11-VC")
add_thirdparty(${PROJECT_NAME} SDL2_image "${CMAKE_SOURCE_DIR}/thirdparty/SDL2_image-devel-2.8.8-VC")

