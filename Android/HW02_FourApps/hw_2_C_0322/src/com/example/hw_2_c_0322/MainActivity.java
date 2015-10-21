package com.example.hw_2_c_0322;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class MainActivity extends Activity {

	EditText Name;
	EditText phoneNumber;
	
	RadioGroup rbg1;
	RadioButton jjajang;
	RadioButton jjambbong;
	RadioButton bbokeum;
	
	RadioGroup rbg2;
	RadioButton botong;
	RadioButton goppaki;
	
	CheckBox danmooji;
	CheckBox hothot;
	CheckBox deliver;
	
	
	Button finish;

	//
	String name;
	String p_number;
	
	String menu;
	String quantity;
	
	String options="";
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		//각 뷰에 대해 아이디를 할당해주는 과정입니다 
		Name = (EditText)findViewById(R.id.enterName);
		phoneNumber = (EditText)findViewById(R.id.yourPhoneNumber);
		rbg1 = (RadioGroup)findViewById(R.id.radioGroup);
		jjajang = (RadioButton)findViewById(R.id.jjajang);
		jjambbong = (RadioButton)findViewById(R.id.jjambbong);
		bbokeum = (RadioButton)findViewById(R.id.bokkeum);
		rbg2 = (RadioGroup)findViewById(R.id.radioGroup2);
		botong = (RadioButton)findViewById(R.id.botong);
		goppaki = (RadioButton)findViewById(R.id.goppaeki);
		danmooji = (CheckBox)findViewById(R.id.danmooji);
		hothot = (CheckBox)findViewById(R.id.hothot);
		deliver = (CheckBox)findViewById(R.id.deliver);
		finish = (Button)findViewById(R.id.completeButton);
		
		
		finish.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				name = Name.getText().toString();
				p_number = phoneNumber.getText().toString();
				
				if(name.equals("")||p_number.equals("")){
					Toast.makeText(getApplicationContext(), "information empty ! ", Toast.LENGTH_LONG).show();
					return;
				}
				//
				
				//아이디를 확인하며 기능을 수행하는 과정입니다 
				if(rbg1.getCheckedRadioButtonId()==jjajang.getId()){
					menu = "짜장면";
				}
				else if(rbg1.getCheckedRadioButtonId()==jjambbong.getId()){
					menu = "짬뽕";
				}
				else if(rbg1.getCheckedRadioButtonId()==bbokeum.getId()){
					menu = "볶음밥";
				}
				else{
					Toast.makeText(getApplicationContext(), "Select the menu ~  ", Toast.LENGTH_LONG).show();
					return;
				}
				//
				
				//아이디를 확인하며 기능을 수행하는 과정입니다 
				if(rbg2.getCheckedRadioButtonId()==botong.getId()){
					quantity = "보통";
				}
				else if(rbg2.getCheckedRadioButtonId()==goppaki.getId()){
					quantity = "곱빼기";
				}
				else{
					Toast.makeText(getApplicationContext(), "Select the quantity ~  ", Toast.LENGTH_LONG).show();
					return;
				}
				//
				
				//아이디를 확인하며 기능을 수행하는 과정입니다 
				if(danmooji.isChecked()){
					options+="단무지 많이";
				}
				if(hothot.isChecked()){
					if(options.length()!=0){
						options+=", 맵게";
					}
					else{
						options+="맵게";
					}
				}
				if(deliver.isChecked()){
					if(deliver.length()!=0){
						options+=", 배달";
					}
					else{
						options+="배달";
					}
				}
				//
				
				Toast.makeText(getApplicationContext(), "//"+name+"\n"+"//"+p_number+"\n"+"//"+menu+"\n"+"//"+quantity+"\n"+"//"+options, Toast.LENGTH_LONG).show();
				options="";
				
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
