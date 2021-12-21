#include "stdafx.h"
#include "RandomManager.h"
#include <random>
#include <numeric>

// ���ϸ� ���� ����ġ ����
float RandomManager::WeightMaker()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(80, 150);
	
	float weight = distrib(gen) * 0.01f;


	return weight;
}

// probability %�� Ȯ���� true�� �����Ѵ�.
bool RandomManager::PercentMaker(int probability)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 100);

	int value = distrib(gen);
	

	if (value <= probability) return true;
	else return false;

}

// a ~ b ������ �� �� �������� �̴´�
int RandomManager::RandomPeeker(int a, int b)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(a, b);

	int random = distrib(gen);

	return random;
}


