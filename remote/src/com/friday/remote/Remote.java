package com.friday.remote;

import android.app.ListActivity;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;

public class Remote extends ListActivity {
	
    private static final int INSERT_ID = Menu.FIRST;
    private static final int DELETE_ID = Menu.FIRST + 1;	
	
    /* Activity IDs */
    private static final int NEW_CONNECTION_ACTIVITY = 1; 
    private static final int GET_HOSTNAME_ACTIVITY = NEW_CONNECTION_ACTIVITY + 1;
    private static final int BROWSE_HOME = NEW_CONNECTION_ACTIVITY + 2;
    
    private HostsDbAdapter mDbHelper;

    private String mNewConnectionAddress;
    
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.home);
        mDbHelper = new HostsDbAdapter(this);
        mDbHelper.open();
        fillData();
    }
    
    private void fillData() {
        Cursor c = mDbHelper.fetchAllHosts();
        startManagingCursor(c);
        
        // Create an array to specify the fields we want to display in the list (only TITLE)
        String[] from = new String[]{HostsDbAdapter.KEY_NAME, HostsDbAdapter.KEY_ADDRESS};
        
        // and an array of the fields we want to bind those fields to (in this case just text1)
        int[] to = new int[]{R.id.text1, R.id.text2};
        
        // Now create a simple cursor adapter and set it to display
        SimpleCursorAdapter notes = 
        	    new SimpleCursorAdapter(this, R.layout.hosts_row, c, from, to);
        setListAdapter(notes);
    }
     
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        menu.add(0, INSERT_ID, 0, R.string.menu_new);
        menu.add(0, DELETE_ID, 0, R.string.menu_delete);
        return true;
    }

    @Override
    public boolean onMenuItemSelected(int featureId, MenuItem item) {
        switch(item.getItemId()) {
        case INSERT_ID:
        	Intent intent = new Intent(this, NewConnection.class);
       	    startActivityForResult(intent, NEW_CONNECTION_ACTIVITY);

            return true;
        case DELETE_ID:
            mDbHelper.deleteHost(getListView().getSelectedItemId());
            fillData();
            return true;
        }
       
        return super.onMenuItemSelected(featureId, item);
    }
    
    
    @Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
    	switch (requestCode)
    	{
    	case NEW_CONNECTION_ACTIVITY:
    		if (resultCode == RESULT_OK) {
    	      	Bundle extras = data.getExtras();
    			mNewConnectionAddress = extras.getString(NewConnection.IP_ADDRESS_LABEL);
    			Intent getHostnameIntent = new Intent(this, GetHostname.class);
    			startActivityForResult(getHostnameIntent, GET_HOSTNAME_ACTIVITY);
    		}
    		
    		break;
    	case GET_HOSTNAME_ACTIVITY:
          	Bundle extras = data.getExtras();
    		mDbHelper.addHost(extras.getString(GetHostname.HOSTNAME_LABEL), mNewConnectionAddress);
            fillData();

    		break;
    	}
    	
		super.onActivityResult(requestCode, resultCode, data);
	}

	@Override
    protected void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);

        Cursor c = mDbHelper.fetchHosts(id);
        startManagingCursor(c);
        
        Intent intent = new Intent(this, BrowseHome.class);
        intent.putExtra(HostsDbAdapter.KEY_ADDRESS, c.getString(c.getColumnIndexOrThrow(HostsDbAdapter.KEY_ADDRESS)));
        intent.putExtra(HostsDbAdapter.KEY_SONGS_DATABASE_NAME, c.getString(c.getColumnIndexOrThrow(HostsDbAdapter.KEY_SONGS_DATABASE_NAME)));
        intent.putExtra(HostsDbAdapter.KEY_ROWID, c.getString(c.getColumnIndexOrThrow(HostsDbAdapter.KEY_ROWID)));
        String md5 = "";
        try { md5 = c.getString(c.getColumnIndexOrThrow(HostsDbAdapter.KEY_MD5)); }
        catch (Exception e) 
        { 
        	md5 = ""; 
        } 
        intent.putExtra(HostsDbAdapter.KEY_MD5, md5);
		startActivityForResult(intent, BROWSE_HOME);
    }
}