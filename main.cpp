#include <iostream>
#include <GLFW/glfw3.h>
#include <learncmake.h>


int main(){
    #ifdef USE_ADDER
	    std::cout << add(1.1f,73.8f) << '\n';
    #endif
	std::cout << "VERSION" << learncmake_VERSION_MAJOR;

	GLFWwindow *window;

	if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

	window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
	if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
	while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        //draw();

        // Update animation
        //animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
	glfwTerminate();
	return 0;
}
