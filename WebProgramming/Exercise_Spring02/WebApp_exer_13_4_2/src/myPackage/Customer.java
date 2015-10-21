package myPackage;

public class Customer {
	public String id, firstName, lastName;
	public double balance, balanceNo;
	
	public Customer(){
		id="";
		firstName="";
		lastName="";
		balance=0;
		balanceNo=0;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public double getBalance() {
		return balance;
	}

	public void setBalance(double balance) {
		this.balance = balance;
	}

	public double getBalanceNo() {
		return balanceNo;
	}

	public void setBalanceNo(double balanceNo) {
		this.balanceNo = balanceNo;
	}
	
	
}
