#include "ray.h"

ray::ray(const point& begin, const point& p)
{
	if (p != begin)
	{
		_begin = begin;
		_p = p;
	}
}

bool ray::is_element(const line& l) const
{
	if (_begin.is_element(l) && _p.is_element(l))
		return true;
	return false;
}