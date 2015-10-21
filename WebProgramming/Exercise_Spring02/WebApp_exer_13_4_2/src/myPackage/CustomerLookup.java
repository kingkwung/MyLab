package myPackage;

import java.util.Map;

public class CustomerLookup {
	public Map<String,Customer> customers;

	public Customer findCustomer(String id){
		if(id!=null){
			return (customers.get(id.toLowerCase()));
		}
		return null;
	}
	public CustomerLookup(){
	}
	public CustomerLookup(Map<String,Customer> customers){
		this.customers=customers;
	}
	public Map<String, Customer> getcustomers() {
		return customers;
	}
	public void setcustomers(Map<String, Customer> customers) {
		this.customers = customers;
	}


}
