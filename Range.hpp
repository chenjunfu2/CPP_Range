#ifndef RANGE_HPP
#define RANGE_HPP

#include <stdexcept>

template <typename T>
class Range
{
private:
	T tBegin;
	T tEnd;
	T tStep;
	mutable T tCurrent;//确保迭代器始终可用

public:
	Range(T _tStart, T _tEnd, T _tStep = 1) :tBegin(_tStart), tEnd(_tEnd), tStep(_tStep), tCurrent(tBegin)
	{
		if (tStep == 0)
		{
			throw std::invalid_argument("Step is 0 !");//错误值异常
		}
	}
	Range(T _tEnd) noexcept :tBegin(0), tEnd(_tEnd), tStep(1), tCurrent(tBegin)
	{}

	~Range(void) = default;//确保可平凡析构！

	const Range &begin(void) const noexcept
	{
		return *this;
	}

	const Range &end(void) const noexcept
	{
		return *this;
	}

	const Range &operator++(void) const noexcept//前缀
	{
		tCurrent += tStep;
		return *this;
	}

	const Range &operator++(int) const noexcept//后缀
	{
		T tTemp = tCurrent;
		tCurrent += tStep;
		return *this;
	}

	bool operator!=(const Range &_End) const noexcept
	{
		if (tStep > 0)
		{
			return tCurrent < _End.tEnd;
		}
		else
		{
			return tCurrent > _End.tEnd;
		}
	}

	T operator*(void) const noexcept
	{
		return tCurrent;
	}

	void reset(void) const noexcept
	{
		tCurrent = tBegin;
	}
};

#endif // !RANGE_HPP