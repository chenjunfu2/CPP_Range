#ifndef RANGE_HPP
#define RANGE_HPP

#include <stdexcept>//标准异常

template <typename T>
class Range
{
private:
	T tBegin;
	T tEnd;
	T tStep;
	mutable T tCurrent;//确保迭代器始终可用

public:
	//构造与析构
	Range(T _tStart, T _tEnd, T _tStep = 1) :tBegin(_tStart), tEnd(_tEnd), tStep(_tStep), tCurrent(tBegin)
	{
		if (tStep == 0)
		{
			throw std::invalid_argument("In class : Range.Constructed(3 parameter)\nthrow : The third parameter \"_tStep\" is 0 !");//错误值异常
		}
	}
	Range(T _tEnd) noexcept :tBegin(0), tEnd(_tEnd), tStep(1), tCurrent(tBegin)
	{}

	~Range(void) = default;//确保可平凡析构！

	//迭代器开始与结束
	const Range &begin(void) const noexcept
	{
		return *this;
	}

	const Range &end(void) const noexcept
	{
		return *this;
	}

	//迭代器迭代
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

	const Range &operator--(void) const noexcept//前缀
	{
		tCurrent -= tStep;
		return *this;
	}

	const Range &operator--(int) const noexcept//后缀
	{
		T tTemp = tCurrent;
		tCurrent -= tStep;
		return *this;
	}

	//迭代器比较
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

	//迭代器解引用
	T operator*(void) const noexcept
	{
		return tCurrent;
	}

	//重设当前值为起始值（const类也可使用）
	void ResetCurrent(void) const noexcept
	{
		tCurrent = tBegin;
	}

	//设置成员
	void SetBegin(T _tBegin) noexcept
	{
		tBegin = _tBegin;
	}

	void SetEnd(T _tEnd) noexcept
	{
		tEnd = _tEnd;
	}

	void SetStep(T _tStep)//此处设为0会抛出异常
	{
		tStep = _tStep;
		if (tStep == 0)
		{
			throw std::invalid_argument("In class : Range.SetStep(1 parameter)\nthrow : The first parameter \"_tStep\" is 0 !");//错误值异常
		}
	}

	void SetCurrent(T _tCurrent) noexcept//const类不能直接设置current但是可以ResetCurrent
	{
		tCurrent = _tCurrent;
	}

	//获取成员
	T GetBegin(void) const noexcept
	{
		return tBegin;
	}

	T GetEnd(void) const noexcept
	{
		return tEnd;
	}

	T GetStep(void) const noexcept
	{
		return tStep;
	}

	T GetCurrent(void) const noexcept
	{
		return tCurrent;
	}
};

#endif // !RANGE_HPP