package com.example.hw_3_b_0412;

public class person {
	String name="";
	String email="";
	String phoneNumber="";
	String description="";
	
	public person(String name, String email, String phoneNumber, String description){
		this.name = name;
		this.email = email;
		this.phoneNumber = phoneNumber;
		this.description = description;
	}
	
	public void setName(String name){
		this.name = name;
	}
	
	public void setEmail(String email){
		this.email = email;
	}
	
	public void setPhone(String phone){
		this.phoneNumber = phone;
	}
	
	public void setDescription(String description){
		this.description = description;
	}
	
	public String getName(){
		return this.name;
	}
	
	public String getEmail(){
		return this.email;
	}
	
	public String getPhonenumber(){
		return this.phoneNumber;
	}
	
	public String getDescription(){
		return this.description;
	}
}
