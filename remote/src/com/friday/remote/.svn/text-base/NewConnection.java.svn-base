package com.friday.remote;

import android.app.Activity;
import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class NewConnection extends Activity {
	
    public final static String IP_ADDRESS_LABEL = "IPAddress";
    public final static long MESSAGE_DELAY = 2000;
    private final static String TAG = "NewConnection";
    
    // Parameters to pass back
    private boolean mConnectionTestResult;
    private String mIpAddress;
    
	private Dialog mWaitDialog;
    //private Toast mToast;

	// Need handler for callbacks to the UI thread
    final Handler mHandler = new Handler();

    Context mCtx;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.new_connection);

        mCtx = this;

        // Listen for button clicks.
        Button button = (Button)findViewById(R.id.AddButton);
        button.setOnClickListener(mAddButtonListener);
        
        mWaitDialog = new Dialog(this);
    }

    
    // Create runnable for posting
    final Runnable mTestOver = new Runnable() {
        public void run() {
            if (mConnectionTestResult != true)
            {
            	//Connection failed
            	//mToast.setText("Connection failed!");
            	
            	TextView text = (TextView) mWaitDialog.findViewById(R.id.DialogText);
            	text.setText("Connection failed!");
            }
            
    		Log.d(TAG, "Waiting for a while");    		
        	waitOnError();            
        }
    };

    final Runnable mTerminate = new Runnable() {
        public void run() {
            Intent intent = new Intent();
    		
            if (mConnectionTestResult != true)
            {
            	//Connection failed
                setResult(RESULT_CANCELED);
            }
            else
            {
            	intent.putExtra(IP_ADDRESS_LABEL, mIpAddress); 
            	setResult(RESULT_OK, intent);
            }

            mWaitDialog.dismiss();
            //mToast.cancel();
            finish();
        }
    };

    protected void testConnection(final String IPAddress) {

        // Fire off a thread to do some work that we shouldn't do directly in the UI thread
        Thread t = new Thread() {
            public void run() {
                Connection c = new Connection(mCtx, IPAddress);
                mConnectionTestResult = c.TestConnection();
                c.close();
                mHandler.post(mTestOver);
            }
        };
        t.start();
    }

    protected void waitOnError() {

        // Fire off a thread to do some work that we shouldn't do directly in the UI thread
        Thread t = new Thread() {
            public void run() {
            	try {
            		if (mConnectionTestResult != true)
            			sleep(MESSAGE_DELAY);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
                mHandler.post(mTerminate);
            }
        };
        t.start();
    }
    
    
    // Create an anonymous class to act as a button click listener.
    private OnClickListener mAddButtonListener = new OnClickListener()
    {
        public void onClick(View v)
        {
        	/*
        	mToast = Toast.makeText(v.getContext(), "Testing connection", Toast.LENGTH_LONG);
        	mToast.show();
        	 */
        	
        	mWaitDialog.setContentView(R.layout.connection_dialog);
        	mWaitDialog.show();
        	        	
            EditText IPAddress = (EditText)findViewById(R.id.IPAddress);
            mIpAddress = IPAddress.getText().toString();
            
            testConnection(mIpAddress);
        }
    };   
    
}