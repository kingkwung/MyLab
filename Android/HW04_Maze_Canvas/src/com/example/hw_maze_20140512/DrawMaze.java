package com.example.hw_maze_20140512;

import java.util.Random;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Style;
import android.graphics.Path;
import android.graphics.Point;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.Display;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.Toast;

public class DrawMaze extends View{
	
	private Path mPath;
	private Paint mPaint;
	
	Point mPoint;
	Paint blockPaint;
	
	private Bitmap startBitmap;
	private Bitmap finishBitmap;
	private Rect startRect;
	private Rect finishRect;
	
	private Context c;
	
	int WidthSize=6;
	int HeightSize=9;
	
	//뾱뾱이가 현재 터진상태인지 아닌지 체크하는 행렬입니다 
	boolean[][] blocks = new boolean[HeightSize][WidthSize];
	//현재 = false : 갈수있는 길 / true : 갈수없는 길  
	
	private Rect[][] rect_info = new Rect[HeightSize][WidthSize];

	
	//전체스크린사이즈입니다 
	int screenWidth=0;
	int screenHeight=0;
	
	//미로 한칸 유닛 길이입니다 
	int unitWidth=0;
	int unitHeight=0;
	
	
	boolean isStart=true;
	
	
	public DrawMaze(Context c){
		super(c);
		init();
	}
	public DrawMaze(Context c, AttributeSet a){
		super(c, a);
		this.c = c;
		init();
	}
	
