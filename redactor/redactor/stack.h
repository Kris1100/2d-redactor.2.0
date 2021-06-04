#pragma once

template <class T>
class stack
{
public:

	stack(size_t size)
	{
		_buf = new T[size];
		_size = size;
	}
	~stack()
	{
		if (size_ == 0)
			return;
		delete[] _buf;
		_buf = nullptr;
		_size = 0;
		_used = 0;
	}
	stack(const stack& st)
	{
		T* tmp = new T[st._size];
		for (int i = 0; i < st._used; i++)
			tmp[i] = st._buf[i];
		delete[] _buf;
		_buf = tmp;
		_size = st._size;
		_used = st._used;
	}

	size_t get_size() const
	{
		return _size;
	}
	T* get_buf_ptr() const
	{
		return _buf;
	}
	size_t get_used() const
	{
		return _used;
	}

	void push_back(const T& element)
	{
		if (_size == 0)
		{
			_buf = new T[10];
			_size = 10;
		}
		else
			if (_used == _size)
			{
				T* tmp = new T[_size * 2];
				for (int i = 0; i < _used; i++)
					tmp[i] = _buf[i];
				delete[] _buf;
				_buf = tmp;
				_size = _size * 2;
			}
		_buf[_used] = element;
		_used++;
	}
	T pop_back()
	{
		if (_used == 0)
			throw "error";
		T element = _buf[_used];
		_used--;
		return element;
	}

private:
	size_t _size = 0;
	size_t _used = 0;
	T* _buf = nullptr;
};