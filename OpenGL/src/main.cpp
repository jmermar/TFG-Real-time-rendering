#include <Window.hpp>


int main(int argc, char** argv) {
    Window* window = new Window(1280, 720);
    
    while(!window->shouldQuit()) {
    }

    delete window;
    
    return 0;
}
