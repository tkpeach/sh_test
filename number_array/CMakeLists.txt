set(src bunny-mark.ts)
set(src_js bunny-mark-ori.js)

set(BUNNYMARK_O bunny-mark${CMAKE_C_OUTPUT_EXTENSION})
add_custom_command(OUTPUT ${BUNNYMARK_O}
        COMMAND ${HERMES_BINARY_DIR}/bin/shermes $<$<CONFIG:Debug>:-g3> -typed -c ${src}
          -Wc,-I.,-I${HERMES_SOURCE_DIR}/include,-I${HERMES_BINARY_DIR}/lib/config
        -o ${CMAKE_CURRENT_BINARY_DIR}/${BUNNYMARK_O}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

set(BUNNYMARK_JS_O bunny-mark-js${CMAKE_C_OUTPUT_EXTENSION})
add_custom_command(OUTPUT ${BUNNYMARK_JS_O}
        COMMAND ${HERMES_BINARY_DIR}/bin/shermes $<$<CONFIG:Debug>:-g3> -typed -c ${src_js}
          -Wc,-I.,-I${HERMES_SOURCE_DIR}/include,-I${HERMES_BINARY_DIR}/lib/config
	  -o ${CMAKE_CURRENT_BINARY_DIR}/${BUNNYMARK_JS_O}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(number-array-calc-c-d ${CMAKE_CURRENT_SOURCE_DIR}/bunny-mark.c)
set_target_properties(number-array-calc-c-d PROPERTIES COMPILE_FLAGS -g)

add_executable(number-array-calc-c-O0 ${CMAKE_CURRENT_SOURCE_DIR}/bunny-mark.c)
set_target_properties(number-array-calc-c-O0 PROPERTIES COMPILE_FLAGS -O0)

add_executable(number-array-calc-c-O1 ${CMAKE_CURRENT_SOURCE_DIR}/bunny-mark.c)
set_target_properties(number-array-calc-c-O1 PROPERTIES COMPILE_FLAGS -O1)

add_executable(number-array-calc-c-O2 ${CMAKE_CURRENT_SOURCE_DIR}/bunny-mark.c)
set_target_properties(number-array-calc-c-O2 PROPERTIES COMPILE_FLAGS -O2)

add_executable(number-array-calc ${CMAKE_CURRENT_BINARY_DIR}/${BUNNYMARK_O})
target_link_directories(number-array-calc PRIVATE ${HERMES_BINARY_DIR}/lib ${HERMES_BINARY_DIR}/tools/shermes)
target_link_libraries(number-array-calc hermesvm libshermes_console.so)

add_executable(number-array-calc-js ${CMAKE_CURRENT_BINARY_DIR}/${BUNNYMARK_JS_O})
target_link_directories(number-array-calc-js PRIVATE ${HERMES_BINARY_DIR}/lib ${HERMES_BINARY_DIR}/tools/shermes)
target_link_libraries(number-array-calc-js hermesvm libshermes_console.so)

set_property(TARGET number-array-calc number-array-calc-js number-array-calc-c-d number-array-calc-c-O0 number-array-calc-c-O1 number-array-calc-c-O2 PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR})
set_property(TARGET number-array-calc number-array-calc-js number-array-calc-c-d number-array-calc-c-O0 number-array-calc-c-O1 number-array-calc-c-O2 PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR})
set_target_properties(number-array-calc number-array-calc-js PROPERTIES LINKER_LANGUAGE CXX)
