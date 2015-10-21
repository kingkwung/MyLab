package com.example.quiz0410youngnam;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class youngnamsActivity extends Activity {

	EditText phoneField;
	RadioGroup group;
	RadioButton sktRadio;
	RadioButton ktRadio;
	RadioButton lguRadio;
	Button ok;
	String p_number="";
	String tong="";
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main2);
		
		phoneField = (EditText)findViewById(R.id.getPhonenumber);
		group = (RadioGroup)findViewById(R.id.radioGroup);
		sktRadio = (RadioButton)findViewById(R.id.skt);
		ktRadio = (RadioButton)findViewById(R.id.kt);
		lguRadio = (RadioButton)findViewById(R.id.lgu);
		ok = (Button)findViewById(R.id.okButton);
		
		ok.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				p_number = phoneField.getText().toString();
				if(group.getCheckedRadioButtonId()==sktRadio.getId()){
					tong = "SKT";
				}
				else if(group.getCheckedRadioButtonId()==ktRadio.getId()){
					tong="KT";
				}
				else if(group.getCheckedRadioButtonId()==lguRadio.getId()){
					tong="LGU+";
				}
				Intent myLocalIntent = getIntent();
				Bundle myBundle = myLocalIntent.getExtras();
				
				myBundle.putString("p_number", p_number);
				myBundle.putString("tongsin",tong);
				
				myLocalIntent.putExtras(myBundle);
				setResult(Activity.RESULT_OK, myLocalIntent);
				finish();
			}
		});
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
