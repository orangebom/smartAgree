#include <iostream>
#include <stdint.h>
#include <queue> 

using namespace std;

//是否开启加密 
#define SA_EPM_ADD 0
//是否开启权限 
#define SA_PM_ADD 0
//是否开启消息类型 
#define SA_MSGTYPE_ADD 0


#define SA_CHDATA_ADD 0


//发送最大长度 
#define SA_SendMax 200


#define SA_CID_SetCountdownTime 			0x00
#define SA_CID_QueryTime		0x01

enum SA_FrameNameST{
	ST_HEAD 	= 1,
	ST_DLEN 	= 2,
	ST_DATA 	= 3,
	ST_CS   	= 4,
	ST_EPN		= 5,
	ST_PM 		= 6,
	ST_MSGTYPE	= 7,
	ST_CHDATA	= 8,
	ST_CNT		= 9,
};


struct SA_SendST{
	uint8_t databuf[SA_SendMax-20];
	uint8_t sendbuf[SA_SendMax];
	uint16_t sendLen;
};

//加密类 
class SA_EPM{

public:
	uint8_t VALUE;
	
	SA_EPM();
	
	int encryption();
	int Decrypt();

private:
	
};

//消息类型类 
class SA_MSGTYPE{

public:
	uint8_t VALUE;
	
	SA_MSGTYPE();
	
	int encryption();
	int Decrypt();

private:
	enum  MSGTYPE_TYPE{
		SET,
		TRANSMIT,
	};
	
};

class SmartAgree{
public:
	SmartAgree();
	
	int SA_Traverse();
	
	int SA_Send(); 
	
	int SA_Pack();
	
	int SA_AddCommand(uint8_t CID, uint8_t * data, uint32_t dataLen);
	
private:
	
	uint8_t HEAD_V; 
	
	struct SA_SendST SA_SendST;
	
	int FrameForm[20];
	
	//命令数量统计 
	uint8_t count_ST; 
	
	enum SA_FrameNameST FrameNameST;
};
