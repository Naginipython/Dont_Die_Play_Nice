all:

win: all
	g++ -g src/main.cpp src/windowsAPI.cpp src/ddpn_lib_impl.cpp -I include -I OpenGL -o DDPN

linux: all
	g++ -lX11 -g src/main.cpp src/linuxAPI.cpp src/ddpn_lib_impl.cpp -I include -I OpenGL -o DDPN

runw: all
	./DDPN.exe

runl: all
	./DDPN