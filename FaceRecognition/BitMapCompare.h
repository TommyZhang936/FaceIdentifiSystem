#pragma once

#include "Poco/Runnable.h"
#include "Poco/Thread.h"

class BitMapCompare : public Poco::Runnable
{
public:
	void run();
private:
	void CompareBitmap(BYTE *pFirst, BYTE *pSecond, long nFirstWidth, long nSecondWidth, long nFirstHeight, long nSecondHeight, float& fRet);
	Mat LoadBmpFile1(std::string strFilePath);
	void getCamBuf();
	void writeDB();
	void onEvent(const void* pSender, bool& arg);

private:
	bool             _break;
};