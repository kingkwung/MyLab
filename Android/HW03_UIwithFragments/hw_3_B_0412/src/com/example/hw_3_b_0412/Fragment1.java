package com.example.hw_3_b_0412;

import java.util.ArrayList;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.view.Display;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class Fragment1 extends Fragment {

	ListView list;
	TextView nameField;
	TextView emailField;
	TextView phoneField;
	TextView descriptField;

	ArrayList<person> person_list = new ArrayList<person>();
	ArrayAdapter<String> adapter;

	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		return inflater.inflate(R.layout.fragment1, container, false);
	}

	public void onStart(){
		super.onStart();

		//뷰들을 할당해주는 과정입니다 
		list = (ListView)getActivity().findViewById(R.id.listView);
		nameField = (TextView)getActivity().findViewById(R.id.nameField);
		emailField = (TextView)getActivity().findViewById(R.id.emailField);
		phoneField = (TextView)getActivity().findViewById(R.id.phoneField);
		descriptField = (TextView)getActivity().findViewById(R.id.descriptionField);

		//사람을 만들어주는 과정입니다 
		person_list.add(new person("아이언맨","tony@naver.com","01050146434","잘날라다님"));
		person_list.add(new person("헐크","hulk@naver.com","01022228888","초파워맨"));
		person_list.add(new person("로저스","captain@naver.com","01033339999","오래살음"));
		person_list.add(new person("토르","thor@naver.com","01055551234","못을 잘 박음"));

		//name_list 어레이에 이름들을 저장해주는 과정입니다
		String[] name_list = new String[person_list.size()];
		for(int i=0; i<person_list.size(); i++){
			name_list[i] = person_list.get(i).getName();
		}

		//리스트를 구성하는 과정입니다 
		adapter = new ArrayAdapter<String>(getActivity(), android.R.layout.simple_list_item_1, name_list);
		list.setAdapter(adapter);
		
		
		//setOnItemClickListener를 구현하는 과정입니다 
		list.setOnItemClickListener(new OnItemClickListener(){
			public void onItemClick(AdapterView<?> av, View v, int position, long id){
				person p = person_list.get(position);
				nameField.setText(p.getName());
				emailField.setText(p.getEmail());
				phoneField.setText(p.getPhonenumber());
				descriptField.setText(p.getDescription());
				
				WindowManager wm = getActivity().getWindowManager();
				Display d = wm.getDefaultDisplay();
				
				if(d.getWidth() < d.getHeight()){
					FragmentManager fm = getActivity().getSupportFragmentManager();
					FragmentTransaction ft = fm.beginTransaction();
					
					//이름클릭시 Fragment1은 숨기고 Fragment2만 화면에 보여주는 과정 
					ft.hide((Fragment1)fm.getFragments().get(0));
					ft.show((Fragment2)fm.getFragments().get(1));
					ft.commit();
				}
			}
		});
	}
}
