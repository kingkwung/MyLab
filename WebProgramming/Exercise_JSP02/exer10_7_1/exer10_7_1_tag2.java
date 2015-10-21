package pack_10_7;

import java.io.IOException;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.SimpleTag;
import javax.servlet.jsp.tagext.SimpleTagSupport;

public class exer10_7_1_tag2 extends SimpleTagSupport implements SimpleTag{
	int limit=0;
	public int getLimit() {
		return limit;
	}
	public void setLimit(int limit) {
		this.limit = limit;
	}
	@Override
	public void doTag() throws JspException, IOException{
		double randNum = Math.random() * limit;
		JspWriter out = getJspContext().getOut();
		
		out.print("<h2>random number(0 ~ "+limit+") : "+ randNum +"</h2>");
	}
}