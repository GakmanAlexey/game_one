#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <String>
#include <iostream>
#include <sstream>

#pragma warning(disable: 4996)
/*
????? ?????? ? ????? ????? 2 ???????.
in_queue - ???????? ???????
out_queue - ????????? ???????
*/
class NetWork{
public:
	SOCKET Connection;
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	SOCKADDR_IN addr;

	std::string hash = "GHdshadasgdhj123k";

	std::vector<std::vector<std::string>> in_queue;
	std::vector<std::vector<std::string>> out_queue;
	bool con_suspent = false;

	bool Handler_job = false;
	bool Send_job = false;
	bool Ping_job = false;

	void Work() {
		while (!con_suspent) {
			if (!con_suspent) {
				preload();
			}
			run();
		}
	}
	/*
	* ??????? ???????? ??????
	????????? 2 ??????, ????????? ??????? ? ???? ???????
	????????? ? ??????? in_queue
	*/
	void add_in_queue(std::string &head, std::string &command) {
		std::vector<std::string> timed;
		timed.push_back(head);
		timed.push_back(command);
		in_queue.push_back(timed);
	}
	/*
	* ??????? ????????? ??????
	????????? 2 ??????, ????????? ??????? ? ???? ???????
	????????? ? ??????? out_queue
	*/
	void add_out_queue(std::string& head, std::string& command) {
		std::vector<std::string> timed;
		timed.push_back(head);
		timed.push_back(command);
		out_queue.push_back(timed);
	}
	void preload() {
		if (WSAStartup(DLLVersion, &wsaData) != 0) {
			std::cout << "??????" << std::endl;
			exit(1);
		}
		int sizeofaddr = sizeof(addr);
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		addr.sin_port = htons(1111);
		addr.sin_family = AF_INET;

		Connection = socket(AF_INET, SOCK_STREAM, NULL);
		if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
			std::cout << "??????:?????? ?? ????????.\n";
		}
		std::cout << "???????????!\n";
		con_suspent = true;
	}
	void run() {
		if (!Handler_job) {
			std::thread thr1(&NetWork::Handler, this);
			Handler_job = true;
			thr1.join();
		}
		if (!Send_job) {
			std::thread thr2(&NetWork::Send, this);
			Send_job = true;
			thr2.join();

		}

		if (!Ping_job) {
			std::thread thr3(&NetWork::Ping, this);
			Ping_job = true;
			thr3.join();
		}
	}
	void Handler(void) {
		char chars[1024];
		while (true) {
			if (!con_suspent) {
				return;
			}
			recv(Connection, chars, sizeof(chars), NULL);
		}
			/*
			char* pch = strtok(msg, "$R!H");			
			int i = 0;
			while (pch != NULL)                         
			{
				printf("%s\n", pch);
				pch = strtok(NULL, ";");
				i++;
			}
			*/
	}
	void Send() {
		std::string msg;
		int size_vector = 0;
		while (true) {
			if (!con_suspent) {
				return;
			}
			size_vector = out_queue.size();
			if (size_vector >= 1) {
				msg = hash + " $R!H " + out_queue[0][0] + " $R!E " + out_queue[0][1];
				char chars[1023];
				msg.copy(chars, 1024);
				send(Connection, chars, sizeof(chars), NULL);
				out_queue.erase(out_queue.begin());
			}
		}
		
	}
	void Ping() {
	}
};


