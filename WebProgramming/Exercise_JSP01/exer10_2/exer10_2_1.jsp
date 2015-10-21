<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Exercise10_2_1</title>
</head>
<body>

	<H2>HTTP Request Headers</H2>
	<br>
	<%@ page import="java.util.Enumeration"%>
	<%!Enumeration<String> headerNames;%>

	<%=request.getMethod() + request.getRequestURI()
					+ request.getProtocol()%><br>
	<%
		headerNames = request.getHeaderNames();
		while (headerNames.hasMoreElements()) {
			String name = (String) headerNames.nextElement();
			String cname = name.substring(0, 1).toUpperCase()
					+ name.substring(1);
	%>

	<font style='color: red'><%=cname%> : </font><%=request.getHeader(name)%><br>

	<%
		}
	%>


</body>
</html>




