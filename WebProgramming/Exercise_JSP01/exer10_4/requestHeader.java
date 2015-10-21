package pack_exer10_4;

import java.util.ArrayList;

public class requestHeader {
	private String headerName;
	private String headerValue;
	private String allList="";
	
	public requestHeader(){
		
	}
	
	public void setHeaderName(String headerName){
		this.headerName = headerName;
		allList+="<tr><td>"+headerName + "</td>";
	}
	public String getHeaderName(){
		return headerName;
	}
	public void setHeaderValue(String headerValue){
		this.headerValue = headerValue;
		allList+="<td>"+headerValue+"</td></tr>";
	}
	public String getHeaderValue(){
		return headerValue;
	}
	public void setAllList(String allList){
		this.allList = allList;
	}
	public String getAllList(){
		return allList;
	}
//	public void addData(){
//		allList+=headerName + " : " + headerValue + "<br>";
//	}
}
