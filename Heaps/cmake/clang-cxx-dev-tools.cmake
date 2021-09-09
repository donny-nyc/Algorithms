# More matches for autoformatting
file(GLOB_RECURSE
	ALL_CXX_SOURCE_FILES
	*.[chi]pp *.[chi]xx *.cc *.hh *.ii *.[CHI]
	)

# grab the executable
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
	add_custom_target(
		clang-format
		COMMAND /usr/lib/llvm/11/bin/clang-format
		-i
		-style=file
		${ALL_CXX_SOURCE_FILES}
		)
endif()

find_program(CLANG_TIDY "clang-tidy")
if(CLANG_TIDY)
	add_custom_target(
		clang-tidy
		COMMAND /usr/lib/llvm/11/bin/clang-tidy
		${ALL_CXX_SOURCE_FILES}
		-config=''
		--
		-std=c++11
		${INCLUDE_DIRECTORIES}
		)
endif()
