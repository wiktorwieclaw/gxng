set(NAME gx2d_input)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCE)

add_library(${NAME} STATIC ${SOURCE} MouseInput.ipp)

target_include_directories(${NAME}
        PUBLIC ${CMAKE_CURRENT_LIST_DIR}
        )

target_link_libraries(${NAME} PUBLIC gx2d_graphics)