set(BUILD_EXAMPLE OFF)
set(BUILD_TESTS OFF)
add_subdirectory(popl)
add_subdirectory(pugixml)
unset(BUILD_EXAMPLE)
unset(BUILD_TESTS)

