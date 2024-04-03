# Compile the source files into object files
gcc -c -fPIC create_node.c delete_node.c print_list.c

# Create static library
ar rcs libunique_functions.a create_node.o delete_node.o print_list.o

# Create dynamic library
gcc -shared -o libunique_functions.so create_node.o delete_node.o print_list.o

# Check if the dynamic library was created successfully
if [ ! -f "libunique_functions.so" ]; then
    echo "Error: Unable to create the dynamic library"
    exit 1
fi

# Set library path
export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH

# Compile main program with static library
gcc main.c -L. -lunique_functions -o main_static

# Check if the main program was compiled successfully
if [ ! -f "main_static" ]; then
    echo "Error: Unable to compile the main program with static library"
    exit 1
fi

# Compile main program with dynamic library
gcc main.c -L. -lunique_functions -o main_dynamic

# Check if the main program was compiled successfully
if [ ! -f "main_dynamic" ]; then
    echo "Error: Unable to compile the main program with dynamic library"
    exit 1
fi

# Execute main programs
echo "Executing main program with static library..."
./main_static

echo "Executing main program with dynamic library..."
./main_dynamic

# Clean up object files and executables
rm *.o libunique_functions.a libunique_functions.so main_static main_dynamic
