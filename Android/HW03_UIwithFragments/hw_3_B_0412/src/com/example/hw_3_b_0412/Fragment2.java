package com.example.hw_3_b_0412;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.view.Display;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class Fragment2 extends Fragment implements OnClickListener {
	Button emailButton;
	Button callButton;
	Button smsButton;
	Button showlistButton;
	
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		return inflater.inflate(R.layout.fragment2, container, false);
	}
	
	public void onStart(){
		super.onStart();
		emailButton = (Button)getActivity().findViewById(R.id.emailButton);
		callButton = (Button)getActivity().findViewById(R.id.callButton);
		smsButton = (Button)getActivity().findViewById(R.id.smsButton);
		showlistButton = (Button)getActivity().findViewById(R.id.showListButton);
		
		emailButton.setOnClickListener(this);
		callButton.setOnClickListener(this);
		smsButton.setOnClickListener(this);
		showlistButton.setOnClickListener(this);
		
		
	}
	public void onClick(View v){
		if(v.getId()==emailButton.getId()){
			TextView emailField = (TextView)getActivity().findViewById(R.id.emailField);
			
			Intent intent = new Intent(android.content.Intent.ACTION_SENDTO,Uri.parse("mailto:"+emailField.getText().toString()));
			startActivity(intent);
		}
		else if(v.getId()==callButton.getId()){
			TextView phoneField = (TextView)getActivity().findViewById(R.id.phoneField);
			
			Intent intent = new Intent(android.content.Intent.ACTION_CALL,Uri.parse("tel:"+phoneField.getText().toString()));
			startActivity(intent);
		}
		else if(v.getId()==smsButton.getId()){
			TextView phoneField = (TextView)getActivity().findViewById(R.id.phoneField);
			
			Intent intent = new Intent(android.content.Intent.ACTION_SENDTO,Uri.parse("smsto:"+phoneField.getText().toString()));
			startActivity(intent);
		}
		else if(v.getId()==showlistButton.getId()){
			WindowManager wm = getActivity().getWindowManager();
			Display d = wm.getDefaultDisplay();
			
			if(d.getWidth() < d.getHeight()){
				FragmentManager fm = getActivity().getSupportFragmentManager();
				FragmentTransaction ft = fm.beginTransaction();
				
				//세로화면의 경우 showList버튼을 눌렀을 때 다시 리스트를 보여주는 과정입니다 
				ft.hide((Fragment2)fm.getFragments().get(1));
				ft.show((Fragment1)fm.getFragments().get(0));
				ft.commit();
			}
			else{
				Toast.makeText(getActivity(), "Only hightlength mode~", Toast.LENGTH_SHORT).show();
			}
		}
	}
}
