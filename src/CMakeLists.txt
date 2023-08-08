
# Add all the source files in src
file(GLOB SOURCES "*.cpp" "*.h")

# Create a library target for src
add_library(SrcTarget ${SOURCES})
