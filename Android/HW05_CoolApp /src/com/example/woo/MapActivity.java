
package com.example.woo;

import android.content.Intent;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import com.google.android.gms.common.GooglePlayServicesUtil;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.GoogleMap.OnMapClickListener;
import com.google.android.gms.maps.GoogleMap.OnMarkerClickListener;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;

public class MapActivity extends FragmentActivity {

	GoogleMap mGoogleMap;

	float[]	lat;
	float[]	lng;

	int count=0;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_main);

		Intent intent=getIntent();
		count=intent.getExtras().getInt("COUNT");
		
		
		lat=new float[count];
		lng=new float[count];
		for(int i=0;i<count;i++){
			lat[i]=intent.getExtras().getFloat("LAT"+i);
			lng[i]=intent.getExtras().getFloat("LNG"+i);
		}

		init();

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	private void init() {

		Intent getI = getIntent();

		String title = getI.getStringExtra("title");


		LatLng position = new LatLng(lat[0], lng[0]);
		
		GooglePlayServicesUtil.isGooglePlayServicesAvailable(MapActivity.this);

		mGoogleMap = ((SupportMapFragment) getSupportFragmentManager()
				.findFragmentById(R.id.map)).getMap();


		mGoogleMap.moveCamera(CameraUpdateFactory.newLatLngZoom(position, 15));
		
		String temp="";
		for(int i=0;i<count;i++){
			position = new LatLng(lat[i], lng[i]);
			temp+="count : "+i;
			temp+=" lat : "+lat[i];
			temp+=" lng : "+lng[i]+"\n";
		
			mGoogleMap.addMarker(
					new MarkerOptions().position(position).title(i+" "))
					.showInfoWindow();
		}
	}
}
