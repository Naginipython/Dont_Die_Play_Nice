all:
	echo nothing

buildwin: all
	g++ src/main.cpp -I include -o DDPN

buildlinux: all
	g++ -lX11 src/main.cpp -I include -o DDPN

runwin: all
	./DDPN.exe

runlinux: all
	./DDPN