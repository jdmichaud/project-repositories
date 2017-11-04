package com.friday.remote;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.UUID;

import android.content.Context;
import android.util.Log;

class Connection
{
	public final static int PORT = 14725;

	/* protocol */
	public final static String HANDSHAKE = "hello";
	public final static String HANDSHAKE_ANSWER = "hi";
	public final static String PLAY = "play";
	public final static String PAUSE = "pause";
	public final static String GET_DB = "get_database";
	public final static String GET_MD5 = "get_database_md5";
	public final static String GET_STATUS = "status";
	public final static String CLOSE_CONNETION = "close";
	public final static int BUFFER_SIZE = 1024;
	
	private static final String TAG = "Connection";
		
	public String mLastError; 

	private String mHostname;
	private int mPort;
	private Socket mSocket;
	private DataOutputStream mOutStream;
	private DataInputStream mInStream;
	private boolean mConnected = false;
	
	private Context mCtx;
	
	public Connection(Context c, String host)
	{
		Log.d(TAG, "host: " + host + " - port: " + PORT);
		mHostname = host;
		mPort = PORT;
		
		mCtx = c;
	}
	
	protected void finalize() throws Throwable
	{
		if (mConnected) close();
	}
	
	void openConnection() throws IOException
	{
		/*
		String[] addressArray = mHostname.split("\\.");
		byte[] ipAddress = new byte[addressArray.length];
		for (int i = 0; i < addressArray.length; ++i)
		{
			ipAddress[i] = Byte.parseByte(addressArray[i]);
		}
		InetAddress ip = InetAddress.getByAddress(ipAddress);
		*/
		if (mConnected == false)
		{
			InetAddress ip = InetAddress.getByName(mHostname);
			mSocket = new Socket(ip, mPort);
			mOutStream = new DataOutputStream(mSocket.getOutputStream());
			mOutStream.flush();
			mInStream = new DataInputStream(mSocket.getInputStream());
			mConnected = true;
		}
	}

	protected void close()
	{
		if (mConnected)
		{
			sendMessage(CLOSE_CONNETION);
			mConnected = false;
		}
	}
	
	public void sendMessage(String msg)
	{
		try{
			mOutStream.writeBytes(msg);
			mOutStream.flush();
		}
		catch(IOException ioException){
			ioException.printStackTrace();
		}
	}
	
	public String listen() throws ClassNotFoundException
	{
		try{
			String message = (String) mInStream.readLine();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- received: " + message);    		
			return message;
		}
		catch(IOException ioException){
			ioException.printStackTrace();
			return "";
		}
	}

    public boolean TestConnection()
    {
    	try
    	{
			openConnection();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- sending: " + HANDSHAKE);    		
			sendMessage(HANDSHAKE);
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- listening answer");    		
    		String answer = listen(); 
			if (answer.contentEquals(HANDSHAKE_ANSWER))
				return true;
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- bad handshake answer");
			return false;
    	}
    	catch (UnknownHostException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;
    	}
    	catch (IOException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;    		
    	}
    	catch (ClassNotFoundException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;    		
    	}

    	finally // The test does not keep the connection alive.
    	{
    		try {
    			if (mSocket != null)
    				mSocket.close();
			} catch (IOException e) {
	    		mLastError = e.getLocalizedMessage();
	    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
				e.printStackTrace();
			}
    		mConnected = false;    		
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- disconnected");
    	}
    }

	public String getServerStatus()
	{
		try {
			openConnection();
			sendMessage(GET_STATUS);
			return listen();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
			return "";
		} catch (IOException e) {
			e.printStackTrace();
		}
		return "";
	}

    
    /*
     * Play a particular song
     */
    public boolean play(String path)
    {
    	try
    	{
    		openConnection();
    		sendMessage(PLAY + " " + path);
    	}
    	catch (UnknownHostException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;
    	}
    	catch (IOException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;    		
    	}
    	return true;
    }
	
    public boolean play()
    {
    	try
    	{
    		openConnection();
    		sendMessage(PLAY);
    	}
    	catch (UnknownHostException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;
    	}
    	catch (IOException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;    		
    	}
    	return true;
    }

    public boolean pause()
    {
    	try
    	{
    		openConnection();
    		sendMessage(PAUSE);
    	}
    	catch (UnknownHostException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;
    	}
    	catch (IOException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return false;    		
    	}
    	return true;
    }

    public String getServerMD5()
    {
    	try
    	{
    		openConnection();
    		sendMessage(GET_MD5);
    		String md5 = listen();
    		return md5;
    	}
    	catch (UnknownHostException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return "";
    	}
    	catch (IOException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return "";    		
    	} catch (ClassNotFoundException e) 
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
			e.printStackTrace();
    		return "";    		
		}
    }

    public String getDatabase(String toFilename, BrowseHome progressDialog)
    {
    	try
    	{
    		openConnection();
    		sendMessage(GET_DB);
    		String sizeStr = listen();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- sizeStr: " + sizeStr);    		
    		int size = Integer.parseInt(sizeStr);
    		return writeFileFromServer(toFilename, size, progressDialog);
    	}
    	catch (UnknownHostException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return "";
    	}
    	catch (IOException e)
    	{
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
    		return "";    		
    	} catch (NumberFormatException e) {
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
			return "";
		} catch (ClassNotFoundException e) {
    		mLastError = e.getLocalizedMessage();
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- error: " + mLastError);    		
    		e.printStackTrace();
			return "";
		} 
    }
    
    public static String removeChar(String s, char c) {
        String r = "";
        for (int i = 0; i < s.length(); i ++) {
           if (s.charAt(i) != c) r += s.charAt(i);
           }
        return r;
    }

    
    public String writeFileFromServer(String toFilename, int fileSize, BrowseHome progressDialog) throws IOException
    {
    	FileOutputStream fileStream = mCtx.openFileOutput(toFilename, Context.MODE_PRIVATE);
    	
    	byte[] buffer = new byte[BUFFER_SIZE];
    	int byteRead = 0;
    	int totalPercent = (fileSize / 100);
    	int totalByteRead = 0;
    	do {
			byteRead = mInStream.read(buffer);
			totalByteRead += byteRead;
			if ((totalByteRead % totalPercent) == 0)
				progressDialog.mHandler.post(progressDialog.mDisplayProgress);
			
			fileStream.write(buffer);
    		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- bytes written: " + totalByteRead + " (+ " + byteRead + ")");	
    	} while (totalByteRead != fileSize && byteRead != -1);
    	
    	fileStream.close();
    	
		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- computing md5");	        
        
        buffer = new byte[fileSize];
        FileInputStream fileIStream = mCtx.openFileInput(toFilename);
        fileIStream.read(buffer, 0, fileSize);
        UUID md5 = UUID.nameUUIDFromBytes(buffer);
		Log.d(TAG, "host: " + mHostname + " - port: " + PORT + " -- md5: " + md5.toString());	        
        return removeChar(md5.toString(),'-');
    }

}