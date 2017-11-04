import javax.xml.parsers.*;
import org.xml.sax.*;
import org.w3c.dom.*;
import java.io.*;

public class ParseXML
{
    public Document getDocument(String file)
    {
	DocumentBuilder db = null;
	Document doc = null;
	try {
	    db = DocumentBuilderFactory.newInstance().newDocumentBuilder();
	}
	catch (ParserConfigurationException e) {
	    System.err.println("Document builder failed.");
	    System.exit(1);
	}
	try {
	    doc = db.parse(file);
	}
	    catch(IOException e) {
		System.err.println("Get of the XML document failed (I/O error): " + e);
		System.exit(1);
	    }
	    catch(SAXException e) {
		System.err.println("Get of the XML document failed (parse error): " + e);
		System.exit(1);
	    }
	    catch(IllegalArgumentException e) {
		System.err.println("Get of the XML document failed (illegal argument): " + e);
		System.exit(1);
	    }
	return doc;
    }
}
