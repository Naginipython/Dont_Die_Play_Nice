FILES = src/main.cpp src/ddpn_lib_impl.cpp
INCS = -I include -I extern_libs

all:

win: all
	g++ -g ${FILES} src/windowsAPI.cpp ${INCS} -w -o DDPN

linux: all
	g++ -lX11 -g ${FILES} src/linuxAPI.cpp ${INCS} -w -o DDPN

runw: all
	./DDPN.exe

runl: all
	./DDPN