import java.util.Vector;

public class TDefaultHistory extends THistory
{
    public TDefaultHistory (Vector hits)
    { _hits = hits; }

    public Vector getHits ()
    { return _hits; }

    public void addHit (THit hit)
    { _hits.add (hit); }
}
