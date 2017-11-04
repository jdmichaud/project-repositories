package com.friday.remote;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class Browse extends ListActivity {

	private static String mBrowseLevel;
	private static String mDBName;
	private static String mSelector;
    private static String mIPAddress;

    private static String mArtist;
    private static String mAlbum;
    private static String mTitle;

    private SongsDbAdapter mDbHelper;
	
    private Context mCtx;
    // Need handler for callbacks to the UI thread
    final Handler mHandler = new Handler();

    private List<String> mItems;
    private Cursor mItemsCursor;
    private Cursor mItemCursor;
    
    private final static String TAG = "Browse";
    private final static String SELECTOR = "selector"; 

	/** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.browse_home);
        
        mCtx = this;
    	Bundle extras = getIntent().getExtras();
    	mIPAddress = extras != null ? extras.getString(HostsDbAdapter.KEY_ADDRESS) : null;
    	mBrowseLevel = extras != null ? extras.getString(BrowseHome.BROWSE_LEVEL) : null;
    	mDBName = extras != null ? extras.getString(BrowseHome.DB_NAME) : null;
    	mSelector = extras != null ? extras.getString(SELECTOR) : null;

    	mArtist = extras != null ? extras.getString(SongsDbAdapter.KEY_ARTIST) : null;
    	mAlbum = extras != null ? extras.getString(SongsDbAdapter.KEY_ALBUM) : null;
    	mTitle = extras != null ? extras.getString(SongsDbAdapter.KEY_TITLE) : null;

    	
        mDbHelper = new SongsDbAdapter(mCtx);
        mDbHelper.open(mDBName);

        Thread t = new Thread() {
            public void run() {
        		mItemsCursor = mDbHelper.fetchAllUniq(mBrowseLevel, mSelector);
        		startManagingCursor(mItemsCursor);
        		mItems = new ArrayList<String>();
            	boolean done = mItemsCursor.isLast();
        		while (true)
            	{
        			String itemStr = mItemsCursor.getString(mItemsCursor.getColumnIndexOrThrow(mBrowseLevel));
        			if (itemStr.length() != 0)
        				mItems.add(itemStr);
            		mItemsCursor.moveToNext();
            		
            		if (done)
            			break ;
            		done =  mItemsCursor.isLast();
            	}
        		Collections.sort(mItems);
        		
        		for (int i = 0; i < mItems.size(); ++i) // What is this empty string ???
        			if (mItems.get(i).length() == 0)
        				mItems.remove(i);
        			else
        				break;
        		
        		if (mItems.size() == 0)
	    			browseDirectToTitle();
        		else
        			mHandler.post(fillData);
            }
        };
        t.start();
    }	
    
    // Create runnable for posting
    final Runnable fillData = new Runnable() {
        public void run() {
            // Now create a simple cursor adapter and set it to display
            setTitle("remote (" + mItems.size() + " items)");
            try {
	            ArrayAdapter<String> notes = 
	            	    new ArrayAdapter<String>(mCtx, R.layout.item_row, mItems);
	            setListAdapter(notes);
            }
            catch (IllegalArgumentException e)
            {
        		Log.d(TAG, "Exception: " + e.getLocalizedMessage());    		
            }
        }
    };
	
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
	protected void onResume() {
		mHandler.post(fillData);
		super.onResume();
	}

	@Override
    protected void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);
        
        Intent i = new Intent(this, Browse.class);
    	i.putExtra(BrowseHome.DB_NAME, mDBName);
    	i.putExtra(HostsDbAdapter.KEY_ADDRESS, mIPAddress);
    	if (mArtist != null) i.putExtra(SongsDbAdapter.KEY_ARTIST, mArtist);
    	if (mAlbum != null) i.putExtra(SongsDbAdapter.KEY_ALBUM, mAlbum);
    	if (mTitle != null) i.putExtra(SongsDbAdapter.KEY_TITLE, mTitle);
        if (mBrowseLevel.equalsIgnoreCase(SongsDbAdapter.KEY_ARTIST))
        {
        	i.putExtra(BrowseHome.BROWSE_LEVEL, SongsDbAdapter.KEY_ALBUM);
        	i.putExtra(SELECTOR, SongsDbAdapter.KEY_ARTIST + " = '" + mItems.get(position) + "'");
        	i.putExtra(SongsDbAdapter.KEY_ARTIST, mItems.get(position));
        	startActivityForResult(i, BrowseHome.BROWSE_ALBUM_ACTIVITY);
        }
        if (mBrowseLevel.equalsIgnoreCase(SongsDbAdapter.KEY_ALBUM))
        {
        	i.putExtra(BrowseHome.BROWSE_LEVEL, SongsDbAdapter.KEY_TITLE);
        	i.putExtra(SELECTOR, SongsDbAdapter.KEY_ALBUM + " = '" + mItems.get(position) + "'");
        	i.putExtra(SongsDbAdapter.KEY_ALBUM, mItems.get(position));
        	startActivityForResult(i, BrowseHome.BROWSE_TITLE_ACTIVITY);
        }
        if (mBrowseLevel.equalsIgnoreCase(SongsDbAdapter.KEY_TITLE))
        {
            Intent playIntent = new Intent(this, PlayScreen.class);
            playIntent.putExtra(BrowseHome.DB_NAME, mDBName);
            playIntent.putExtra(HostsDbAdapter.KEY_ADDRESS, mIPAddress);
        	if (mArtist != null) playIntent.putExtra(SongsDbAdapter.KEY_ARTIST, mArtist);
        	if (mAlbum != null) playIntent.putExtra(SongsDbAdapter.KEY_ALBUM, mAlbum);
        	if (mTitle != null) playIntent.putExtra(SongsDbAdapter.KEY_TITLE, mTitle);

        	String title = mItems.get(position);
        	playIntent.putExtra(SongsDbAdapter.KEY_TITLE, title);

        	mItemCursor = mDbHelper.fetchPath(mArtist, mAlbum, title);
    		startManagingCursor(mItemsCursor);
    		
        	String path = mItemCursor.getString(mItemCursor.getColumnIndexOrThrow(SongsDbAdapter.KEY_PATH));
        	playIntent.putExtra(SongsDbAdapter.KEY_PATH, path);

        	startActivityForResult(playIntent, PlayScreen.PLAY_SCREEN_ACTIVITY);
        }
        
        /* tougher to handle and not sure it's useful for now
        if (mBrowseLevel.equalsIgnoreCase(SongsDbAdapter.KEY_GENRE))
        {
        	i.putExtra(BrowseHome.BROWSE_LEVEL, SongsDbAdapter.KEY_ALBUM);
        	i.putExtra(SELECTOR, mItems.get(position));
        	startActivityForResult(i, BrowseHome.BROWSE_TITLE_ACTIVITY);
        }
        */
        
    }
	
	void browseDirectToTitle()
	{
        Intent i = new Intent(this, Browse.class);
    	i.putExtra(BrowseHome.DB_NAME, mDBName);
    	i.putExtra(HostsDbAdapter.KEY_ADDRESS, mIPAddress);
    	i.putExtra(BrowseHome.BROWSE_LEVEL, SongsDbAdapter.KEY_TITLE);
    	i.putExtra(SELECTOR, mSelector);
    	if (mArtist != null) i.putExtra(SongsDbAdapter.KEY_ARTIST, mArtist);
    	if (mAlbum != null) i.putExtra(SongsDbAdapter.KEY_ALBUM, mAlbum);
    	if (mTitle != null) i.putExtra(SongsDbAdapter.KEY_TITLE, mTitle);
    	startActivityForResult(i, BrowseHome.BROWSE_TITLE_ACTIVITY);
	}
    
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
	    if (keyCode == KeyEvent.KEYCODE_BACK) {
	        finish();
	        return true;
	    }
	    return super.onKeyDown(keyCode, event);
	}

}