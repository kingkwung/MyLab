<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Exercise10_4</title>
</head>
<body>

	<H2>HTTP Request Headers</H2>

	<jsp:useBean id="requestHeader" class="pack_exer10_4.requestHeader" scope="application"/>
	<%@ page import="java.util.Enumeration"%>



	<br>
	<table border='1'>
		<%!Enumeration<String> headerNames;%>

		<%=request.getMethod() + request.getRequestURI()
					+ request.getProtocol()%>
		<%
			headerNames = request.getHeaderNames();
			while (headerNames.hasMoreElements()) {
				String name = (String) headerNames.nextElement();
				String cname = name.substring(0, 1).toUpperCase()
						+ name.substring(1);
		%>

		<jsp:setProperty name="requestHeader" property="headerName"
			value="<%=cname%>" />
		<jsp:setProperty name="requestHeader" property="headerValue"
			value="<%=request.getHeader(name)%>" />


		<%
			}
		%>
		<jsp:getProperty name="requestHeader" property="allList" />
	</table>
</body>
</html>