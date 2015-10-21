
package com.example.woo;




import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener {

	
	Button message;
	Button set;
	EditText setPassword;
	EditText phonenum;
	EditText sendPassword;
	EditText intervar;
	
	
	//????????? ?????? ?????????. 
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		//?????? ?????? ?????? ?????????. ???????????? ????????? ??????????????????. 
		
		if(v.getId()==R.id.send){
			String intervarTemp;
			
			if(intervar.getText()==null||intervar.getText().toString().equals("")){
				intervarTemp="300";
			}else {
				intervarTemp=intervar.getText().toString();
			}
			
			SmsManager sms=SmsManager.getDefault();
			sms.sendTextMessage(phonenum.getText().toString(), null,"REQUEST "+intervarTemp+","+sendPassword.getText().toString(),null,null);
	
		}else if(v.getId()==R.id.settingpassword){
			
			if(setPassword.getText()==null||setPassword.getText().toString().equals("")){
				Toast.makeText(this, "EMPTY", Toast.LENGTH_LONG).show();
				return; 
			}
			
			SharedPreferences pref=getSharedPreferences("PASSWORD",MODE_PRIVATE);
			
			
			SharedPreferences.Editor editor=pref.edit();
			editor.putString("PASSWORD", setPassword.getText().toString());
			
			editor.commit();
			
			Toast.makeText(this, "설정 되었습니다.   " +pref.getString("PASSWORD", "1111"), Toast.LENGTH_LONG).show();
			
		}
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		
		super.onCreate(savedInstanceState);
		setContentView(R.layout.layout);
		
		message=(Button)findViewById(R.id.send);
		phonenum=(EditText)findViewById(R.id.phonenumber);
		sendPassword=(EditText)findViewById(R.id.password);
		intervar=(EditText)findViewById(R.id.interval);
		
		set=(Button)findViewById(R.id.settingpassword);
		setPassword=(EditText)findViewById(R.id.setpwdEdit);
		
		message.setOnClickListener(this);
		set.setOnClickListener(this);
		
		
	}

}






