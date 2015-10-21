package com.example.hw_3_a_0412;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class Fragment2 extends Fragment{
	
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
	
	
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		return inflater.inflate(R.layout.fragment2, container, false);
	}
	public void onStart(){
		super.onStart();
		
		//뷰들을 할당해주는 과정입니다 
		resultButton = (Button)getActivity().findViewById(R.id.resultButton);
		price = (EditText)getActivity().findViewById(R.id.priceField);
		radioGroup = (RadioGroup)getActivity().findViewById(R.id.RadioGroup);
		radio1 = (RadioButton)getActivity().findViewById(R.id.fiftyButton);
		radio2 = (RadioButton)getActivity().findViewById(R.id.twentyButton);
		radio3 = (RadioButton)getActivity().findViewById(R.id.otherButton);
		otherField = (EditText)getActivity().findViewById(R.id.otherField);
		resultField = (TextView)getActivity().findViewById(R.id.resultField);
		
		
		int button_check = radioGroup.getCheckedRadioButtonId();
		
		resultButton.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				
				try{
					insertedValue = Double.parseDouble(price.getText().toString());
					if(insertedValue<=0){
						Toast.makeText(getActivity(), "Input the CorrectNumber~", Toast.LENGTH_LONG).show();
						price.setText("");return;
					}
				}
				catch(NumberFormatException e){
					Toast.makeText(getActivity(), "Not number~", Toast.LENGTH_LONG).show();
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
					Toast.makeText(getActivity(), "Input the CorrectNumber~", Toast.LENGTH_LONG).show();
					otherField.setText("");return;
					}
					calculatedValue = insertedValue*(rateDouble/100);
					resultField.setText(Double.toString(calculatedValue));
				}
				else{
					Toast.makeText(getActivity(), "Click the Button~", Toast.LENGTH_LONG).show();
				}
				

				
			}
		});
	}
}