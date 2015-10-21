package com.example.hw_2_b_0321;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	
	EditText price;
	RadioGroup radioGroup;
	RadioButton radio1;
	RadioButton radio2;
	RadioButton radio3;
	EditText otherField;
	Button resultButton;
	TextView resultField;
	
	double insertedValue;
	double calculatedValue;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
		//각 뷰들에 ID를 지정해주는 과정입니다 
		price = (EditText)findViewById(R.id.priceField);
		radioGroup = (RadioGroup)findViewById(R.id.RadioGroup);
		radio1 = (RadioButton)findViewById(R.id.fiftyButton);
		radio2 = (RadioButton)findViewById(R.id.twentyButton);
		radio3 = (RadioButton)findViewById(R.id.otherButton);
		otherField = (EditText)findViewById(R.id.otherField);
		resultButton = (Button)findViewById(R.id.resultButton);
		resultField = (TextView)findViewById(R.id.resultField);
		
		int button_check = radioGroup.getCheckedRadioButtonId();
		
		//각버튼에 대한 onclick listener입니다 
		resultButton.setOnClickListener(new OnClickListener(){
			public void onClick(View view){
				
				try{
					insertedValue = Double.parseDouble(price.getText().toString());
					if(insertedValue<=0){
						Toast.makeText(getApplicationContext(), "Input the CorrectNumber~", Toast.LENGTH_LONG).show();
						price.setText("");return;
					}
				}
				catch(NumberFormatException e){
					Toast.makeText(getApplicationContext(), "Not number~", Toast.LENGTH_LONG).show();
					price.setText("");return;
				}
				
				//라디오버튼에 대한 아이디를 확인하고 기능을 수행하는 과정입니다 
				int radioId = radioGroup.getCheckedRadioButtonId();
				if(radioId==radio1.getId()){
					calculatedValue = insertedValue*0.15;
					resultField.setText(Double.toString(calculatedValue));
				}
				else if(radioId==radio2.getId()){
					calculatedValue = insertedValue*0.20;
					resultField.setText(Double.toString(calculatedValue));
				}
				else if(radioId==radio3.getId()){
					String rateString = otherField.getText().toString();
					double rateDouble = Double.parseDouble(rateString);
					
					if(rateDouble<=0){
					Toast.makeText(getApplicationContext(), "Input the CorrectNumber~", Toast.LENGTH_LONG).show();
					otherField.setText("");return;
					}
					calculatedValue = insertedValue*(rateDouble/100);
					resultField.setText(Double.toString(calculatedValue));
				}
				else{
					Toast.makeText(getApplicationContext(), "Click the Button~", Toast.LENGTH_LONG).show();
				}
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
