#include "ray.h"

ray::ray(const point& begin, const point& p)
{
	if (p != begin)
	{
		_begin = begin;
		_p = p;
	}
}

bool ray::is_elem_line(line& l) const
{
	if (_begin.is_elem_line(l) && _p.is_elem_line(l))
		return true;
	return false;
}