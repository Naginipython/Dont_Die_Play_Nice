all:

win: all
	g++ src/main.cpp -I include -o DDPN

linux: all
	g++ -lX11 src/main.cpp -I include -o DDPN

runw: all
	./DDPN.exe

runl: all
	./DDPN