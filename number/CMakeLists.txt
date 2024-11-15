set(src bunny-mark.ts)

set(BUNNYMARK_O bunny-mark${CMAKE_C_OUTPUT_EXTENSION})
add_custom_command(OUTPUT ${BUNNYMARK_O}
        COMMAND ${HERMES_BINARY_DIR}/bin/shermes $<$<CONFIG:Debug>:-g3> -typed -c ${src}
          -Wc,-I.,-I${HERMES_SOURCE_DIR}/include,-I${HERMES_BINARY_DIR}/lib/config
        -o ${CMAKE_CURRENT_BINARY_DIR}/${BUNNYMARK_O}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(number-calc-c ${CMAKE_CURRENT_SOURCE_DIR}/bunny-mark.c)
add_executable(number-calc ${CMAKE_CURRENT_BINARY_DIR}/${BUNNYMARK_O})
target_link_directories(number-calc PRIVATE ${HERMES_BINARY_DIR}/lib ${HERMES_BINARY_DIR}/tools/shermes)
target_link_libraries(number-calc hermesvm libshermes_console.so)

set_property(TARGET number-calc number-calc-c PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR})
set_property(TARGET number-calc number-calc-c PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR})
set_target_properties(number-calc number-calc-c PROPERTIES LINKER_LANGUAGE CXX)
