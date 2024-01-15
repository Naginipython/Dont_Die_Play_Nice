all:

win: all
	g++ src/main.cpp src/windowsAPI.cpp -I include -o DDPN

linux: all
	g++ -lX11 src/main.cpp src/linuxAPI.cpp -I include -o DDPN

runw: all
	./DDPN.exe

runl: all
	./DDPN