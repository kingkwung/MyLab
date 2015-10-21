package com.example.hw_2_a_0321;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	Button up;
	Button down;
	EditText field;
	String set_text;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		//각 버튼과 뷰들에 대해 아이디를 등록하는 과정입니다 
		up = (Button)findViewById(R.id.upButton);
		down = (Button)findViewById(R.id.downButton);
		field = (EditText)findViewById(R.id.textfield);
		
		//up버튼에 대한 onclick listener등록 
		up.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				int value;
				try{
					//string을 입력했을 때에 대한 예외처리입니다 
					value = Integer.parseInt(field.getText().toString());
				}
				catch(NumberFormatException e){
					Toast.makeText(getApplicationContext(), "Not a Integer~", Toast.LENGTH_LONG).show();
					field.setText("0");
					return;
				}
				value++;
				set_text = Integer.toString(value);
				field.setText(set_text);
				Toast.makeText(getApplicationContext(), "+1~", Toast.LENGTH_LONG).show();
			}
		});
		
		//down버튼에 대한 onclick listener등록 
		down.setOnClickListener(new OnClickListener(){
			public void onClick(View v){
				int value;
				try{
				value=Integer.parseInt(field.getText().toString());
				}
				catch(NumberFormatException e){
					Toast.makeText(getApplicationContext(), "Not a Integer~", Toast.LENGTH_LONG).show();
					field.setText("0");
					return;
				}
				value--;
				set_text = Integer.toString(value);
				field.setText(set_text);
				Toast.makeText(getApplicationContext(), "-1~", Toast.LENGTH_LONG).show();
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
