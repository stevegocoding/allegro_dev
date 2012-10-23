set(TARGET hello_allgro)

# Dependencies
set(DEP_LIBS
	allegro.lib
	allegro_ttf.lib
	allegro_font.lib
	winmm.lib
	)
	
	
set(SOURCE_FILES
	hello_allegro.cpp
	)
	
set(SRC_FILES ${SOURCE_FILES})

source_group("source" FILES ${SOURCE_FILES})

add_executable(${TARGET} WIN32 ${SRC_FILES})
SET_TARGET_PROPERTIES(${TARGET} PROPERTIES DEBUG_POSTFIX "_d")
SET_TARGET_PROPERTIES(${TARGET} PROPERTIES RELEASE_POSTFIX "_rel")

target_link_libraries(${TARGET} "${DEP_LIBS}")

# Installation
install(TARGETS ${TARGET} RUNTIME DESTINATION bin/)
install(DIRECTORY ${DEP_DLL_DIR} DESTINATION bin/) 
