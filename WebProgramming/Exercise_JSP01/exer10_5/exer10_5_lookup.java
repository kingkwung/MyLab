package pack_exer10_5;

import java.util.Map;
import java.util.TreeMap;

public class exer10_5_lookup {
	private Map<String, String> matching;

	public exer10_5_lookup(){
		matching = new TreeMap<String,String>(String.CASE_INSENSITIVE_ORDER);

		//init
		matching.put("oregon","OR");
		matching.put("pennsylvania","PA");
		matching.put("rhode Island", "RI");
		matching.put("south Carolina", "SC");
		matching.put("south Dakota", "SD");
		matching.put("tennesse", "TN");
		matching.put("texas", "TX");
		matching.put("utah","UT");
		matching.put("vermont","VT");
		matching.put("virginia","VA");
		matching.put("washington","WA");
		matching.put("west Virginia","WV");
		matching.put("wisconsin", "WI");
		matching.put("washington dc", "DC");
		matching.put("alabama","AL");
		matching.put("alaska","AK");
		matching.put("arizona","AZ");
		matching.put("arkansas","AR");
		matching.put("california","CA");
		matching.put("colorado","CO");
		matching.put("connecticut","CT");
		matching.put("delaware","DE");
		matching.put("florida","FL");
		matching.put("georgia","GA");
		matching.put("hawaii","HI");
		matching.put("idaho","ID");
		matching.put("ilinois","IL");
		matching.put("indiana","IN");
		matching.put("iowa","IA");
		matching.put("kansas","KS");
		matching.put("kentucky","KY");
		matching.put("louisiana","LA");
		matching.put("maine","ME");
		matching.put("maryland","MD");
		matching.put("massachusetts","MA");
		matching.put("michigan","MI");
		matching.put("minnesota","MN");
		matching.put("wyoming", "WY");
		matching.put("mississippi","MS");
		matching.put("missouri","MO");
		matching.put("montana","MT");
		matching.put("nebraska","NE");
		matching.put("nevada","NV");
		matching.put("new Hampshire","NH");
		matching.put("new Jersey","NJ");
		matching.put("new Mexico","NM");
		matching.put("new York","NY");
		matching.put("north Carolina", "NC");
		matching.put("north Dakota","ND");
		matching.put("ohio","OH");
		matching.put("oklahoma","OK");
	}

	public String findAbbrev(String fullName){
		if(fullName!=null){
			return matching.get(fullName);}
		else{
			return null;
		}
	}
}
