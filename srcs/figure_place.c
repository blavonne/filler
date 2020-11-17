#include "filler.h"


int			try_via_top(t_filler *filler, int w, int h)
{

}

int			find_min(t_filler *filler, int w, int h)
{
	try_via_top(filler, w, h);
	try_via_left(filler, w, h);
	try_via_right(filler, w, h);
	try_via_bottom(filler, w, h);
}