	public void init(){//초기화 하는 부분입니다 
		
		Resources res = getResources();
		startBitmap = BitmapFactory.decodeResource(res, R.drawable.ball);
		finishBitmap = BitmapFactory.decodeResource(res, R.drawable.jordan);
		
		mPath = new Path();
		mPaint = new Paint();
		mPaint.setDither(true);
		mPaint.setColor(Color.BLUE);
		mPaint.setStyle(Paint.Style.STROKE);
		mPaint.setStrokeJoin(Paint.Join.ROUND);
		mPaint.setStrokeCap(Paint.Cap.ROUND);
		mPaint.setStrokeWidth(5);
		
		mPoint = new Point();
		
		//미로 단위 크기 이차행렬 초기화 
		for(int i=0; i<HeightSize; i++){
			for(int j=0; j<WidthSize; j++){
				blocks[i][j] = true;
			}
		}
		
		
		
		/*랜덤으로 미로를 만드는 로직입니다 
		*/
		
		Random ran = new Random();
		
		
		int count_x_forward;
		int count_y_forward;
		
		boolean decide_x_y;
		
		count_x_forward = WidthSize-1;
		count_y_forward = HeightSize-1;
		
		int i=0;
		int j=0;
		
		blocks[i][j]=false;

		
		while(true){
			
			decide_x_y = ran.nextBoolean();
			
			if(decide_x_y==true && count_x_forward!=0){ // x를 1중가하는 경우~! 
				blocks[i][++j]=false;
				count_x_forward--;
			}
			else if(decide_x_y==false && count_y_forward!=0){ // y를 1중가하는 경우~! 
				blocks[++i][j]=false;
				count_y_forward--;
			}
			
			if(count_x_forward==0 && count_y_forward==0){
				Toast.makeText(getContext(), "[new maze created]", Toast.LENGTH_SHORT).show();
				break;
			}
		}
		
		int ran_y_line;
		for(i=0; i<2; i++){
			ran_y_line = ran.nextInt(3)+2;
			
			for(j=0; j<4; j++){
				blocks[ran_y_line][j]=false;
			}
		}
		
		int ran_x_line;
		ran_x_line = ran.nextInt(3)+2;
		for(i=0; i<HeightSize; i++){
			blocks[i][ran_x_line] = false;
		}
		
		/*
		for(int m=0; m<200; m++){
			decide_x_y = ran.nextBoolean();
			
			if(decide_x_y==true){ // x좌표를 가지고 놀겠다 하는 경우 
									
					decide_forward_back = ran.nextBoolean();
					if(decide_forward_back==true){ // x좌표를 "증가" 시키겠다 하는 경우 
						if(j+1>=WidthSize || count_x_forward<=0 || (i!=0&&blocks[i-1][j+1]==false) || (i!=HeightSize-1&&blocks[i+1][j+1]==false)||blocks[i][j+1]==false ||((j>=3)&&(count_y_forward!=0))){ // 왼쪽 끝 벽을 넘어가거나 오른쪽 끝 벽은 넘어가는 경우엔 다시 그리게한다! 
							continue;
						}
						else{ // 넘어가지 않으면~ 길을 뚫겠다~ 
							if(count_x_forward!=0){
							count_x_forward--;
							j++;
							blocks[i][j]=false;}
						}
					}
					else if(decide_forward_back==false){ // x좌표를 "감소" 시키겠다 하는 경우 
						if(j-1<=0 || count_x_back<=0||(i!=0&&blocks[i-1][j-1]==false) || (i!=HeightSize-1&&blocks[i+1][j-1]==false)||blocks[i][j-1]==false || ((j<=2)&&(count_y_back!=0)) ){ // 왼쪽 끝 벽을 넘어가거나 오른쪽 끝 벽은 넘어가는 경우엔 다시 그리게한다! 
							continue;
						}
						else{ // 넘어가지 않으면~ 길을 뚫겠다~ 
							if(count_x_back!=0){
							count_x_back--;
							j--;
							blocks[i][j]=false;}
						}
					}
				
			}
			else if(decide_x_y==false){ // y좌표를 가지고 놀겠다 하는 경우 
				
				decide_forward_back = ran.nextBoolean();
				if(decide_forward_back==false){ // y좌표를 "증가" 시키겠다 하는 경우 
					if(i+1>=HeightSize || count_y_forward<=0 || (j!=0&&blocks[i+1][j-1]==false) || (j!=WidthSize-1&&blocks[i+1][j+1]==false)||blocks[i+1][j]==false || ((i>=6)&&(count_x_forward!=0))){ // 왼쪽 끝 벽을 넘어가거나 오른쪽 끝 벽은 넘어가는 경우엔 다시 그리게한다! 
						
						continue;
					}
					else{ // 넘어가지 않으면~ 길을 뚫겠다~ 
						if(count_y_forward!=0){
						count_y_forward--;
						i++;
						blocks[i][j]=false;}
					}
				}
				else{ // y좌표를 "감소" 시키겠다 하는 경우 
					if(i-1<=0 || count_y_back<= 0 || (j!=0&&blocks[i-1][j-1]==false) || (j!=WidthSize-1&&blocks[i-1][j+1]==false)||blocks[i-1][j]==false ||((i<=2)&&(count_x_back!=0)) ){ // 왼쪽 끝 벽을 넘어가거나 오른쪽 끝 벽은 넘어가는 경우엔 다시 그리게한다! 
						
						continue;
					}
					else{ // 넘어가지 않으면~ 길을 뚫겠다~ 
						if(count_y_back!=0){
						count_y_back--;
						i--;
						blocks[i][j]=false;}
					}
				}
			}
			if(count_x_forward==0 && count_x_back==0 && count_y_forward==0 && count_y_back==0){
				break;
			}
		}
		*/
		
//		//이건 그냥 테스트 
//		blocks[0][0]=false;
//		blocks[0][1]=false;
//		blocks[0][2]=false;
//		blocks[0][3]=false;
//		blocks[1][3]=false;
//		blocks[2][3]=false;
//		blocks[3][3]=false;
//		blocks[3][4]=false;
//		blocks[4][4]=false;
//		blocks[5][4]=false;
//		blocks[5][3]=false;
//		blocks[5][2]=false;
//		blocks[6][2]=false;
//		blocks[7][2]=false;
//		blocks[7][3]=false;
//		blocks[7][4]=false;
//		blocks[7][5]=false;
//		blocks[8][5]=false;

	}
	
