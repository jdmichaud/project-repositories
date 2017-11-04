import java.util.Vector;

/*
** A pion can eat an other pion if there is an ennemy pion in front of him
*/
public class TEat extends TAction
{
    public TEat ()
    {
	_locations = new Vector ();
	TLocation loc1 = new TLocation (TQueensFactory.DIR_UPLEFT, 2);
	TLocation loc2 = new TLocation (TQueensFactory.DIR_UPRIGHT, 2);	
	TLocation loc3 = new TLocation (TQueensFactory.DIR_DOWNLEFT, 2);
	TLocation loc4 = new TLocation (TQueensFactory.DIR_DOWNRIGHT, 2);
	_locations.addElement (loc1);
	_locations.addElement (loc2);
	_locations.addElement (loc3);
	_locations.addElement (loc4);
    
	_conditions = new Vector ();
	loc1 = new TLocation (TQueensFactory.DIR_UPLEFT, 1);
	loc2 = new TLocation (TQueensFactory.DIR_UPRIGHT, 1);	
	loc3 = new TLocation (TQueensFactory.DIR_DOWNLEFT, 1);
	loc4 = new TLocation (TQueensFactory.DIR_DOWNRIGHT, 1);
	TCondition cond1 = new TCondition (loc1, TCondition.IS_ADV);
	TCondition cond2 = new TCondition (loc2, TCondition.IS_ADV);
	TCondition cond3 = new TCondition (loc3, TCondition.IS_ADV);
	TCondition cond4 = new TCondition (loc4, TCondition.IS_ADV);
	_conditions.addElement (cond1);	
	_conditions.addElement (cond2);
	_conditions.addElement (cond3);	
	_conditions.addElement (cond4);
    }

    /**
     * returns the hits corresponding to eat in the four directions
     */
    public Vector getPossibleHits (TPlayer P, TCase C)
    {
	Vector res = new Vector ();

	Vector locs = new Vector ();
	locs.add (new TLocation (TQueensFactory.DIR_UPLEFT, 2));
	locs.add (new TLocation (TQueensFactory.DIR_UPRIGHT, 2));
	locs.add (new TLocation (TQueensFactory.DIR_DOWNLEFT, 2));
	locs.add (new TLocation (TQueensFactory.DIR_DOWNRIGHT, 2));

	for (int i = 0; i < 4; i++)
	    {
		THit hit = new THit (P);
		hit.addCase (C);
		hit.addCase 
		    (C.getBoard ().getCases (C, (TLocation) locs.get (i)));
		res.addElement (hit);
	    }
	
	return res;
    }
};
