

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class exer03_1106
 */
@WebServlet("/exer03_1106")
public class exer03_1106 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public exer03_1106() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String search_val = request.getParameter("searchkey");
		String search_engine = request.getParameter("searchengine");
		
		
		//response.setContentType("text/html");
		PrintWriter out = response.getWriter();


		if(search_val==null){
			out.println(
					"<!DOCTYPE html>\n" +
							"<html>\n" +
							"<head><title>Exercise 9.3</title></head>\n" +
							"<body align='center' ><H2>Search Front-end</H2>" + 
							"<FORM ACTION='http://localhost:8080/myServlet/exer03_1106'>" + 
							"<p>Choose a search engine and enter query keyworks</p>" + 
							"<TABLE border='0' align='center'>" + 
							"<TR><TD>" + 
							"<select name='searchengine'><option value='naver'>Naver</option><option value='google'>Google</option><option value='daum'>Daum</option><option value='yahoo'>Yahoo</option><option value='bing'>Bing</option></select></TD><TD><INPUT TYPE='TEXT' name='searchkey'></TD></TR>" + 
							"</TABLE><br>" + 
							"<INPUT TYPE='SUBMIT' VALUE='Search'>" +
							"</FORM>"+
							"</body></html>"
					);
		}


		if(search_engine!=null){
			if(search_engine.equalsIgnoreCase("naver")){
				response.sendRedirect("http://search.naver.com/search.naver?query="+search_val);
			}
			else if(search_engine.equalsIgnoreCase("google")){
				response.sendRedirect("http://www.google.com/search?q="+search_val);

			}
			else if(search_engine.equalsIgnoreCase("daum")){
				response.sendRedirect("http://search.daum.net/"+search_val);

			}
			else if(search_engine.equalsIgnoreCase("yahoo")){
				response.sendRedirect("http://search.yahoo.com/bin/search?p="+search_val);

			}
			else if(search_engine.equalsIgnoreCase("bing")){
				response.sendRedirect("http://www.bing.com/search?q="+search_val);

			}
			else {
				
			}
		}


	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

}
