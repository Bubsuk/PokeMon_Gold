#pragma once
#include "Singleton.h"


class TextManager : public Singleton<TextManager>
{
public:
	vector<string> mDrOScript;
	vector<string> mMomScript;
	void Init();
	void ReadScript(const char* directory, vector<string> &strvec);

};

