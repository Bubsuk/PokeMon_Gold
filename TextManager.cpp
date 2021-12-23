#include "stdafx.h"
#include "TextManager.h"
#include "Enum.h"
#include <fstream>

void TextManager::Init()
{
	ReadScript("Dialogue/DrODialogue.txt", mDrOScript);
		
}

void TextManager::ReadScript(const char* directory, vector<string> &strvec)
{
	ifstream input_file(directory);
	if (true == input_file.is_open())
	{
		string s;
		while (getline(input_file, s, ';'))
		{
			strvec.push_back(s);
		}
		input_file.close();
	}
	else
	{
		cout << "파일 열기에 실패" << endl;
	}
	
}

