import java.util.Vector;

public abstract class ContentAnalyzer
{
    public abstract Vector analyze(DBQueryFactory df, org.w3c.dom.Document d);
};

