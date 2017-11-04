package com.friday.remote;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

public class HostsDbAdapter {

    public static final String KEY_NAME = "name";
    public static final String KEY_ADDRESS = "ip_address";
    public static final String KEY_SONGS_DATABASE_NAME = "database_name";
    public static final String KEY_ROWID = "_id";
    public static final String KEY_MD5 = "md5";

    private static final String TAG = "HostDbAdapter";
    private DatabaseHelper mDbHelper;
    private SQLiteDatabase mDb;
    
    /**
     * Database creation sql statement
     */
    private static final String DATABASE_CREATE =
            "create table hosts (_id integer primary key autoincrement, "
                    + "name text not null, ip_address text not null, database_name text not null, md5 text default '');";

    private static final String DATABASE_NAME = "data";
    private static final String DATABASE_TABLE = "hosts";
    private static final int DATABASE_VERSION = 5;

    private final Context mCtx;

    private static class DatabaseHelper extends SQLiteOpenHelper {

        DatabaseHelper(Context context) {
            super(context, DATABASE_NAME, null, DATABASE_VERSION);
        }

        @Override
        public void onCreate(SQLiteDatabase db) {

            db.execSQL(DATABASE_CREATE);
        }

        @Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
            Log.w(TAG, "Upgrading database from version " + oldVersion + " to "
                    + newVersion + ", which will destroy all old data");
            db.execSQL("DROP TABLE IF EXISTS " + DATABASE_TABLE);
            onCreate(db);
        }
    }

    /**
     * Constructor - takes the context to allow the database to be
     * opened/created
     * 
     * @param ctx the Context within which to work
     */
    public HostsDbAdapter(Context ctx) {
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
    public HostsDbAdapter open() throws SQLException {
        mDbHelper = new DatabaseHelper(mCtx);
        mDb = mDbHelper.getWritableDatabase();
        return this;
    }
    
    public void close() {
        mDbHelper.close();
    }


    /**
     * Create a new host using the name and ip_address provided. If the host is
     * successfully created return the new rowId for that host, otherwise return
     * a -1 to indicate failure.
     * 
     * @param name the name of the host
     * @param ip_address the ip_address of the host
     * @return rowId or -1 if failed
     */
    public long addHost(String name, String ip_address) {
        ContentValues initialValues = new ContentValues();
        initialValues.put(KEY_NAME, name);
        initialValues.put(KEY_ADDRESS, ip_address);
        initialValues.put(KEY_SONGS_DATABASE_NAME, name);

        return mDb.insert(DATABASE_TABLE, null, initialValues);
    }

    /**
     * Delete the note with the given rowId
     * 
     * @param rowId id of note to delete
     * @return true if deleted, false otherwise
     */
    public boolean deleteHost(long rowId) {

        return mDb.delete(DATABASE_TABLE, KEY_ROWID + "=" + rowId, null) > 0;
    }

    /**
     * Return a Cursor over the list of all notes in the database
     * 
     * @return Cursor over all notes
     */
    public Cursor fetchAllHosts() {

        return mDb.query(DATABASE_TABLE, new String[] {KEY_ROWID, KEY_NAME,
                KEY_ADDRESS, KEY_SONGS_DATABASE_NAME, KEY_MD5}, null, null, null, null, null);
    }

    /**
     * Return a Cursor positioned at the note that matches the given rowId
     * 
     * @param rowId id of note to retrieve
     * @return Cursor positioned to matching note, if found
     * @throws SQLException if note could not be found/retrieved
     */
    public Cursor fetchHosts(long rowId) throws SQLException {

        Cursor mCursor =

                mDb.query(true, DATABASE_TABLE, new String[] {KEY_ROWID,
                        KEY_NAME, KEY_ADDRESS, KEY_SONGS_DATABASE_NAME, KEY_MD5}, KEY_ROWID + "=" + rowId, null,
                        null, null, null, null);
        if (mCursor != null) {
            mCursor.moveToFirst();
        }
        return mCursor;

    }

    /**
     * Update the host using the details provided. The host to be updated is
     * specified using the rowId, and it is altered to use the name and ip_address
     * values passed in
     * 
     * @param rowId id of host to update
     * @param name value to set host name to
     * @param ip_address value to set host ip_address to
     * @return true if the host was successfully updated, false otherwise
     */
    public boolean updateNote(long rowId, String name, String ip_address, String dbName) {
        ContentValues args = new ContentValues();
        args.put(KEY_NAME, name);
        args.put(KEY_ADDRESS, ip_address);
        args.put(KEY_SONGS_DATABASE_NAME, dbName);

        return mDb.update(DATABASE_TABLE, args, KEY_ROWID + "=" + rowId, null) > 0;
    }

    public boolean updateNote(long rowId, String name, String ip_address) {
    	return updateNote(rowId, name, ip_address, name);
    }

    public boolean updateMd5(long rowId, String md5) {
        ContentValues args = new ContentValues();
        args.put(KEY_MD5, md5);

        return mDb.update(DATABASE_TABLE, args, KEY_ROWID + "=" + rowId, null) > 0;
    }

}
