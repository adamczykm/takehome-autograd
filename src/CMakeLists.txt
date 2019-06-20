# Source files (except the main for the executable):
set(autograd_src
  foo.cc
  bar.cc
  answer.cc
  count_primes.cc
)

# Compile the library
add_library(${AUTOGRAD_LIB_NAME} ${AUTOGRAD_LIB_TYPE} ${autograd_src})

# Compile the executable
add_executable(autograd_exe main.cc)

# Link the executable to the autograd library (and thread/math libs).
target_link_libraries(autograd_exe ${AUTOGRAD_LIB_NAME} ${CMAKE_THREAD_LIBS_INIT} ${MATH_LIBS})

# How and what to install
install(TARGETS ${AUTOGRAD_LIB_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(TARGETS autograd_exe RUNTIME DESTINATION bin)
install(DIRECTORY ../include/autograd DESTINATION include)
