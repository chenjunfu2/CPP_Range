#ifndef RANGE_HPP
#define RANGE_HPP

template <typename T>
class Range
{
public:
	Range(T _tStart, T _tEnd, T _tStep = 1) :tStart(_tStart), tEnd(_tEnd), tStep(_tStep), tCurrent(tStart)
	{
		if (tStep == 0)
		{
			throw "Step is zero!";//错误值异常
		}
	}
	Range(T _tEnd) noexcept :tStart(0), tEnd(_tEnd), tStep(1), tCurrent(tStart)
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
		if (_End.tStep > 0)
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

protected:
	const T tStart;
	const T tEnd;
	const T tStep;
	mutable T tCurrent;
};

#endif // !RANGE_HPP