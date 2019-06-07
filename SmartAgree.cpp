#include "SmartAgree.h"

SmartAgree::SmartAgree(){
	
	cout << "开始构造" <<endl;
	count_ST = 0;
	HEAD_V = 0xEA;
	
	
	FrameForm[count_ST++] = ST_HEAD;
	FrameForm[count_ST++] = ST_DLEN;
	
#if SA_EPM_ADD
	FrameForm[count_ST++] = ST_EPN;
#endif

#if SA_PM_ADD
	FrameForm[count_ST++] = ST_PM;
#endif 
	
#if SA_MSGTYPE_ADD
	FrameForm[count_ST++] = ST_MSGTYPE;
#endif 

	FrameForm[count_ST++] = ST_DATA;

}

//遍历输出 
int SmartAgree::SA_Traverse(){
	int i = 0;
	for(i = 0; i<SA_SendST.sendLen; i++){
		printf("command[%d]: %x\n", i, SA_SendST.databuf[i]);
	}
}

int SmartAgree::SA_AddCommand(uint8_t CID, uint8_t * data, uint32_t dataLen){
	int i = 0;
	SA_SendST.databuf[SA_SendST.sendLen++] = CID;
	
	for(i = 0; i<dataLen; i++){
		SA_SendST.databuf[SA_SendST.sendLen++] = data[i];
	}
	
}

int SmartAgree::SA_Pack(){
	FrameForm[count_ST++] = ST_CS;
	
	
}
