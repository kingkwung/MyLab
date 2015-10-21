package com.example.hw_3_a_0412;

import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.view.Display;
import android.view.Menu;
import android.view.WindowManager;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends FragmentActivity {

	LinearLayout linear;
	LinearLayout linearFrag1;
	LinearLayout linearFrag2;
	
	TextView resultField;
	String result;
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		//뷰들을 할당해주는 과정입니다 
		linear = (LinearLayout)findViewById(R.id.linear);
		linearFrag1 = (LinearLayout)findViewById(R.id.linearFrag1);
		linearFrag2 = (LinearLayout)findViewById(R.id.linearFrag2);
		resultField = (TextView)findViewById(R.id.resultField);
		
		WindowManager wm = getWindowManager();
		Display d = wm.getDefaultDisplay();
		
		//화면을 가로로 눞혔을 때의 과정입니다 
		if(d.getWidth() > d.getHeight()){
			linear.setOrientation(LinearLayout.HORIZONTAL);
			LinearLayout.LayoutParams param1 = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.MATCH_PARENT, 2);
			LinearLayout.LayoutParams param2 = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.MATCH_PARENT, 1);
			
			linearFrag1.setLayoutParams(param1);
			linearFrag2.setLayoutParams(param2);
			
		}
	}
	
	//화면에 있는 값을 저장해 놓습니다 
	public void onSaveInstanceState(Bundle outState){
		super.onSaveInstanceState(outState);
		result = resultField.getText().toString();
		outState.putString("RESULT", result);
	}
	
	//저장해놓은 값을 다시 resultField에 출력해줍니다 
	protected void onRestoreInstanceState(Bundle savedInstanceState){
		super.onRestoreInstanceState(savedInstanceState);
		result = savedInstanceState.getString("RESULT");
		if(result == null){
			return;
		}
		else{
			resultField.setText(result);
		}
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
