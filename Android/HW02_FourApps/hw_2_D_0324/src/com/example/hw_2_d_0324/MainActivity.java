package com.example.hw_2_d_0324;



import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener {

	EditText inputText;
	Button btn_7;
	Button btn_8;
	Button btn_9;
	Button btn_div;
	Button btn_4;
	Button btn_5;
	Button btn_6;
	Button btn_multi;
	Button btn_1;
	Button btn_2;
	Button btn_3;
	Button btn_min;
	Button btn_0;
	Button btn_cancle;
	Button btn_equal;
	Button btn_add;
	
	boolean check_reset;
	boolean check_sec_operand=false;
	String first="";
	String second="";
	String operator=""; 
	int result;
	boolean flag=true;
	
	
	String prev_operator="";
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		//각 뷰에 대한 아이디 지정해주는 과정입니다 
		inputText=(EditText)findViewById(R.id.inputField);
		btn_0=(Button)findViewById(R.id.btn_0);
		btn_1=(Button)findViewById(R.id.btn_1);
		btn_2=(Button)findViewById(R.id.btn_2);
		btn_3=(Button)findViewById(R.id.btn_3);
		btn_4=(Button)findViewById(R.id.btn_4);
		btn_5=(Button)findViewById(R.id.btn_5);
		btn_6=(Button)findViewById(R.id.btn_6);
		btn_7=(Button)findViewById(R.id.btn_7);
		btn_8=(Button)findViewById(R.id.btn_8);
		btn_9=(Button)findViewById(R.id.btn_9);
		btn_add=(Button)findViewById(R.id.btn_add);
		btn_min=(Button)findViewById(R.id.btn_min);
		btn_multi=(Button)findViewById(R.id.btn_multi);
		btn_div=(Button)findViewById(R.id.btn_div);
		btn_cancle=(Button)findViewById(R.id.btn_cancle);
		btn_equal=(Button)findViewById(R.id.btn_equal);
		
		btn_0.setOnClickListener(this);
		btn_1.setOnClickListener(this);
		btn_2.setOnClickListener(this);
		btn_3.setOnClickListener(this);
		btn_4.setOnClickListener(this);
		btn_5.setOnClickListener(this);
		btn_6.setOnClickListener(this);
		btn_7.setOnClickListener(this);
		btn_8.setOnClickListener(this);
		btn_9.setOnClickListener(this);
		btn_add.setOnClickListener(this);
		btn_min.setOnClickListener(this);
		btn_multi.setOnClickListener(this);
		btn_div.setOnClickListener(this);
		btn_cancle.setOnClickListener(this);
		btn_equal.setOnClickListener(this);
	}
	

	//클릭 이벤트가 발생했을 때 들어오는 메서드 입니다 
	public void onClick(View v){
		if(v.getId()==btn_0.getId()){
			this.textField("0", false);
		}
		else if(v.getId()==btn_1.getId()){
			this.textField("1", false);
		}
		else if(v.getId()==btn_2.getId()){
			this.textField("2", false);
		}
		else if(v.getId()==btn_3.getId()){
			this.textField("3", false);
		}
		else if(v.getId()==btn_4.getId()){
			this.textField("4", false);
		}
		else if(v.getId()==btn_5.getId()){
			this.textField("5", false);
		}
		else if(v.getId()==btn_6.getId()){
			this.textField("6", false);
		}
		else if(v.getId()==btn_7.getId()){
			this.textField("7", false);
		}
		else if(v.getId()==btn_8.getId()){
			this.textField("8", false);
		}
		else if(v.getId()==btn_9.getId()){
			this.textField("9", false);
		}
		
		else if(v.getId()==btn_add.getId()){
			this.textField("+", true);
		}
		else if(v.getId()==btn_min.getId()){
			this.textField("-", true);
		}
		else if(v.getId()==btn_multi.getId()){
			this.textField("*", true);
		}
		else if(v.getId()==btn_div.getId()){
			this.textField("/", true);
		}
		else if(v.getId()==btn_equal.getId()){
			this.textField("=", true);
		}
		else if(v.getId()==btn_cancle.getId()){
			this.textField("c", true);
		}
	}    
	
	//실질적인 계산을 하는 부분입니다 
	public void textField (String str, boolean check_reset){
    	
    	if(str.equals("c")){ // reset에 대한 것 구현 
    		first="";
    		second="";
    		operator="";
    		check_sec_operand=false;
    		Toast.makeText(this,"*RESET*",Toast.LENGTH_SHORT).show();
    		inputText.setText("0");
    		return;
    	}
    	//=을 누른 경우입니다 
    	if(first.length()!=0 && second.length()!=0 && str.equals("=")){
    		inputText.setText(first);
    		
    		if(operator.equals("+")){
    			result=(Integer.parseInt(first) + Integer.parseInt(second));
    		}
    		else if(operator.equals("-")){
    			result=(Integer.parseInt(first) - Integer.parseInt(second));
    		}
    		else if(operator.equals("*")){
    			result=(Integer.parseInt(first) * Integer.parseInt(second));
    		}
    		else if(operator.equals("/")){
    			if(second.equals("0")){
    				Toast.makeText(this,"*CAN'T DIV BY ZERO",Toast.LENGTH_SHORT).show();
    				first="";
    	    		second="";
    	    		operator="";
    	    		check_sec_operand=false;
    	    		inputText.setText("");
    				return;
    			}
    			result=(Integer.parseInt(first) / Integer.parseInt(second));
    		}
    		
    		first=String.valueOf(result);
    		check_sec_operand=false;
    		return;
    	}
    	
    	//연산자를 누른 경우입니다 
    	if(check_reset){
    		check_sec_operand=true;
    		operator=str;
    		inputText.setText(first);
    		flag=true;
    	}

    	//계산을 하는 부분입니다 
    	else{

    		if((inputText.length()==1&&inputText.getText().toString().equals("0"))||inputText.getText().toString().equals("+")||inputText.getText().toString().equals("-")||inputText.getText().toString().equals("*")||inputText.getText().toString().equals("/")||inputText.getText().toString().equals("=")){
    			inputText.setText("");
    		}
    		
    		if(check_sec_operand==false){
        		inputText.setText(inputText.getText().toString()+str);

    			first=inputText.getText().toString();

    		}
    		else{
    			if(flag){
    			inputText.setText("");flag=false;}
    			inputText.setText(inputText.getText().toString()+str);
    			second=inputText.getText().toString();
    			int temp_result=0;
    			if(operator.equals("+")){
        			temp_result=(Integer.parseInt(first) + Integer.parseInt(second));
        			first=Integer.toString(temp_result);
        		}
        		else if(operator.equals("-")){
        			temp_result=(Integer.parseInt(first) - Integer.parseInt(second));
        			first=Integer.toString(temp_result);
        		}
        		else if(operator.equals("*")){
        			temp_result=(Integer.parseInt(first) * Integer.parseInt(second));
        			first=Integer.toString(temp_result);
        		}
        		else if(operator.equals("/")){
        			if(second.equals("0")){
        				Toast.makeText(this,"*CAN'T DIV BY ZERO",Toast.LENGTH_SHORT).show();
        				first="";
        	    		second="";
        	    		operator="";
        	    		check_sec_operand=false;
        	    		inputText.setText("");
        				return;
        			}
        			temp_result=(Integer.parseInt(first) / Integer.parseInt(second));
        			first=Integer.toString(temp_result);
        		}
    		}
    	}
    	
    }

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
