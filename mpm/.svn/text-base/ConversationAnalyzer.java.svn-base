import java.util.Vector;
import org.w3c.dom.*;
import java.util.Iterator;

public class ConversationAnalyzer extends ContentAnalyzer
{
  private int	    STATE = 0;
  private int	    POSITION = 0;
  private boolean   createQueries = false;
  private boolean   ignore = true;
  
  private Vector  fields_name = new Vector ();
  private Vector  fields = new Vector ();
  private String  date;
  private String  action;
  private Vector  createur = new Vector ();
  private Vector  recepteur = new Vector ();
  private Vector  objet = new Vector ();
  
  
  public Vector analyze(DBQueryFactory df, org.w3c.dom.Document d)
    {
      Vector	  QVector = new Vector ();
      
      fields_name.addElement("date");
      fields_name.addElement("createur");
      fields_name.addElement("recepteur");
      fields_name.addElement("objet");
      
      roote(df, QVector, d);
      for (int c = 0; c < createur.size (); ++c)
	for (int r = 0; r < recepteur.size (); ++r)
	  for (int o = 0; o < objet.size (); ++o)
	    {
	      fields = new Vector ();
	      fields.addElement(date);
	      fields.addElement((String) createur.get(c));
	      fields.addElement((String) recepteur.get(r));
	      fields.addElement((String) objet.get(o));
	      if (!ignore)
		QVector.addElement(df.buildTupleInsertionCommand(action, fields));
	    }	    
      return (QVector);
    }

  private void roote(DBQueryFactory df, Vector vec, org.w3c.dom.Node d)
    {	
      NamedNodeMap attrs = d.getAttributes();
      NodeList sons = d.getChildNodes();

      //System.out.println(d.getNodeName() + " : " + d.getNodeValue());
      if (d.getNodeName() == "LOG")
	{
	  if (!createQueries)
	    createQueries = true;
	  else
	    {
	      for (int c = 0; c < createur.size (); ++c)
		for (int r = 0; r < recepteur.size (); ++r)
		  for (int o = 0; o < objet.size (); ++o)
		    {
		      fields.clear();
		      fields.addElement(date);
		      fields.addElement((String) createur.get(c));
		      fields.addElement((String) recepteur.get(r));
		      fields.addElement((String) objet.get(o));
		      if (!ignore)
			vec.addElement(df.buildTupleInsertionCommand(action, fields));
		    }
	      createur.clear();
	      recepteur.clear();
	      objet.clear();
	    }
	}
      if (d.getNodeName() == "date")
	{
	  date = d.getNodeValue();
	  STATE |= 1;
	  STATE |= 32;
	}
      if (d.getNodeName() == "action")
	{
	  if (d.getNodeValue().compareTo("dit") == 0)
	    {
	      ignore = false;
	      vec.addElement(df.buildTableCreationCommand(d.getNodeValue(), fields));
	    }
	  else
	    ignore = true;
	  action = d.getNodeValue(); 

	  STATE |= 2;
	  STATE |= 32;
	}
      if (d.getNodeName() == "CREATEUR")
	POSITION = 1;
      if (d.getNodeName() == "RECEPTEUR")
	POSITION = 2;
      if (d.getNodeName() == "OBJET")
	POSITION = 3;
      if (d.getNodeName() == "#text")
	{
	  if (POSITION == 1)
	    {
	      createur.addElement(d.getNodeValue());
	      POSITION = 0;
	      STATE |= 4;
	      STATE |= 32;
	    }
	  if (POSITION == 2)
	    {
	      recepteur.addElement(d.getNodeValue()); 
	      POSITION = 0;
	      STATE |= 8;
	      STATE |= 32;
	    }
	  if (POSITION == 3)
	    {
	      objet.addElement(d.getNodeValue()); 
	      POSITION = 0;
	      STATE |= 16;
	      STATE |= 32;
	    }
	}
	
      if (attrs != null && attrs.getLength() > 0)
	{
	  for (int i = 0; i < attrs.getLength(); i++)
	    roote(df, vec, attrs.item(i));
	}
      if (sons != null && sons.getLength() > 0)
	{
	  for (int i = 0; i < sons.getLength(); i++)
	    roote(df, vec, sons.item(i));
	}
    }
}
