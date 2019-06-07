#include <iostream>
#include "SmartAgree.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	uint8_t buf[2] = "";
	
	SmartAgree SmartAgree;
	
	buf[0] = 0x00;
	buf[1] = 0x05;
	
	SmartAgree.SA_AddCommand(SA_CID_SetCountdownTime, buf, 2);
	
	
	
	SmartAgree.SA_Traverse();
	
	return 0;
}
