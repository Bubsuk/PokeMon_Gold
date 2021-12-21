#include "stdafx.h"
#include "RandomManager.h"
#include <random>
#include <numeric>

// 포켓몬 스펙 가중치 생성
float RandomManager::WeightMaker()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(80, 150);
	
	float weight = distrib(gen) * 0.01f;


	return weight;
}

// probability %의 확률로 true를 리턴한다.
bool RandomManager::PercentMaker(int probability)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 100);

	int value = distrib(gen);
	

	if (value <= probability) return true;
	else return false;

}

// a ~ b 사이의 수 중 랜덤으로 뽑는다
int RandomManager::RandomPeeker(int a, int b)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(a, b);

	int random = distrib(gen);

	return random;
}


