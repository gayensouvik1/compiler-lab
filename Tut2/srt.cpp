#include <bits/stdc++.h>

using namespace std;


class client;
class server;



enum STATES{
	START,
	CLOSED,
	SYNSENT,
	CONNECTED,
	FINWAIT
};

enum INPUT{
	srt_client_sock,
	srt_client_connect,
	syn_timeout,
	synmaxretryexceed,
	receivesynack,
	syn_client_disconnected,
	fin_timeout,
	receivefinack,
	finmaxretryexceed
}

class server{

	public:
		void receive_SYN();

		void send_SYNACK();
		void receive_FIN();

		void send_FINACK();


};

class client{

	public:

		void send_SYN();

		void receive_SYNACK();

		void send_FIN();

		void receive_FINACK();

		STATES next_state(STATES current,int input){

			if(input==srt_client_connect && current==CLOSED){
				current=SYNSENT;
				send_SYN();
			}
			if(input==syn_timeout && current==SYNSENT){
				send_SYN();
			}

			if(input==synmaxretryexceed && current==SYNSENT){
				current=CLOSED;
			}


			if(input==receivesynack && current==SYNSENT){
				current=CONNECTED;
			}

			if(input==syn_client_disconnected && current==CONNECTED){
				current=FINWAIT;
				send_FIN();
			}

			if(input==fin_timeout && current==FINWAIT){
				send_FIN();
			}

			if(input==receivefinack && current==FINWAIT){
				current=CLOSED;
			}
			if(input==finmaxretryexceed && current==FINWAIT){
				current=CLOSED;
			}
		}

		void transition(){
			STATES current = START;
			int input;
			while(cin>>input){
				//current = next_state(current,input);
			}
		}
		//next_state(STATES current,int input);
		

};

client* c;
server* s;


void client::send_SYN(){
	cout << "sending SYN"<<endl;
	s->receive_SYN();
}

void server::receive_SYN(void){	
	cout << "receiving SYN"<<endl;

}

void server:: receive_FIN(void){
	cout << "receiving FIN"<<endl;
}

void client::send_FIN(){
	cout << "sending FIN"<<endl;
	s->receive_FIN();
}



void client::receive_SYNACK(){
			s->send_SYNACK();
			cout << "receiving SYNACK"<<endl;
		}
void client::receive_FINACK(){
			s->send_FINACK();
			cout << "receiving FINACK"<<endl;
		}

int main(){

	c = new client();
	s = new server();
	c->transition();


	return 0;
}