package com.example.quiz0410youngnam;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener {

	Button s_number;
	Button nameButton;
	Button launch;
	TextView p_number;
	TextView s_provide;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		s_number=(Button)findViewById(R.id.studentnumber);
		nameButton = (Button)findViewById(R.id.name);
		launch = (Button)findViewById(R.id.LaunchActivity);
		p_number=(TextView)findViewById(R.id.tel_num);
		s_provide=(TextView)findViewById(R.id.service_provide);
		
		s_number.setOnClickListener(this);
		nameButton.setOnClickListener(this);
		launch.setOnClickListener(this);
		
	}

	public void onClick(View v){
		if(v.getId() == s_number.getId()){
			Toast.makeText(this, s_number.getText().toString(), Toast.LENGTH_LONG).show();
		}
		else if(v.getId() == nameButton.getId()){
			Toast.makeText(this, nameButton.getText().toString(), Toast.LENGTH_LONG).show();
		}
		else if(v.getId() == launch.getId()){
			Intent myIntent = new Intent(MainActivity.this, youngnamsActivity.class);
			
			Bundle myData = new Bundle();
			myIntent.putExtras(myData);
			startActivityForResult(myIntent, 101);
		}
	}
	
	
	
	protected void onActivityResult(int requestCode, int resultCode, Intent data){
		super.onActivityResult(requestCode, resultCode, data);
		try{
			if((requestCode == 101) && resultCode == Activity.RESULT_OK){
				Bundle myResults = data.getExtras();
				
				p_number.setText(myResults.getString("p_number"));
				s_provide.setText(myResults.getString("tong"));
				//Double vresult = myResults.getDouble("vresult");
				//lblResult.setText("Sum is" + vresult);
			}
		}
		catch(Exception e){
			//lblResult.setText("Problems - " + requestCode + " " + resultCode);
		}
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
