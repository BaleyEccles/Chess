#pragma once
#include <vector>

template<class Ttype>
std::vector<Ttype> UpdateVector(std::vector<Ttype> Vector);




template<class Ttype>
std::vector<Ttype> UpdateVector(std::vector<Ttype> Vector)
{
	std::vector<Ttype> DummyVec;
	for (int i = 0; i < Vector.size(); i++)
	{
		DummyVec.push_back(Vector[i]);
	}
	return DummyVec;
}
