#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>


namespace lg
{
	template <typename T>
	void printL(T x)
	{
		std::cout << x << '\n';
	}

	template <typename T>
	void printP(T x)
	{
		std::cout << x;
	}

	template <typename T>
	void printVec(std::vector<T> x)
	{
		for (int i =0; i < int(x.size()); i++)
		{
			std::cout << x[i];
			if (i + 1 != x.size())
			{
				std::cout << ", ";
			}
			else
				std::cout << '\n';
		}
	}
}