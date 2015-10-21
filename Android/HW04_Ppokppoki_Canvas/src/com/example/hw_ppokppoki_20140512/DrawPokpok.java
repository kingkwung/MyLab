package com.example.hw_ppokppoki_20140512;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.Display;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.Toast;

public class DrawPokpok extends View{
	private Paint mPaint;
	
	private Bitmap originPok;
	private Bitmap popPok;
	
	private Context c;
	
	int WidthSize=6;
	int HeightSize=9;
	
	//뾱뾱이가 현재 터진상태인지 아닌지 체크하는 행렬입니다 
	boolean[][] bubbles = new boolean[WidthSize][HeightSize];

	//전체스크린사이즈입니다 
	int screenWidth=0;
	int screenHeight=0;
	
	//방울한개의 유닛 길이입니다 
	int unitWidth=0;
	int unitHeight=0;
	
	
	public void init(){
		mPaint = new Paint();
		
		Resources res = getResources();
		originPok = BitmapFactory.decodeResource(res, R.drawable.bubbles);
		popPok = BitmapFactory.decodeResource(res, R.drawable.bubbles2);
		
		//뾱뾱이상태체크 이차행렬 초기화 
		for(int i=0; i<WidthSize; i++){
			for(int j=0; j<HeightSize; j++){
				bubbles[i][j] = true;
			}
		}
		
	}
	
	public DrawPokpok(Context c){
		super(c);
		init();
	}
	public DrawPokpok(Context c, AttributeSet a){
		super(c,a);
		this.c = c;
		init();
	}
	
	public boolean onTouchEvent(MotionEvent event){
		
		//이벤트가 발생하면 좌표를 가져옵니다 
		float eventX = event.getX();
		float eventY = event.getY();
		
		//뾱뾱이를 체크할 위치를 담는 변수들 
		int left=0; int top=0; int right=unitWidth; int bottom=unitHeight;

		if(event.getAction() == MotionEvent.ACTION_DOWN){
			for(int i=0; i<WidthSize; i++){
				for(int j=0; j<HeightSize; j++){
					
					//눌린 좌표가 방울 범위안에 있다면 그 것을 false로 바꾸어 줍니다 
					if((left<=eventX && eventX<=right)&&(top<=eventY && eventY<=bottom)){
						bubbles[i][j]=false;
					}
					top += unitHeight;
					bottom += unitHeight;
				}
				left += unitWidth;
				right += unitWidth;
				top = 0;
				bottom = unitHeight;
			}

			//다시그리기 
			invalidate();
		}
		return true;
	}
	
	protected void onDraw(Canvas canvas){

		Display display = ((WindowManager)c.getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
		//canvas.drawBitmap(originPok, 0, 0, mPaint);
		
		//각 정보들을 세팅해줍니다 
		screenWidth = display.getWidth();
		screenHeight = display.getHeight()-200;
		unitWidth = screenWidth/WidthSize;
		unitHeight = (int)screenHeight/HeightSize;
		
		
		int left=0; int top=0; int right=unitWidth; int bottom=unitHeight;

		//for loop 를 통해 방울 상태를 체크하며 상태에 맞게 그려줍니다 
		for(int i=0; i<WidthSize; i++){
			for(int j=0; j<HeightSize; j++){
				
				//만약 방울이 안터진 상태라면 originPok을 그립니다 
				if(bubbles[i][j]==true){
					canvas.drawBitmap(originPok,null,new Rect(left,top,right,bottom),null);
				}
				
				//만약 방울이 터진 상태라면 popPok을 그립니다 
				else if(bubbles[i][j]==false){
					canvas.drawBitmap(popPok,null,new Rect(left,top,right,bottom),null);
				}
				top += unitHeight;
				bottom += unitHeight;
			}
			left += unitWidth;
			right += unitWidth;
			top = 0;
			bottom = unitHeight;
		}
		
	}
}



