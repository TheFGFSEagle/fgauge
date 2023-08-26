add_executable(fgauge
	#mainwindow.ui
	application.cxx
	command.cxx
	commands.cxx
	mainwindow.cxx
	main.cxx
	menubar.cxx
	project.cxx
	uiloader.cxx
	utils.cxx
	#resources.qrc
)

if(CMAKE_BUILD_TYPE EQUAL "Debug")
	target_link_libraries(
		fgauge
		Qt5::Widgets
		Qt5::UiTools
		pugixml::pugixml
		${OSGDB_LIBRARY_DEBUG}
		${OSGSIM_LIBRARY_DEBUG}
		${OSGGA_LIBRARY_DEBUG}
		${OSGVIEWER_LIBRARY_DEBUG}
		${OSGPARTICLE_LIBRARY_DEBUG}
		${OSGUTIL_LIBRARY_DEBUG}
		${OSGFX_LIBRARY_DEBUG}
		${OSGQT_LIBRARIES}
	)
else()
	target_link_libraries(fgauge Qt5::Widgets Qt5::UiTools pugixml::pugixml ${OPENSCENEGRAPH_LIBRARIES} ${OSGQT_LIBRARIES})
endif()
target_include_directories(fgauge PUBLIC ../3rdparty/popl/include/ ../3rdparty/pugixml/src ${OPENSCENEGRAPH_INCLUDE_DIR} ${OSGQT_INCLUDE_DIR})
install(TARGETS fgauge RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
