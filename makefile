chess: main.cpp
	g++ -std=c++17 -L/usr/local/lib -lX11 -lpthread -lxcb -lXau -lXrandr -lX11 -lpthread -lxcb -lXau -lpthread -lxcb -lXau -lXrender -lX11 -lpthread -lxcb -lXau -lX11 -lpthread -lxcb -lXau -lXi -lX11 -lpthread -lxcb -lXau -lX11 -lpthread -lxcb -lXau -lXfixes -lX11 -lpthread -lxcb -lXau -lXxf86vm -lX11 -lpthread -lxcb -lXau -lXext -lpthread -lxcb -lXau -lGLEW -lX11 -lGLU -lglut -lm -lGL -lglfw -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp -O3 -Wall main.cpp -o chess
	
	
clean:
	rm chess
 
