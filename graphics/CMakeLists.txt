set(NAME gx2d_graphics)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCE)

add_library(${NAME} STATIC ${SOURCE} Action.h)

target_include_directories(${NAME}
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}
        )

target_link_libraries(${NAME} PUBLIC
        gxng_math
        glad
        )