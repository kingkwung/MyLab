
package com.example.woo;


import java.util.ArrayList;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.util.Log;
import android.widget.Toast;

public class SMSReceiver extends BroadcastReceiver{

	String phonenum="";
	String content="";
	double lat;
	double lng;
	Context c;

	//????????? ????????? ???????????? ????????? ???????????? ?????? ???????????????. 
	
	
	public void onReceive(Context context,Intent intent){
		c=context;

		Bundle bundle = intent.getExtras();
		SmsMessage[] msgs = null;
		String str = "";
		if (bundle != null)
		{
			//---retrieve the SMS message received---
			Object[] pdus = (Object[]) bundle.get("pdus"); 
			msgs = new SmsMessage[pdus.length];
			for (int i=0; i<msgs.length; i++){
				msgs[i] = SmsMessage.createFromPdu((byte[])pdus[i]);
				phonenum += msgs[i].getOriginatingAddress(); 
				content += msgs[i].getMessageBody().toString();
			}
			
			//?????? ????????? ????????? ???????????????. 
			
			if(content.contains("REQUEST")){
				content=content.substring(7).trim();
				
				SharedPreferences pref=context.getSharedPreferences("PASSWORD",Context.MODE_PRIVATE);

				String password=pref.getString("PASSWORD", "FAIL");
				
				String[] temp=content.split(",");
				int intervar=Integer.parseInt(temp[0]);
			
				String pwd=temp[1];
				
				if(pwd.equals(password)){
					//TODO:SEND find location
					Toast.makeText(c, "SEND LOCATION", Toast.LENGTH_LONG).show();
					Intent findLocation=new Intent(c,location.class);
					findLocation.putExtra("PHONENUM", phonenum.toString());
					findLocation.putExtra("INTERVAR", intervar);
					c.startService(findLocation);
					
				}else{
					Toast.makeText(c, "FIND LOCATION FAIL",Toast.LENGTH_LONG).show();
				}	
			}else if(content.contains("LOCATION")){
				//????????? ???????????? ????????? ??????????????? ?????????. 
				content=content.substring(8).trim();
				String[] temp=content.split(",");
				int count=Integer.parseInt(temp[0]);

				SharedPreferences pref=c.getSharedPreferences("LOCATION",Context.MODE_PRIVATE);		
				
				
				if(count==1){
					//initiate the all data
					for(int i=0;i<10;i++){
						pref=c.getSharedPreferences("LOCATION",Context.MODE_PRIVATE);		
						SharedPreferences.Editor editor=pref.edit();
						editor.putFloat("LAT"+i, 0);		
						editor.putFloat("LNG"+i, 0);		
						editor.commit();
					}		
					Toast.makeText(c,"ACCEPT DATA \n START TRACE", Toast.LENGTH_LONG).show();
				}
				pref=c.getSharedPreferences("LOCATION",Context.MODE_PRIVATE);		
				SharedPreferences.Editor editor=pref.edit();
				editor.putFloat("LAT"+(count-1), Float.parseFloat(temp[1]));		
				editor.putFloat("LNG"+(count-1), Float.parseFloat(temp[2]));		

				editor.commit();
				
				
				Intent map=new Intent(c,MapActivity.class);
				map.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK); 

				map.putExtra("COUNT", count);
				for(int i=0;i<count;i++){
					map.putExtra("LAT"+i, pref.getFloat("LAT"+i, 0));
					map.putExtra("LNG"+i, pref.getFloat("LNG"+i, 0));
				}
				c.startActivity(map);
			}

			//---display the new SMS message---
		}

	}

}



