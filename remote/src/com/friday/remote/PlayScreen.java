package com.friday.remote;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageButton;
import android.widget.TextView;

public class PlayScreen extends Activity {

	public static int PLAY_SCREEN_ACTIVITY = 1;
	
    private static String mArtist;
    private static String mAlbum;
    private static String mTitle;
    private static String mPath;
    private static String mIPAddress;
    
	// Need handler for callbacks to the UI thread
    public final Handler mHandler = new Handler();
    private Context mCtx;
    private Connection mConnection;
    
    private boolean mPlaying;

    private final String FINISH = "finish";
    
	/** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.playing_screen);

        mCtx = this;
    	Bundle extras = getIntent().getExtras();
    	mPlaying = true;
    	
    	mArtist = extras != null ? extras.getString(SongsDbAdapter.KEY_ARTIST) : null;
    	mAlbum = extras != null ? extras.getString(SongsDbAdapter.KEY_ALBUM) : null;
    	mTitle = extras != null ? extras.getString(SongsDbAdapter.KEY_TITLE) : null;
    	mPath = extras != null ? extras.getString(SongsDbAdapter.KEY_PATH) : null;
    	mIPAddress = extras != null ? extras.getString(HostsDbAdapter.KEY_ADDRESS) : null;

		TextView ArtistName = (TextView) findViewById(R.id.ArtistName);
		ArtistName.setText(mArtist == null ? "" : mArtist);
		TextView AlbumName = (TextView) findViewById(R.id.AlbumName);
		AlbumName.setText(mAlbum == null ? "" : mAlbum);
		TextView TitleName = (TextView) findViewById(R.id.TitleName);
		if (mTitle == null)
			TitleName.setText(mPath == null ? "" : mPath);
		else
			TitleName.setText(mTitle);
        
		ImageButton button = (ImageButton) findViewById(R.id.ControlButton);
		if (button != null)
			button.setOnClickListener(mSetHostnameButtonListener);
		
		mConnection = new Connection(mCtx, mIPAddress);
		if (mConnection.play(mPath))
			setTitle("remote (playing)");
		else
			finish();
		
        Thread t = new Thread() {
            public void run() {
            	try {
					String r = mConnection.listen();
					if (r.equalsIgnoreCase(FINISH))
		                mHandler.post(mSongsOver);
						
				} catch (ClassNotFoundException e) {
					e.printStackTrace();
				}
            }
        };
        t.start();

    }
	
	// Create an anonymous class to act as a button click listener.
	private OnClickListener mSetHostnameButtonListener = new OnClickListener() {
		public void onClick(View v) {
			if (mPlaying)
			{
				mConnection.pause();				
	    		setTitle("remote (pause)");
	    		mPlaying = false;

				ImageButton button = (ImageButton) findViewById(R.id.ControlButton);
				button.setImageResource(android.R.drawable.ic_media_pause);
			}
			else
			{
				mConnection.play();
	    		setTitle("remote (playing)");
	    		mPlaying = true;

	    		ImageButton button = (ImageButton) findViewById(R.id.ControlButton);
				button.setImageResource(android.R.drawable.ic_media_play);
			}
		}
	};

	@Override
	protected void finalize() throws Throwable {
		mConnection.close();
		super.finalize();
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
	    if (keyCode == KeyEvent.KEYCODE_BACK) {
	        finish();
	        return true;
	    }
	    return super.onKeyDown(keyCode, event);
	}
	
	
    final Runnable mSongsOver = new Runnable() {
        public void run() {
    		setTitle("remote (stop)");
    		mPlaying = false;
    		ImageButton button = (ImageButton) findViewById(R.id.ControlButton);
			button.setImageResource(android.R.drawable.ic_media_play);        	
        }
    };
}
