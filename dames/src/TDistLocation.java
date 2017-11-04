import java.util.Vector;

/**
 * this class describes a location that can reached cells with distance bounds
 */
public class TDistLocation extends TLocation
{
    /**
     * the bounds
     */
    private int _distDelta;

    public TDistLocation (int dir, int dist, int distDelta)
    {
	super (dir, dist);
	_distDelta = distDelta;
    }

    /**
     * returns a vector of cells that can be reached from a cell
     */
    public Vector getCases (TBoard B, TCase C)
    {
	return null;
    }
};
