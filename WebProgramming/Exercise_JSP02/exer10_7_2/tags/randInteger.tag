<%@ tag language="java" pageEncoding="UTF-8"%>


<%@ attribute name = "limit" required="true"%>

<%
double randNum = Math.random() * Integer.parseInt(limit);
%>

<h2>random number(0 ~ <%=limit%>): <%=randNum%></h2>