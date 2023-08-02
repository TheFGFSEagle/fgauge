add_executable(fgauge
	#mainwindow.ui
	application.cxx
	mainwindow.cxx
	main.cxx
	menus.cxx
	#resources.qrc
)
target_link_libraries(fgauge Qt5::Widgets Qt5::UiTools pugixml::pugixml)
target_include_directories(fgauge PUBLIC ../3rdparty/popl/include/ ../3rdparty/pugixml/src)
install(TARGETS fgauge RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
