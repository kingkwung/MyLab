package pack_10_6;

public class exer10_6_2_bean {
	private String headerName;
	private String headerValue;
	private String allList="";
	
	public exer10_6_2_bean(){
		
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
}
