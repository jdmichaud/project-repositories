package com.friday.remote;

import java.util.ArrayList;
import java.util.HashMap;

import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ListActivity;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class BrowseHome extends ListActivity {
	
	private ArrayList<HashMap<String,String>> mList = new ArrayList<HashMap<String,String>>();
	private final static int PROGRESS_DL_DB = 1;
	private final static int DL_DB_FAILED = PROGRESS_DL_DB + 1;

	private final static String[] mHomeMenu = { "Artist", "Album", "Title" }; //, "Genre" };
	private final static int ARTIST_MENU = 0;
	private final static int ALBUM_MENU = 1;
	private final static int TITLE_MENU = 2;
	private final static int GENRE_MENU = 3;
	
    private static final String TAG = "BrowseHome";

    private final static int MAX_PROGRESS = 100;
    
    /* Constants shared with other Browse window to store Intent data */
    public static final int BROWSE_ARTIST_ACTIVITY = 1; 
    public static final int BROWSE_ALBUM_ACTIVITY = BROWSE_ARTIST_ACTIVITY + 1; 
    public static final int BROWSE_TITLE_ACTIVITY = BROWSE_ARTIST_ACTIVITY + 2; 
    public static final int BROWSE_GENRE_ACTIVITY = BROWSE_ARTIST_ACTIVITY + 3; 
    
    public final static String BROWSE_LEVEL = "browse_level";
    public final static String CURSOR_TO_LIST = "cursor_to_list";
    public final static String DB_NAME = "db_name";
    public final static String CONNECTION = "connection";

    /* Activity IDs */
	
	// Need handler for callbacks to the UI thread
    public final Handler mHandler = new Handler();
	
    private ProgressDialog mProgressDialog; 
    
    private SongsDbAdapter mDbHelper;
    private HostsDbAdapter mDbHosts;
    private Context mCtx;
    private String mIPAddress;
    private String mDBName;
    private String mMd5;
	private int mHostRowId = 0;
	private int mProgress = 0;
    
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.home);

        mCtx = this;
    	Bundle extras = getIntent().getExtras();
    	mIPAddress = extras != null ? extras.getString(HostsDbAdapter.KEY_ADDRESS) : null;
    	mDBName = extras != null ? extras.getString(HostsDbAdapter.KEY_SONGS_DATABASE_NAME) : null;
    	mHostRowId = Integer.parseInt(extras != null ? extras.getString(HostsDbAdapter.KEY_ROWID) : null);
    	mMd5 = extras != null ? extras.getString(HostsDbAdapter.KEY_MD5) : null;
    	
        showDialog(PROGRESS_DL_DB);
        mProgress = 0;
        mProgressDialog.setProgress(0);
        Thread t = new Thread() {
            public void run() {
            	Connection connection = new Connection(mCtx, mIPAddress);
                if (connection.TestConnection() == false)
                    mHandler.post(mDBLoadFailed);
                else
                {
	                String remoteMd5 = connection.getServerMD5();
	        		Log.d(TAG, "remoteMd5: " + remoteMd5 + " - mMd5: " + mMd5);
	        		
	        		if (remoteMd5.length() == 0 ||
	        			mMd5.length() == 0 ||
	        			remoteMd5.substring(remoteMd5.length() - 6).equalsIgnoreCase(mMd5.substring(mMd5.length() - 6)) == false)
	        		{
	        			mCtx.deleteFile(mDBName);
	        			String md5 = connection.getDatabase(mDBName, (BrowseHome) mCtx);
	
	        			mDbHosts = new HostsDbAdapter(mCtx);
	        			mDbHosts.open();
	        			mDbHosts.updateMd5(mHostRowId, md5);
	        		}
	                mHandler.post(mDBLoadOver);
                }
                connection.close();
            }
        };
        t.start();
        
    }
    
    private void DisplayMenu() 
    {
    	for (int i = 0; i < mHomeMenu.length; ++i)
    	{
    		HashMap<String,String> item = new HashMap<String,String>();
    		item.put( "line1", mHomeMenu[i] );
    		mList.add(item);
    	}
    	
    	SimpleAdapter adapter = new SimpleAdapter( 
				this, 
				mList,
				R.layout.item_row,
				new String[] { "line1" },
				new int[] { R.id.ItemText }  );

        setListAdapter(adapter);
    }
     
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        /*
        menu.add(0, INSERT_ID, 0, R.string.menu_new);
        menu.add(0, DELETE_ID, 0, R.string.menu_delete);
        */
        return true;
    }

    @Override
    public boolean onMenuItemSelected(int featureId, MenuItem item) {
        switch(item.getItemId()) {
        /*
        case INSERT_ID:
        	Intent intent = new Intent(this, NewConnection.class);
       	    startActivityForResult(intent, NEW_CONNECTION_ACTIVITY);

            return true;
        case DELETE_ID:
            return true;
        */
        }
       
        return super.onMenuItemSelected(featureId, item);
    }
    
    
    @Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
      	/*Bundle extras = data.getExtras();
    	switch (requestCode)
    	{
    	}
    	*/
		super.onActivityResult(requestCode, resultCode, data);
	}

	@Override
    protected void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);
        
        Intent i = new Intent(this, Browse.class);
    	i.putExtra(DB_NAME, mDBName);
    	i.putExtra(HostsDbAdapter.KEY_ADDRESS, mIPAddress);
        switch ((int) id)
        {
        case ARTIST_MENU:
        	i.putExtra(BROWSE_LEVEL, SongsDbAdapter.KEY_ARTIST);
        	startActivityForResult(i, BROWSE_ARTIST_ACTIVITY);
        	break;
        case ALBUM_MENU:
        	i.putExtra(BROWSE_LEVEL, SongsDbAdapter.KEY_ALBUM);
        	startActivityForResult(i, BROWSE_ALBUM_ACTIVITY);
        	break;
        case TITLE_MENU:
        	i.putExtra(BROWSE_LEVEL, SongsDbAdapter.KEY_TITLE);

        	startActivityForResult(i, BROWSE_TITLE_ACTIVITY);
        	break;
        case GENRE_MENU:
        	i.putExtra(BROWSE_LEVEL, SongsDbAdapter.KEY_GENRE);
        	startActivityForResult(i, BROWSE_GENRE_ACTIVITY);
        	break;
        }
    }
	
    @Override
    protected Dialog onCreateDialog(int id) {
        switch (id) {
            case PROGRESS_DL_DB: {
            	mProgressDialog = new ProgressDialog(this);
            	mProgressDialog.setTitle("Downloading database");
            	mProgressDialog.setMessage("Please wait while downloading...");
            	mProgressDialog.setIndeterminate(false);
            	mProgressDialog.setCancelable(false);
            	mProgressDialog.setMax(MAX_PROGRESS);
                return mProgressDialog;
            }
            case DL_DB_FAILED:
            {
                return new AlertDialog.Builder(this)
                    .setTitle("Download failed!")
                    .setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int whichButton) {
                        	finish();
                        }
                    })
                    .create();
            }
        }
		return mProgressDialog;
    }
 	
    final Runnable mDBLoadOver = new Runnable() {
        public void run() {
        	// checking is the server is not already playing something
        	Connection connection = new Connection(mCtx, mIPAddress);
        	String status = connection.getServerStatus();
        	connection.close();
        	if (status != null && status.length() > 4 && status.substring(0, 4).equalsIgnoreCase("play"))
        	{
                Intent i = new Intent(mCtx, PlayScreen.class);
            	i.putExtra(DB_NAME, mDBName);
            	i.putExtra(HostsDbAdapter.KEY_ADDRESS, mIPAddress);
            	i.putExtra(SongsDbAdapter.KEY_PATH, status.substring(5));
        	}
        	else if (status != null && status.length() > 5 && status.substring(0, 5).equalsIgnoreCase("pause"))
        	{
                Intent i = new Intent(mCtx, PlayScreen.class);
            	i.putExtra(DB_NAME, mDBName);
            	i.putExtra(HostsDbAdapter.KEY_ADDRESS, mIPAddress);
            	i.putExtra(SongsDbAdapter.KEY_PATH, status.substring(6));
        	}
        		
        	
            DisplayMenu();
            mDbHelper = new SongsDbAdapter(mCtx);
            mDbHelper.open(mDBName);

            setTitle("remote (" + mDbHelper.songCount() + " songs)");
            
            mProgressDialog.dismiss();
        }
    };
    
    final Runnable mDBLoadFailed = new Runnable() {
        public void run() {
        	showDialog(DL_DB_FAILED);
        }
    };

    public final Runnable mDisplayProgress = new Runnable() {
        public void run() {
        	if (mProgress >= MAX_PROGRESS) {
                mProgressDialog.dismiss();
            } else {
                mProgress++;
                mProgressDialog.incrementProgressBy(1);
            }
        	
        }
    };

}