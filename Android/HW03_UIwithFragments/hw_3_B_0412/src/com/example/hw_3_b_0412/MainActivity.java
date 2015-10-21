package com.example.hw_3_b_0412;

import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.view.Display;
import android.view.Menu;
import android.view.WindowManager;
import android.widget.TextView;

public class MainActivity extends FragmentActivity {
	String tempName="";
	String tempEmail="";
	String tempPhone="";
	String tempDescription="";
	
	TextView nameField;
	TextView emailField;
	TextView phoneField;
	TextView descriptField;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		WindowManager wm = getWindowManager();
		Display d = wm.getDefaultDisplay();
		
		//세로화면의 경우 Fragment1만 보여줍니다 
		if(d.getWidth() < d.getHeight()){
			FragmentManager fm = getSupportFragmentManager();
			FragmentTransaction ft = fm.beginTransaction();
			
			ft.hide((Fragment2)fm.getFragments().get(1));
			ft.commit();
		}
		
		nameField = (TextView)findViewById(R.id.nameField);
		emailField = (TextView)findViewById(R.id.emailField);
		phoneField = (TextView)findViewById(R.id.phoneField);
		descriptField = (TextView)findViewById(R.id.descriptionField);
	}
	
	
	//화면이 바뀔 때 화면위의 값들 저장 
	protected void onPause(){
		super.onPause();
		
		tempName = nameField.getText().toString();
		tempEmail = emailField.getText().toString();
		tempPhone = phoneField.getText().toString();
		tempDescription = descriptField.getText().toString();
	}
	
	
	//각 값들을 "outState"번들에 저장해 놓습니다 
	public void onSaveInstanceState(Bundle outState){
		super.onSaveInstanceState(outState);
		outState.putString("name", tempName);
		outState.putString("email", tempEmail);
		outState.putString("phone", tempPhone);
		outState.putString("description", tempDescription);
	}
	
	//번들에서 저장된 값들을 불러옵니다 
	protected void onRestoreInstanceState(Bundle savedInstanceState){
		super.onRestoreInstanceState(savedInstanceState);
		tempName = savedInstanceState.getString("name");
		tempEmail = savedInstanceState.getString("email");
		tempPhone = savedInstanceState.getString("phone");
		tempDescription = savedInstanceState.getString("description");
		
		nameField.setText(tempName);
		emailField.setText(tempEmail);
		phoneField.setText(tempPhone);
		descriptField.setText(tempDescription);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
