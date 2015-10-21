package pack_10_7;

import java.io.IOException;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.SimpleTag;
import javax.servlet.jsp.tagext.SimpleTagSupport;

public class exer10_7_1_tag1 extends SimpleTagSupport implements SimpleTag{
	@Override
	public void doTag() throws JspException, IOException{
		double randNum = Math.random();
		JspWriter out = getJspContext().getOut();
		
		out.print("<h2>random number : " + randNum+ "</h2>");
	}
}
