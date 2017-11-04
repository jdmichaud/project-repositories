import java.util.Vector;

/**
 * A location determines a position from a cell
 * the board is able to recognnize a cell from a location and an other cell
 */
public class TLocation
{
    /**
     * the direction
     */
    protected int _dir;

    /**
     * the number of cell between the cell and the target
     */
    protected int _dist;

    public TLocation (int dir, int dist)
    {
	_dir = dir;
	_dist = dist;
    }

    /**
     * returns a vector of cells that can be reached from a cell
     */
    public Vector getCases (TBoard B, TCase C)
    {
	Vector res = new Vector ();
	
	int w = ((TSquareBoard) B).getWidth ();
	int h = ((TSquareBoard) B).getHeight ();

	int i = C.getIndex ();
	
	switch (_dir)
	    {
	    case TQueensFactory.DIR_UP:
		if (i < w * (h - _dist))
		    res.addElement (B.getCase (i + w * _dist));
		break;

	    case TQueensFactory.DIR_DOWN:
		if (i >= _dist * w)
		    res.addElement (B.getCase (i - _dist * w));
		break;

	    case TQueensFactory.DIR_LEFT:
		if ((i % w) > _dist - 1)
		    res.addElement (B.getCase (i - _dist));
		break;

	    case TQueensFactory.DIR_RIGHT:
		if ((i % w) != w - _dist)
		    res.addElement (B.getCase (i + _dist));
		break;

	    case TQueensFactory.DIR_UPLEFT:
		if ((i < w * (h - _dist)) && ((i % w) > _dist - 1))
		    res.addElement (B.getCase (i + _dist * w - _dist));
		break;

	    case TQueensFactory.DIR_UPRIGHT:
		if ((i >= _dist * w) && (i < w * (h - _dist)))
		    res.addElement (B.getCase (i + _dist * w + _dist));
		break;

	    case TQueensFactory.DIR_DOWNLEFT:
		if ((i >= _dist * w) && ((i % w) > _dist - 1))
		    res.addElement (B.getCase (i - w * _dist - _dist));
		break;
		
	    case TQueensFactory.DIR_DOWNRIGHT:
		if ((i >= _dist * w) && ((i % w) != w - _dist))
		    res.addElement (B.getCase (i - w * _dist + _dist));
		break;
	    }
	
	return res;
    }
};
