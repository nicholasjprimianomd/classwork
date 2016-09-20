import java.io.*;
import java.net.*;
import java.util.*;

/**********************************************************************
 *
 * Project 4: Web Page Preprocessing
 *
 * <p>This program takes a list of one or more URLs from its command
 * line.  For each such URL, this program does the following:</p>
 * <ol>
 * <li>Creates directory.</li>
 * <li>Downloads the resource associated with said URL into this
 * directory.</li>
 * <li>If the resource is an HTML file, the program downloads all
 * resources (such as images, audio files, videos) that are necessary
 * to construct a web page.</li>
 * </ol>
 *
 * @author Nicholas Primiano
 * @version 1.0 15 Apirl 2014
 *
 **********************************************************************/

public class Proj4 {

  /**
   * Disallow the construction of <code>Proj4</code> objects.
   */
  private Proj4() {}

  /**
   * For readability
   */
  public static final String EMPTY_STRING = "";

  /**
   * The usual main function.
   *
   * <p>The command-line arguments are (absolute) URLs.
   * For each of these, we do the following:</p>
   * <ol>
   * <li>Make an appropriately-named directory, as described in the
   * documentation of <code>mkdir()</code>.</li>
   * <li>Store the resource given by the command-line argument in
   * this directory.</li>
   * <li>Generate a vector containing all <code>src</code> URLs found
   * in the resource we saved in step&nbsp;2.  Note that if this
   * resource was not an (HTML) web page, this list will be
   * empty.</li>
   * <li>Download each resource contained in the vector step&nbsp;3
   * into the directory created in step&nbsp;1.</li>
   * </ol>
   */
  public static void main(String args[])
  {
    int exitCode = 0;
    if (args.length == 0) {
      System.err.println("Usage: java Proj4 url url ...");
      exitCode = 1;
    }
    for (String urlString: args) {
      try {
	File directory = mkdir(urlString);
	byte[] argContents = saveResource(directory, urlString, 
					  EMPTY_STRING);
	Vector<String> srcUrls = getSourceUrls(argContents);
	for (String s: srcUrls) 
	  saveResource(directory, s, urlString);
      }
      catch (Exception ex) {
	System.err.println(ex);
	exitCode = 2;
      }
    }
    System.exit(exitCode);
  }
         
  /**
   * Make a directory whose name is a hexadecimal version of the
   * absolute version of the value of the hash of a given String.  The
   * point here is that the String might be somthing that would make
   * for an incovenient directory name, such as a URL.
   *
   * @param s names the directory, in this rather roundabout way
   * @return the directory, assuming that it can be made
   * @throws IOException if it cant make the directory
   */
  public static File mkdir(String s) 
    throws IOException {
    String dirname = s;               
    String directoryName = String.format("%x", Math.abs(dirname.hashCode()));
    File directory = new File(directoryName);
    if  (!directory.mkdir())
      throw new IOException();
    return directory;
  }
  
  /**
   * <p>Save a resource in a file, as well as in a btye array.  The
   * latter is the return vale.</p>
   *
   * <p>We save in two places, as an economical mesaure, in case we
   * want to access the resource the resource later on without
   * re-reading it.</p>
   *
   * @param dir the directory in which the resource will be saved
   * @param urlString the resource's URL, either relative or absolute
   * @param argURLString if non-empty, the <code>urlString</code> was
   * found on the web page given by <code>argURLString</code>; it may
   * be either absolute or relative.  If the empty string, then this
   * is an absolute URL.
   * @return the contetns of the resources specified by <code>urlString</code>
   * @throws IOException if somthing goes wrong with file creation
   * @throws URISyntaxException if <code>urlString</code> or
   * <code>URLString</code> are invalid.
   */
  public static byte[] saveResource(File dir, String urlString, String argURLString)
    throws IOException, URISyntaxException {    
    URL u = makeAbsoluteURL(urlString, argURLString);
    URLConnection uc = u.openConnection();
    int contentLength = uc.getContentLength();
    byte[] data = null;
    try(InputStream raw = uc.getInputStream()) {
	InputStream in = new BufferedInputStream(raw);
	data = new byte[contentLength];
	int offset = 0;
	while( offset < contentLength){
	  int bytesRead = in.read(data, offset, data.length - offset);
	  if (bytesRead == -1) break;
	  offset += bytesRead;
	}
	if(offset != contentLength) {
	  throw new IOException("Only read" + offset + "bytes;  Expected " +
				contentLength + " bytes'");
	}
	String filename = u.getFile();
	filename = filename.substring(filename.lastIndexOf('/') + 1);
	File path = new File(dir, filename);
	try (FileOutputStream fout = new FileOutputStream(path)) {
	    fout.write(data);
	    fout.flush();
	    return data;
	  }
      }
  }

  /**
   * <p>Get all the <code>src</code> (or <code>SRC</code>) 
   * URLs that appear in an array of bytes.</p>
   * <p>For the purposes of this project, we will only look for
   * occurrences of <code>src</code>="<i>stuff</i>" or of 
   * <code>SRC</code>="<i>stuff</i>", where
   * the <i>stuff</i> is a URL. In other words, we worry about whether
   * this occurs in an HTML tag for which <code>src</code> should appear (such a an
   * <code>img</code> tag).</p>
   * 
   * @param data a sequence of chars that might contain
   * <code>src</code> (or <code>SRC</code>) URLs, initilized from the
   * contentes of a URL.
   * @return a Vector containing all the <code>src</code> attributes
   * found in <code>data</code>.
   */
  public static Vector<String> getSourceUrls(byte[] data)
  {
    Vector<String> src = new Vector<String>();
    for (int i = 0; i < data.length; i++){
      if (data[i] == 'S' || data[i] == 's') { 
	String vader = "";	
	for(int j = i; j < (i+5);j++) {
	  vader += (char) data[j];
	}
	if (vader.equalsIgnoreCase("src=\"")) {
	  String URL = "";
	  int count = i +5;
	  while(data[count] != '\"') {
	    URL += (char) data[count];
	    count++;
	  }
	  src.add(URL);
	}
      }
    }     
    return src;
  } 

  /**
   * Make the absolute version of a possibly-relative URL.
   *
   * @param s a possibly-relative URL
   * @param argURLString the URL of the web page on which
   * <code>s</code> was found.  If this is empty, then <code>s</code>
   * did not originally come from a web page.
   * @return an absolute URL that resolves <code>s</code> and
   * <code>argURLString</code>.
   * @throws URISyntaxException if <code>urlString</code> is not a
   * valid URL
   * @throws MalformedURLException if some error occurred when
   * resolving <code>s</code>
   */
  public static URL makeAbsoluteURL(String s, String argURLString)
    throws URISyntaxException, MalformedURLException
  {
    URI uri = new URI(s);
    if (uri.isAbsolute()) {
      return new URL(s);
    }
    String subURL = null;
    subURL = argURLString.substring(0, argURLString.lastIndexOf('/') + 1);
    String absURL = subURL + s;
    return new URL(absURL);
  }
}

