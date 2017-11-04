package com.friday.remote;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class GetHostname extends Activity {

	public final static String HOSTNAME_LABEL = "Hostname";

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.enter_hostname);

		// Listen for button clicks.
		Button button = (Button) findViewById(R.id.SetHostnameButton);
		if (button != null)
			button.setOnClickListener(mSetHostnameButtonListener);
	}

	// Create an anonymous class to act as a button click listener.
	private OnClickListener mSetHostnameButtonListener = new OnClickListener() {
		public void onClick(View v) {
			EditText Hostname = (EditText) findViewById(R.id.Hostname);

			Intent intent = new Intent();
			intent.putExtra(HOSTNAME_LABEL, Hostname.getText().toString());
			setResult(RESULT_OK, intent);
			finish();
		}
	};
}