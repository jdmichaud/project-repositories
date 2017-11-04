package com.friday.remote;

import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteException;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

public class SongsDbAdapter {

    public static final String KEY_UID = "_id";
    public static final String KEY_TITLE = "title";
    public static final String KEY_ARTIST = "artist";
    public static final String KEY_ALBUM = "album";
    public static final String KEY_YEAR = "year";
    public static final String KEY_COMMENT = "comment";
    public static final String KEY_GENRE = "genre";
    public static final String KEY_PATH = "path";

    private static final String TAG = "SongsDbAdapter";
    private DatabaseHelper mDbHelper;
    private SQLiteDatabase mDb;

    private static final String DATABASE_TABLE = "songs";
    private static final int DATABASE_VERSION = 1;

    private final Context mCtx;

    private static class DatabaseHelper extends SQLiteOpenHelper {

        DatabaseHelper(Context context, String dbBame) {
            super(context, dbBame, null, DATABASE_VERSION);
        }

        @Override
        public void onCreate(SQLiteDatabase db) {
        	// We don't create songs databases, we received them from the remote server
        }

        @Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        	// We don't upgrade songs databases, we received them from the remote server
        }
    }

    /**
     * Constructor - takes the context to allow the database to be
     * opened/created
     * 
     * @param ctx the Context within which to work
     */
    public SongsDbAdapter(Context ctx) {
        this.mCtx = ctx;
    }

    /**
     * Open the notes database. If it cannot be opened, try to create a new
     * instance of the database. If it cannot be created, throw an exception to
     * signal the failure
     * 
     * @return this (self reference, allowing this to be chained in an
     *         initialization call)
     * @throws SQLException if the database could be neither opened or created
     */
    public SongsDbAdapter open(String name) throws SQLException {
        //mDbHelper = new DatabaseHelper(mCtx, name);
        //mDb = mDbHelper.getWritableDatabase();
    	mDb = SQLiteDatabase.openOrCreateDatabase(mCtx.getFilesDir() + "/" + name, null);
        return this;
    }
    
    public void close() {
        //mDbHelper.close();
    }

    public int songCount()
    {
    	try {
    		Cursor cursor =
    			mDb.query(true, DATABASE_TABLE, 
    		  			  new String[] 
    					  {
 							KEY_UID,
    					  }, 
    					  null, null, null, null, null, null);

        	return cursor.getCount();
    	}
    	catch (SQLiteException e)
    	{
    		Log.e(TAG, "Error", e);	        
    		return 0;
    	}
    }
    
    /**
     * Return a Cursor over the list of all songs in the database
     * WARNING: can be very intensive !
     * 
     * @return Cursor over all songs
     */
    public Cursor fetchAllSongs() {

        return mDb.query(DATABASE_TABLE, 
        				 new String[] 
        				 {
        					KEY_UID,
        					KEY_TITLE,
        					KEY_ARTIST,
        					KEY_ALBUM,
        					KEY_YEAR,
        					KEY_COMMENT,
        					KEY_GENRE,
        					KEY_PATH
        				 }, 
        				 null, null, null, null, null);
    }

    /**
     * Return a Cursor on all the 'field' in the database
     * 
     * @return Cursor on all the 'field' in the database
     * @throws SQLException
     */
    public Cursor fetchAllUniq(String field, String where) throws SQLException 
    {
        Cursor cursor =
                mDb.query(true, DATABASE_TABLE, 
                		  new String[] 
                		  {
     						field,
                		  }, 
                		  where, null, null, null, null, null);

        if (cursor != null) {
            cursor.moveToFirst();
        }
        return cursor;
    }
    
    public Cursor fetchPath(String Artist, String Album, String Title)
    {
    	String where = "";
    	if (Artist != null)
    	{
    		where += KEY_ARTIST + " = '" + Artist + "'";
    		if (Album != null || Title != null)
        		where += " AND ";
    	}
    	if (Album != null)
    	{
    		where += KEY_ALBUM + " = '" + Album + "'";
    		if (Title != null)
        		where += " AND ";
    	}
    	if (Title != null)
    		where += KEY_TITLE + " = '" + Title + "'";
    	
		Log.e(TAG, "fetchPath: where clause: " + where);	        
        Cursor mCursor =
            mDb.query(DATABASE_TABLE, 
            		  new String[] 
            		  {
 						KEY_PATH,
            		  }, 
            		  where, null, null, null, null, null);
	    if (mCursor != null) {
	        mCursor.moveToFirst();
	    }
	    return mCursor;
    }

}