	public void onDraw(Canvas canvas){
		
		blockPaint = new Paint();
		
		Display display = ((WindowManager)c.getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
		//canvas.drawBitmap(originPok, 0, 0, mPaint);
		
		//각 정보들을 세팅해줍니다 
		screenWidth = display.getWidth();
		screenHeight = display.getHeight()-200;
		unitWidth = screenWidth/WidthSize;
		unitHeight = (int)screenHeight/HeightSize;
		
		int left=0; int top=0; int right=unitWidth; int bottom=unitHeight;

		
		//for loop 를 통해 블럭의 상태를 체크하며 상태에 맞게 그려줍니다 
		for(int i=0; i<HeightSize; i++){
			for(int j=0; j<WidthSize; j++){
				
				//길인 경우 
				if(blocks[i][j]==false){
					blockPaint.setColor(Color.WHITE);
					blockPaint.setStyle(Style.STROKE);
					
					
					if(i==0 && j==0){
						startRect = new Rect(left,top,right,bottom);
						canvas.drawBitmap(startBitmap,null,startRect,null);
					}
					else if(i==HeightSize-1 && j==WidthSize-1){
						finishRect = new Rect(left,top,right,bottom);
						canvas.drawBitmap(finishBitmap,null,finishRect,null);
					}
					else{
						canvas.drawRect(left,top,right,bottom, blockPaint);
					}
				}
				
				//길이 아닌경우 
				else if(blocks[i][j]==true){
					blockPaint.setColor(Color.BLACK);
					blockPaint.setStyle(Style.FILL);
					//blockPaint.setStyle(Style.STROKE);
					//blockPaint.setStrokeWidth(1);
					rect_info[i][j] = new Rect(left,top,right,bottom);
					canvas.drawRect(left,top,right,bottom, blockPaint);
				}
				left += unitWidth;
				right += unitWidth;
				
			}
			left = 0;
			right = unitWidth;
			
			top += unitHeight;
			bottom += unitHeight;
			
		}
		
		canvas.drawPath(mPath, mPaint);
		

	}
	
	public boolean onTouchEvent(MotionEvent event){
		int eventX = (int)event.getX();
		int eventY = (int)event.getY();
		boolean temp_check=false;
		
		switch(event.getAction()){
		case MotionEvent.ACTION_DOWN:
			
			if(!startRect.contains(eventX, eventY)){//시작점에서 시작하지 않는 경우 아예 시작을 안하게 하는 조건문 
				mPath.reset();
				return false;
			}
			
			isStart = true;
			mPath.moveTo(eventX, eventY);
			break;
		case MotionEvent.ACTION_MOVE:
			
			if(isStart){
				if(finishRect.contains(eventX, eventY)){ // 도착지까지 잘 도착한 경우입니다 
					Toast.makeText(getContext(), "[SUCCESS~!]", Toast.LENGTH_SHORT).show();
					mPoint.x = 0;
					mPoint.y = 0;
					mPath.reset();
					isStart=false; // 도착지까지 도착했는데도 사용자가 손을 떼지 않고 짖궂게 계속 움직이는 경우 그것이 그려지는 것을 방지하는 변수입니다
					
					AlertDialog dialBox = createDialogBox();
					dialBox.show();
					
					
					break;
				}
				
				for(int i=0; i<HeightSize; i++){ // 가는중에 길이 아닌 곳으로 간다면 다시 시도하게 하는 과정입니다 
					for(int j=0; j<WidthSize; j++){
						if(blocks[i][j]==true){
							if(rect_info[i][j].contains(eventX, eventY)){
								Toast.makeText(getContext(), "[TRY AGAIN~!]", Toast.LENGTH_SHORT).show();
								mPoint.x = 0;
								mPoint.y = 0;
								mPath.reset();
								isStart = false;
								temp_check=true;
								break;
							}
						}
					}
				}
				
				if(temp_check){
					temp_check=false;
					break;
				}
				
				mPath.quadTo(mPoint.x, mPoint.y, eventX, eventY);
				break;
				
			}
		case MotionEvent.ACTION_UP:
			//mPath.lineTo(eventX, eventY);
			mPoint.x = 0;
			mPoint.y = 0;
			mPath.reset();
			break;
		}
		
		mPoint.x = (int)eventX;
		mPoint.y = (int)eventY;
		invalidate();
		return true;
	}
	
	private AlertDialog createDialogBox(){ // 다이얼로그를 만들어주는 부분입니다 다시 시작하는 경우 새로운 맵이 만들어지고, 새로시작하지 않는 경우 프로그램이 끝납니다 
		AlertDialog myDial = new AlertDialog.Builder(getContext()).setTitle("CHOICE").setMessage("Want new game?").setIcon(R.drawable.jordan).setPositiveButton("Yes", new DialogInterface.OnClickListener() {
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				init();
				invalidate();
			}
		}).setNegativeButton("NO", new DialogInterface.OnClickListener() {
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
		}).create();
		
		return myDial;
	}
}
