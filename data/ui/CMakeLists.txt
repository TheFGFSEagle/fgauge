install(
	DIRECTORY
		menus
	DESTINATION
		share/${CMAKE_PROJECT_NAME}/ui
)
install(
	FILES
		mainwindow.ui
		menubar.xml
	DESTINATION
		share/${CMAKE_PROJECT_NAME}/ui
)

