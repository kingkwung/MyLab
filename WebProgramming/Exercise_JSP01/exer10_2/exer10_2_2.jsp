<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Exercise10_2_2</title>
</head>
<body>

	<H2>HTTP Request Headers</H2>
	<br>
	<%@ page import="java.util.Enumeration"%>
	<%@ page import="java.io.PrintWriter"%>
	<%@ page import="java.util.zip.GZIPOutputStream"%>
	<%!PrintWriter out2;%>
	<%!Enumeration<String> headerNames;%>

	<%=request.getMethod() + request.getRequestURI()
					+ request.getProtocol()%><br>
	<%
	out.clear();
	out = pageContext.pushBody();
		out2 = null;
		headerNames = request.getHeaderNames();
		while (headerNames.hasMoreElements()) {
			String name = (String) headerNames.nextElement();
			String cname = name.substring(0, 1).toUpperCase() + name.substring(1);
			
			String encodings = request.getHeader("Accept-Encoding");
			boolean gzipSupported = (encodings != null) && (encodings.contains("gzip"));
			String flag = request.getParameter("disableGzip");
			boolean gzipDisabled = (flag != null) && (!flag.equalsIgnoreCase("false"));
			
			if(gzipSupported && !gzipDisabled){
				out2 = new PrintWriter(new GZIPOutputStream(response.getOutputStream()), false);
			}
			else{
				out2 = response.getWriter();
			}

		}
	%>


</body>
</html>