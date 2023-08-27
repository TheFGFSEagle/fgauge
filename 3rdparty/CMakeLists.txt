set(BUILD_OSG_EXAMPLES OFF)
add_subdirectory(osgQt)
unset(BUILD_OSG_EXAMPLES)

add_subdirectory(pugixml)

set(BUILD_EXAMPLE OFF)
set(BUILD_TESTS OFF)
add_subdirectory(popl)
unset(BUILD_EXAMPLE)
unset(BUILD_TESTS)

