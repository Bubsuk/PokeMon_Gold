#pragma once
#include "Singleton.h"


class TextManager : public Singleton<TextManager>
{
public:
	vector<string> mBattleScript;
	vector<string> mBattleScript1;
	vector<string> mEnemyScript;

	vector<string> mDrOScript;
	vector<string> mMomScript;
	vector<string> mNurseScript;
	vector<string> mMartScript;

	vector<string> mItemScript;

	void Init();
	void ReadScript(const char* directory, vector<string> &strvec);
	void BattleScript();
	void ItemScript();

};

